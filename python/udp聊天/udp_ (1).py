import socket
import threading
import sys


def send(s):
    while True:
        data = input()
        if data == 'exit':
            sys.exit(0)
        s.sendto(data.encode('utf-8'), ('127.0.0.1', 8090))


def recv_(s):
    s.bind(("127.0.0.1", 8080))
    while True:
        data = s.recvfrom(1024)
        print("recive from " + str(data[1]) + "   data: " + data[0].decode())


def main():
    udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s = threading.Thread(target=send, args=(udp,))
    r = threading.Thread(target=recv_, args=(udp,))
    s.start()
    r.start()
    r.join()
    s.join()
    udp.close()


if __name__ == "__main__":
    main()
