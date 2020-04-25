import socket
port_start = int(input())
port_end = int(input())
host = input()
# for index in range(port_start, port_end + 1):


def scan(ip, port):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    result = sock.connect_ex((ip, port))
    if result == 0:
        print("Port %d is open" % port)
    else:
        print("Port %d is not open" % port)
    sock.close()


if __name__ == "__main__":
    for i in range(port_start, port_end):
        scan(host, i)
