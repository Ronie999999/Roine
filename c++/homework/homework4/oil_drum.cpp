#include <iostream>
#include <iomanip>
using namespace std;
const double PI = 3.1415926;
class cylinder{
public:
    double getvolumn();
    double getarea();
    cylinder(double h, double r);
    ~cylinder();
private:
    double height;
    double  radius ;
};
cylinder::cylinder(double h, double r) {
    height = h;
    radius = r;
    cout << "构造函数被调用" <<endl;
}

double cylinder::getarea() {
    return 2 * PI * radius * radius + 2 * PI * radius * height;
}

double cylinder::getvolumn() {
    return PI * radius * radius * height;
}

cylinder::~cylinder() {
    cout << "析构函数被调用" << endl;
}

int main(){
    double d,h;
    cin>>d>>h;
    cylinder can(h,d/2);
    cout<<fixed<<setprecision(6);
    cout<<"油桶的容积是"<<can.getvolumn()<<" "<<endl;
    cout<<"铁皮的面积是"<<can.getarea()<<endl;

}