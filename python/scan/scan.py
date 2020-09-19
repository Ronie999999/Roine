import optparse
import sys
import socket
import threading


def scan(tgt_host, tgt_port, sem):
    sem.acquire()
    try:
        con = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        con.connect((tgt_host, tgt_port))
        con.send('hack'.encode())
        result = con.recv(100)
        msg = tgt_host + ' -> ' + str(tgt_port) + ' open' + '\t' + str(result.decode())
        print(msg)
        con.close()
    except Exception:
        print(tgt_host + ' -> ' + str(tgt_port) + ' close')
        pass
    sem.release()


def main(host, port_):
    temp = port_.split(',')
    port = []
    for i in range(int(temp[0]), int(temp[1])):
        port.append(i)
    host = socket.gethostbyname(host)
    sem = threading.Semaphore(12)
    for p in port:
        t = threading.Thread(target=scan, args=(host, p, sem))
        t.start()


if __name__ == '__main__':
    parse = optparse.OptionParser()
    parse.add_option('-u', '--host', type='string', dest='host', help='target host')
    parse.add_option('-p', '--port', type='string', dest='port', help='target port: -p start,end default="1,65432"', default='1,65432')
    options, args = parse.parse_args()
    if options.host is None:
        print(parse.format_help())
        sys.exit(1)
    # print(options)
    main(options.host, options.port)

