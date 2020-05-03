import string
import threading
import binascii
import sys


def crc(_crc):
    l = 1
    dic = string.printable
    _input = _crc
    _input = "0X" + _input
    for i in dic:
        for n in dic:
            for h in dic:
                for m in dic:
                    s = i + n + h + m
                    s = s.encode()
                    # print(str(binascii.crc32(s)), _input)
                    if hex(binascii.crc32(s)).upper() == _input.upper():
                        print(_crc, ':', s.decode())
                        print(l)
                        sys.exit()
                    l = l + 1


def crc32():
    print("四字节碰撞!!!")
    num = int(input("输入线程数："))
    _thread = []
    _args = []
    print("输入参数")
    for i in range(num):
        print(i+1, end=':')
        _args.append(input())
    # print(_args)
    for i in range(num):
        t = threading.Thread(target=crc, args=(_args[i],))
        _thread.append(t)
    for i in range(num):
        _thread[i].start()
    for i in range(num):
        _thread[i].join()
    input()


if __name__ == '__main__':
    crc32()
