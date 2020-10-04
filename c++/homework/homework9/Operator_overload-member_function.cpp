#include  <iostream>
using  namespace  std;

class Complex{
public:
    Complex(float a = 0, float b = 0){
        real_part = a;
        imaginary_part = b;
    }

    Complex operator +(const Complex& other){
        Complex temp;
        temp.real_part = this->real_part + other.real_part;
        temp.imaginary_part = this->imaginary_part + other.imaginary_part;
        return temp;
    }
    Complex operator -(const Complex& other) {
        Complex temp;
        temp.real_part = this->real_part - other.real_part;
        temp.imaginary_part = this->imaginary_part - other.imaginary_part;
        return temp;
    }
    void print(){
        cout << real_part << "+" << imaginary_part << "i" << endl;
    }
private:
    float real_part;
    float imaginary_part;
};


int  main()
{
    Complex  a(3,4),b(1,-1),c;
    c=a+b;
    cout<<"a+b=";
    c.print();
    cout<<endl;
    c=a-b;
    cout<<"a-b=";
    c.print();
    cout<<endl;
    c=a+100;
    cout<<"a+100=";
    c.print();
    cout<<endl;
    c=a-2.5;
    cout<<"a-2.5=";
    c.print();
    cout<<endl;

    return  0;
}