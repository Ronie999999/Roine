//#include  <iostream>
//using  namespace  std;
////请在这里补充类Boat和Car的定义
//class Car;
//class Boat{
//public:
//    Boat(int weight);
//    friend int totalweight(Boat &b, Car &c);
//private:
//    int weight;
//
//};
//
//Boat::Boat(int weight) {
//    this->weight = weight;
//}
//
//
//class Car{
//private:
//    int weight;
//public:
//    Car(int weight);
//    friend int totalweight(Boat &b, Car &c);
//};
//
//Car::Car(int weight) {
//    this->weight = weight;
//}
//
//int totalweight(Boat& b,Car& c)
//{
//    return  b.weight + c.weight;
//}
//
//
//int  main()
//{
//    Boat  b(100);
//    Car  c(200);
//    cout<<totalweight(  b,  c)<<endl;
//    return  0;
//}
#include <iostream>
using namespace std;
class CPoint{
public:
    CPoint(int x , int y);
    CPoint();
    CPoint(CPoint const &A);
    int get_x(){ return x;};
    int get_y(){ return y;}
//    CPoint(CPoint const &A, CPoint const &B);

private:
    int x, y;
};

CPoint::CPoint(int x, int y){
    this->x = x;
    this->y = y;
    cout << "CPoint contstructor with default value(0,0) is called." << endl;
}

CPoint::CPoint(){
    x = 0;
    y = 0;
    cout << "CPoint contstructor with default value(0,0) is called." << endl;
}

CPoint::CPoint(CPoint const &A) {
    x = A.x;
//    cout << "CPoint copy contstructor is called." << endl;
    y = A.y;
    cout << "CPoint copy contstructor is called." << endl;
}

//CPoint::CPoint(CPoint const &A, CPoint const &B) {
//
//}

class CRectangle{
public:
    CRectangle();
    CRectangle(CPoint const A, CPoint const B);
    CRectangle(int A, int B, int C,int D);
    CRectangle(CRectangle const &A);
    int GetArea();

private:
    CPoint a,b;
};

CRectangle::CRectangle(){
    cout << "CRectangle default contstructor is called." << endl;
}

CRectangle::CRectangle(CPoint const A, CPoint const B):a(A),b(B){

    cout << "CRectangle contstructor with (CPoint,CPoint) is called." << endl;
}

CRectangle::CRectangle(int A, int B, int C, int D):a(A,B),b(C,D){
    cout << "CRectangle contstructor with (int,int,int,int) is called." << endl;
}

CRectangle::CRectangle(CRectangle const &A):a(A.a),b(A.b) {
    cout << "CRectangle copy contstructor is called." << endl;
}

int CRectangle::GetArea(){
    return (a.get_x()-b.get_x())*(a.get_y()-b.get_y());
}


int main()
{
    int a=1, b=1, c=6, d=11;
    cout<<"# Define p1 ######"<<endl;
    CPoint p1;
    cout<<"# Define p2 ######"<<endl;
    CPoint p2(10,20);
    cout<<"# Define rect1 ######"<<endl;
    CRectangle rect1;
    cout<<"# Define rect2 ######"<<endl;
    CRectangle rect2(p1, p2);
    cout<<"# Define rect3 ######"<<endl;
    CRectangle rect3(a, b, c, d);
    cout<<"# Define rect4 ######"<<endl;
    CRectangle rect4(rect2);
    cout<<"# Calculate area ######"<<endl;
    cout << "rect1" << rect1.GetArea() << endl;
    cout << "rect2" << rect2.GetArea() << endl;
    cout << "rect3" << rect3.GetArea() << endl;
    cout << "rect4" << rect4.GetArea() << endl;
    system("pause");
    return 0;
}

#include <iostream>
#include <math.h>