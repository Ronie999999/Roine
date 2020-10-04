#include  <iostream>
#include  <cmath>
using  namespace  std;

//判断是否为素数
int  isPrime(long  num)
{
    for (int i = 2; i <= int(sqrt(num)); ++i) {
        if (num % i == 0) return 0;
    }
    return 1;
}

//计算质因素分解，
void factorization(long  n, long factor[], int &numoFactor)
{
    int l = 0;
    if (isPrime(n)){
        factor[0] = n;
        numoFactor = 1;
    }
    else{
        while (n != 1){
            for (int i = 2; i < n + 1; ++i) {
                if (n % i == 0){
                    factor[l] = i;
                    n = n / i;
                    l++; numoFactor++;
                    break;
                }
            }
        }
    }
}

int  main()
{
    long  n;
    long  factor[100];
    int  numofFactor  =  0;
    cin  >>  n;
    factorization(n,  factor, numofFactor);
    for  (int  i  =  0;  i  <  numofFactor;  i++)
    {
        cout  <<  factor[i]  <<  "  ";
    }
    cout  <<  endl;
    return  0;
}

