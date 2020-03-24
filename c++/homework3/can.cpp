#include  <iostream>
#include<iomanip>
#include  <cmath>
using  namespace  std;

const  double  PI=3.1415926;
//请在此处完善类的设计

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
    cout<<"油桶的容积是"<<can.getvolumn()<<"  "<<endl;
    cout<<"铁皮的面积是"<<can.getarea()<<endl;
}