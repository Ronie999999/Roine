#include  <iostream>
#include<iomanip>
using  namespace  std;
void  swap1(float *a, float *b)
{
    float p;
    p = *a;
    *a = *b;
    *b = p;
}


void  swap2(float  &a,  float  &b)
{
    float i;
    i = a;
    a = b;
    b = i;

}


int  main()
{
    float  m,n;
    cin>>m>>n;
    swap1(&m,&n);
    cout<<fixed<<setprecision(2)<<m<<"  "<<n<<endl;
    swap2(m,n);
    cout<<fixed<<setprecision(2)<<m<<"  "<<n<<endl;
    cin>>m;
}
