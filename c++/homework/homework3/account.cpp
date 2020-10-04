#include  <iostream>
#include  <iomanip>
using  namespace  std;
//���ڴ˴�����Account��Ķ���
class Account{
public:
    void init(string id, string name, string sex, int age, double money);
    void printmoney();
    void deposit(double num);
    void withdraw(double num);
    int check(double num);

private:
    string id;
    string name;
    string sex;
    int age;
    double money = 0;
};
void Account::init(string iid, string iname, string isex, int iage, double imoney) {
    id = iid;
    name = iname;
    sex = isex;
    age = iage;
    if (check(imoney) == 0) {
        cout << "������Ľ��Ϸ�" << endl;
        money = 0;
    } else money = imoney;
}

void Account::withdraw(double num) {
    if (check(num) == 0) cout << "������Ľ��Ϸ�" << endl;
    else if (money < num) cout << "���Ĵ�����" << endl;
    else{
        money -= num;
    }
}

void Account::deposit(double num) {
    if (check(num) == 0) cout << "������Ľ��Ϸ�" << endl;
    else{
        money += num;
    }
}

void Account::printmoney() {
    cout<<fixed<<setprecision(2);
    cout << name << "�Ĵ��Ϊ" <<money << endl;
}

int Account::check(double num) {
    unsigned n,temp=100;
    string a = to_string(num);
    for (unsigned int i = 0; i < a.length(); ++i) {
        if (a[i] == '.') temp = i;
        if (i > temp and a[i] == '0'){
            n = i - temp -1;
            if (n > 2) return 0;
            else
                return 1;
        }
    }
    return 1;

}

int  main()
{
    Account  tom;
    tom.init("32020320011001876X", "Tom  Black", "��", 19, 2000.89);
    tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89
    tom.deposit(89.471);//�����������Ľ��Ϸ�
    tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89
    tom.deposit(10000);
    tom.printmoney();//�����Tom  Black�Ĵ��Ϊ12000.89
    tom.withdraw(10001);
    tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89
    tom.withdraw(10000.123);//�����������Ľ��Ϸ�
    tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89
    tom.withdraw(10000.9);//��������Ĵ�����
    tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89
    Account  jerry;
    jerry.init("320203200910116569", "Jerry  Black", "Ů", 11, 100.956);//�����������Ľ��Ϸ�
    jerry.printmoney();//�����Jerry  Black�Ĵ��Ϊ0.00
}