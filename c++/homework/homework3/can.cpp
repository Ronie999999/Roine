#include  <iostream>
#include<iomanip>
#include  <cmath>
using  namespace  std;

const  double  PI=3.1415926;
//���ڴ˴�����������

class cylinder{
public:
    double getvolumn();
    double getarea();
    void init(double h, double d);
private:
    double height;
    double  radius ;
};

void cylinder::init(double h,double d) {
    height = h;
    radius  = d;
 }

double cylinder::getarea() {
    return 2 * PI * radius * radius + 2 * PI * radius * height;
}

double cylinder::getvolumn() {
    return PI * radius * radius * height;
}

int  main()
{
    double  d,h;
    cin>>d>>h;
    cylinder can;
    can.init(h,d/2);
    cout<<fixed<<setprecision(6);
    cout<<"��Ͱ���ݻ���"<<can.getvolumn()<<"  "<<endl;
    cout<<"��Ƥ�������"<<can.getarea()<<endl;
}