#include  <iostream>
#include  <string>
using  namespace  std;

class  CStudent
{
public:
    void printname(){
        cout << "name:" << name << endl;
    };
    static int getcount();
    CStudent(string name, int age){
        this -> name = name;
        this -> age = age;
        count++;
        cout << name << " is contructing" << endl;
    };
    CStudent(){
        this -> name = "noname";
        this -> age = 0;
        count++;
        cout << "noname is contructing" << endl;
    };
    ~CStudent(){
        count--;
        cout << name << " is destructing" << endl;
    };
private:
    string name;
    int age;
    static int count;

};
//请在这里初始静态成员变量
int CStudent::count = 0;
int CStudent::getcount() {
    return count;
}

int  main()
{
    cout  <<  "stu"  <<  CStudent::getcount()  <<  endl;
    {
        CStudent  stuB[5];
        stuB[4].printname();
        cout  <<  "stu"  <<  CStudent::getcount()  <<  endl;
    }
    cout  <<  "stu"  <<  CStudent::getcount()  <<  endl;
    {
        CStudent  stuA[2]  =  {CStudent("Tom",  3),  CStudent("Jerry",  2)};
        for  (int  i  =  0;  i  <  2;  i++)
        {
            stuA[i].printname();
        }
        cout  <<  "stu"  <<  CStudent::getcount()  <<  endl;
    }
    cout  <<  "stu"  <<  CStudent::getcount()  <<  endl;

    return  0;
}