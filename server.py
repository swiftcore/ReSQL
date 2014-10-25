# the rewrite sql compiler server end
import socket
from subprocess import *

HOST = ''
PORT = 9999
BUFSIZE=1024
ADDR = (HOST,PORT)

# call the resql compiler
# pass in the sql statement
# return the rewriting sql result
def rewrite_sql(sql):
    print 'In reswrite_sql: ',sql
    p1 = Popen(["echo",sql],stdout=PIPE)
    p2 = Popen(["./resql"],stdin=p1.stdout,stdout=PIPE)
    fout = p2.communicate()[0]
    if p2.returncode == 0:
        return fout
    else:
        return "can't rewrite"

# parse the create table statement
# and generation the schema file
# for the convince processing of the compiler writen in C.
def parse_query(query):
    table = []
    keys = []
    attrs = []
    
    # parse table name
    s = query.find('c')
    e = query.find('(')
    st = query[s:e]
    stab = st.split()
    table.append(stab[-1])

    s = e+1
    e = query.rfind(')');
    sat = query[s:e]
    sats = sat.split(',')
    for attab in sats:
        if attab.find("foreign") != -1:
            pass
        elif attab.find('primary') == -1:
            attrs.append((attab.split())[0])
        else:
            s = attab.find('(')
            e = attab.rfind(')')
            keys = attab[s+1:e].split(',')

    for i in range(len(keys)):
        keys[i] = keys[i].strip()

    for key in keys:
        attrs.remove(key)

    table.append(keys)
    table.append(attrs)

    return table

# read in the schema definations and
# pass each defination to the parse_query function
# get the parsed schema and write it into the schema.txt file
def extract_schema(schemadef):
    querys = schemadef.split(';')
    tables = []
    for query in querys:
        query = query.strip()
        if query != '':
            tables.append(parse_query(query))

    fout = open('schema.txt','w')
    fout.write(str(len(tables)) + '\n')
    for table in tables:
        fout.write(table[0]+'\n')
        fout.write(str(len(table[1]))+' ')
        fout.write(str(len(table[2]))+'\n')
        for key in table[1]:
            fout.write(key+'\n')
        for attr in table[2]:
            fout.write(attr+'\n')
        fout.write('\n')

# deal with the user requestion
def deal_with(conn,data):
    if not data.rstrip().endswith(';'):
        data = data + ';'

    if data.startswith("\""):
        data = data[1:]
            
    if data.endswith("\";"):
        data = data[:-2]
            
    if data.startswith('schema:'):
        print 'create schema with'
        create_sql = data.split(':')[1]
        print create_sql
        extract_schema(create_sql)
        conn.send('SCHEMA')
    elif data.startswith("sql:"):
        ts = data.split(':')[1]
        print 'try rewriting'
        print ts
        resql = rewrite_sql(ts)
        conn.send(resql)
    else:
        print 'wrong format'
        print data
        conn.send('WRONG')

if __name__ == '__main__':
    sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    sock.bind(ADDR)
    sock.listen(5)
    while True:
        print 'waiting... for connection...'
        connection,address = sock.accept()
        print '...connect from',address

        buf = connection.recv(1024)
        deal_with(connection,buf)
        connection.close()

    sock.close()

