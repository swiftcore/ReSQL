#!/bin/env python
# the graphical interface of resql compiler client
import wx
import wx.grid
from subprocess import *
import sys

# call the client to connect to the server for rewriting the sql statement
def call_clnt(sql):
    try:
        # under windows
        # p1 = Popen(['echo',sql],stdout=PIPE,shell=True)
        # p2 = Popen(['python','clnt.py'],stdin=p1.stdout,stdout=PIPE,shell=True)
        p1 = Popen(['echo',sql],stdout=PIPE)
        p2 = Popen(['python','clnt.py'],stdin=p1.stdout,stdout=PIPE)
        fout,ferr = p2.communicate()
        return fout
    except OSError, e:
        pass

# define my application form
class MyApp(wx.App):
    def OnInit(self):
        frame = MyFrame("ReSQL Client v0.1",(50,60),(460,420))
        frame.Show()
        self.SetTopWindow(frame)
        return True

# define the output table of the query result
class MyTable(wx.grid.PyGridTableBase):
    def __init__(self):
        wx.grid.PyGridTableBase.__init__(self)
        self.data = {}
        self.odd = wx.grid.GridCellAttr()
        self.odd.SetBackgroundColour("white")
        self.even = wx.grid.GridCellAttr()
        self.even.SetBackgroundColour("wheat")
        self.rows = self.cols = 5

    def setData(self,data):
        self.data = data
        
    def GetNumberRows(self):
        return self.rows

    def GetNumberCols(self):
        return self.cols

    def SetNumberRows(self,rows):
        self.rows = rows

    def SetNumberCols(self,cols):
        self.cols = cols
        
    def IsEmptyCell(self,row,col):
        return self.data.get((row,col)) is None

    def GetValue(self,row,col):
        value = self.data.get((row,col))
        if value is not None:
            return value
        else:
            return ''

    def SetValue(self,row,col,value):
        self.data[(row,col)] = value

    def GetAttr(self,row,col,kind):
        attr = [self.even,self.odd][row % 2]
        attr.IncRef()
        return attr

# define the Frame with menus, buttons, output table in it.
class MyFrame(wx.Frame):
    def __init__(self,title,post,sizet):
        wx.Frame.__init__(self,None,-1,title, pos=post,size=sizet)
        menuFile = wx.Menu()
        menuFile.Append(1,"&About")
        menuFile.AppendSeparator()
        menuFile.Append(2,"E&xit")
        menuOutput = wx.Menu()
        menuOutput.Append(3,"Output rewiting")
        menuOutput.Append(4,"Output result")
        menuBar = wx.MenuBar()
        menuBar.Append(menuFile,"&File")
        menuBar.Append(menuOutput,"&Output")

        panel = wx.Panel(self,-1)
        self.schemaBtn = wx.Button(panel,-1,"S",pos=(20,0),size=(40,30))
        self.rewriteBtn = wx.Button(panel,-1,"R",pos=(70,0),size=(40,30))
        self.rewriteBtn.Disable()
        self.execBtn = wx.Button(panel,-1,"Exec",pos=(120,0),size=(40,30))
        self.execBtn.Disable()
        self.Bind(wx.EVT_BUTTON,self.OnSchemaClick,self.schemaBtn)
        self.Bind(wx.EVT_BUTTON,self.OnRewrite,self.rewriteBtn)
        self.Bind(wx.EVT_BUTTON,self.OnExecQuery,self.execBtn)

        self.text = wx.TextCtrl(panel,-1,"",size=(440,100),pos=(5,40),style=wx.TE_MULTILINE)

        from wx.grid import Grid
        self.grid = Grid(panel,pos=(5,140),size=(440,200))
        self.table = MyTable()
        self.grid.SetTable(self.table)
                
        self.SetMenuBar(menuBar)
        self.CreateStatusBar()
        self.SetStatusText("Welcome to ReSQL Client")
        self.Bind(wx.EVT_MENU,self.OnAbout,id=1)
        self.Bind(wx.EVT_MENU,self.OnQuit,id=2)
        self.Bind(wx.EVT_MENU,self.OnOutputRewriting,id=3)
        self.Bind(wx.EVT_MENU,self.OnOutputResult,id=4)

    def OnQuit(self,event):
        self.Close()

    def OnAbout(self,event):
        msg = "The Rewriting SQL client v0.1 !\n\nContact:wanghit2006@gmail.com"
        wx.MessageBox(msg,"About ReSQL client", wx.OK | wx.ICON_INFORMATION, self)

    def OnSchemaClick(self,event):
        schemaStr = 'schema: ' + self.text.GetValue().decode('utf-8').encode('ascii')
        back = call_clnt(schemaStr.replace('\n',' '))
        wx.MessageBox(back,"Schema",wx.OK | wx.ICON_INFORMATION,self)
        self.rewriteBtn.Enable()
        
    def OnRewrite(self,event):
        sql = "sql: " + self.text.GetValue().decode('utf-8').encode('ascii')
        self.resql = call_clnt(sql.replace('\n',' '))
        wx.MessageBox(self.resql,"Rewrite", wx.OK | wx.ICON_INFORMATION,self)
        self.execBtn.Enable()
        
    def OnExecQuery(self,event):        
        #rows,cols,data = self.execQuery(self.resql)
        #self.table.SetNumberRows(rows)
        #self.table.SetNumberCols(cols)
        #self.table.setData(data)
        #self.grid.SetTable(self.table)
        wx.MessageBox("Exec " + self.resql,"Rewrite", wx.OK | wx.ICON_INFORMATION,self)
        
    def OnOutputRewriting(self,event):
        msg = "output writing query"
        wx.MessageBox(msg,"Rewriting query",wx.OK | wx.ICON_INFORMATION,self)

    def OnOutputResult(self,event):
        rows,cols = self.table.GetNumberRows(),self.table.GetNumberCols()
        wd = []
        for i in range(rows):
            tmp = []
            for j in range(cols):
                tmp.append(self.table.data[(i,j)])
            wd.append(tmp)

        import csv
        writer = csv.writer(open('sample.csv','wb'))
        writer.writerows(wd)

        msg = "output query result"
        wx.MessageBox(msg,"Query result",wx.OK | wx.ICON_INFORMATION,self)
        
    def execQuery(self,sql):
        import pymssql
        cxn = pymssql.connect(password='61813744',host=r'.\SQLEXPRESS',database='hello')
        cur = cxn.cursor()
        cur.execute(sql)

        data = {}
        i = coln = 0
        for eachRow in cur.fetchall():
            coln = len(eachRow)
            for x in range(coln):
                data[(i,x)] = eachRow[x]
            i += 1

        cxn.commit()
        cxn.close()
        return cur.rownumber,coln,data
        
if __name__ == '__main__':
    app = MyApp(False)
    app.MainLoop()
