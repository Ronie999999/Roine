import socket
import threading

port_start = int(input("port_start:"))
port_end = int(input("port_end:"))
host = input("host")
port = []

for i in range(port_start, port_end):
    port.append(i)


class Scan:
    def __init__(self, ip, port_):
        self.ip = ip
        self.port = port_
        self.information = [False] * len(port_)

    def scan(self, ip, port_number):
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        result = sock.connect_ex((ip, port_number))
        if result == 0:
            self.information[port_number - port[0]] = True
        else:
            self.information[port_number - port[0]] = False
        sock.close()

    def __theard(self):
        print(socket.gethostbyname(host))
        theards = []
        for l in range(len(port)):
            t = threading.Thread(target=self.scan, args=(host, port[l]))
            theards.append(t)
        for k in range(len(theards)):
            theards[k].setDaemon(True)
            theards[k].start()
        for k in range(len(theards)):
            theards[k].join()

    def __print_information(self):
        for k in range(len(self.information)):
            if self.information[k]:
                print("port ", k + port[0], " is open")
            else:
                print("port ", k + port[0], " is not open")

    def start(self):
        self.__theard()
        self.__print_information()


a = Scan(host, port)
a.start()
