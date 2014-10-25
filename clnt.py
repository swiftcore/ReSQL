# a client of the resql compiler in twisted

from twisted.internet import protocol,reactor

#HOST = '192.168.4.194'
HOST='localhost'
PORT = 9999

# define the protocol of request and response format
class TSClntProtocol(protocol.Protocol):
    def sendData(self):
        data = raw_input('')
        if data:
            self.transport.write(data)
        else:
            self.transport.loseConnection()

    def connectionMade(self):
        self.sendData()

    def dataReceived(self,data):
        print data
        self.transport.loseConnection()

# define the connection factory class
class TSClntFactory(protocol.ClientFactory):
    protocol = TSClntProtocol
    clientConnectionLost = clientConnectionFailed = \
        lambda self, connector, reason: reactor.stop()

if __name__ == '__main__':
    reactor.connectTCP(HOST,PORT,TSClntFactory())
    reactor.run()
