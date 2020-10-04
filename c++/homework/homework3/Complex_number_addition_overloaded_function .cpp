#include  <iostream>
#include  <iomanip>
using  namespace  std;

struct  complex
{
    double  r;
    double  i;
};

complex add(complex a, complex b){
    complex sum;
    sum.r = a.r + b.r;
    sum.i = a.i + b.i;
    return sum;
}
complex add(complex a, double num){
    complex sum;
    sum.r = a.r + num;
    sum.i = a.i;
    return  sum;
}
complex add(double num, complex b){
    complex sum;
    sum.r = num + b.r;
    sum.i = b.i;
    return sum;
}

int  main()
{
    double  num;
    complex  a,  b,  c;
    cin  >>  a.r  >>  a.i;
    cin  >>  b.r  >>  b.i;
    cin  >>  num;
    c  =  add(a,  b);
    cout  <<  c.r  <<  "+"  <<  c.i  <<  "i"  <<  endl;
    c  =  add(a,  num);
    cout  <<  c.r  <<  "+"  <<  c.i  <<  "i"  <<  endl;
    c  =  add(num,  b);
    cout  <<  c.r  <<  "+"  <<  c.i  <<  "i"  <<  endl;
}