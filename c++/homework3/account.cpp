#include  <iostream>
#include  <iomanip>
using  namespace  std;
//请在此处补充Account类的定义
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
        cout << "您输入的金额不合法" << endl;
        money = 0;
    } else money = imoney;
}

void Account::withdraw(double num) {
    if (check(num) == 0) cout << "您输入的金额不合法" << endl;
    else if (money < num) cout << "您的存款金额不足" << endl;
    else{
        money -= num;
    }
}

void Account::deposit(double num) {
    if (check(num) == 0) cout << "您输入的金额不合法" << endl;
    else{
        money += num;
    }
}

void Account::printmoney() {
    cout<<fixed<<setprecision(2);
    cout << name << "的存款为" <<money << endl;
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
    tom.init("32020320011001876X", "Tom  Black", "男", 19, 2000.89);
    tom.printmoney();//输出：Tom  Black的存款为2000.89
    tom.deposit(89.471);//输出：您输入的金额不合法
    tom.printmoney();//输出：Tom  Black的存款为2000.89
    tom.deposit(10000);
    tom.printmoney();//输出：Tom  Black的存款为12000.89
    tom.withdraw(10001);
    tom.printmoney();//输出：Tom  Black的存款为1999.89
    tom.withdraw(10000.123);//输出：您输入的金额不合法
    tom.printmoney();//输出：Tom  Black的存款为1999.89
    tom.withdraw(10000.9);//输出：您的存款金额不足
    tom.printmoney();//输出：Tom  Black的存款为1999.89
    Account  jerry;
    jerry.init("320203200910116569", "Jerry  Black", "女", 11, 100.956);//输出：您输入的金额不合法
    jerry.printmoney();//输出：Jerry  Black的存款为0.00
}