import zipfile
import optparse
import sys


def extractfile(file, password):
    try:
        file.extractall(pwd=password)
        print('password:', password.decode())
        sys.exit(0)
    except Exception:
        # print(password)
        pass


if __name__ == '__main__':
    parser = optparse.OptionParser()
    parser.add_option("-f", "--file", type="string", dest="file", help="file name")
    parser.add_option("-d", "--dic", type="string", dest="dic", help="dictionary ")
    parser.add_option("-w", "--password", type="string", dest="password", help="zipfile password")
    options, args = parser.parse_args()
    # print(options, args)
    if options.file is None and options.path is None:
        print(parser.format_help())

    zfile = zipfile.ZipFile(options.file)
    # print(options.file)
    pwdfile = open(options.dic, 'r')
    while True:
        pwd = pwdfile.readline().strip('\n')
        # print(pwd)
        if not pwd:
            break
        extractfile(zfile, pwd.encode())
    print('password not find')

