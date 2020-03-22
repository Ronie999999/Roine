#include  <iostream>
#include  <cmath>
using  namespace  std;
int isPrime(unsigned short a){
    for (int i = 2; i < int(sqrt(a)) + 1; ++i) {
        if (a % i == 0) return 0;
    }
    return 1;
}

int  main()
{
    unsigned  short  a;
    cin>>a;
    if  (isPrime(a))
        cout<<"Y"<<endl;
    else
        cout<<"N"<<endl;
}