#include  <iostream>
using  namespace  std;
class Complex{
public:
    Complex(float a = 0, float b = 0){
        real_part = a;
        imaginary_part = b;
    }
    friend Complex operator +(const Complex& other1, const Complex &other2);
    friend Complex operator -(const Complex& other1, const Complex& other2);
    void print(){
        cout << "(" << real_part << ")" <<"+" << "(" <<imaginary_part << "i" << ")" << endl;
    }

private:
    float imaginary_part;
    float real_part;
};



Complex operator-(const Complex &other1, const Complex &other2) {
    Complex temp;
    temp.real_part = other1.real_part - other2.real_part;
    temp.imaginary_part = other1.imaginary_part - other2.imaginary_part;
    return temp;
}

Complex operator+(const Complex &other1, const Complex &other2) {
    Complex temp;
    temp.real_part = other1.real_part + other2.real_part;
    temp.imaginary_part = other1.imaginary_part + other2.imaginary_part;
    return temp;
}



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
    c=100+a;
    cout<<"100+a=";
    c.print();
    cout<<endl;
    c=2.5-a;
    cout<<"2.5-a=";
    c.print();
    cout<<endl;
    return  0;
}