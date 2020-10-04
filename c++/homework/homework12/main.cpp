#include <iostream>
using namespace std;

template <typename T>
class Array
{
//请完成类的设计
public:
    Array(unsigned int n){
        max = n;
        p = new T[max];
    };
    void input(unsigned int n){
        if (n>max) exit(1);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
//        for (int j = 0; j < n; ++j) {
//            cout << p[j] << endl;
//        }
    }
    T& operator[](int i){
        if( i > max){
            cout << "索引超过最大值" <<endl;
            exit(1);
        }
        return p[i];
    }

private:
    int max;
    T *p;
};

class Fract
{
//请完成类的设计
    friend ostream & operator<<(ostream &out, Fract &obj);
    friend istream & operator >> (istream &in, Fract &obj);
public:
    Fract(int x, int y){
        a = x; b = y;
    }
    Fract(){
        a = 0; b = 0;
    }

    void operator +=(Fract fr){
        this->a = this->a * fr.b + this->b * fr.a;
        this->b = this->b * fr.b;
        if(b<0){
            a=-a;
            b=-b;
        }
        if(a==0){
            b=1;
        }else{
            int i;
            for(i=a;i>=1;i--)
            {
                if((a%i==0)&&(b%i==0))
                {
                    a=a/i;
                    b=b/i;
                }
            }
        }
    }
    void show(){
        if (a == 0) cout << a << endl;
        else if (b == 1) cout << a << endl;
        else
            cout << a << "/" << b << endl;
    }

private:
    long long int a;
    long long int b;
};
ostream & operator<<(ostream &out, Fract &obj){
    out << obj.a << " " << obj.b;
    return out;
}
istream & operator>>(istream &in, Fract &obj){
    in >> obj.a>> obj.b;
    return in;
}

int main()
{
    unsigned int n;
    cin >> n;
    Array<double> db(n);
    db.input(n);
    double dbsum(0.0);
    for (unsigned int i = 0; i < n; i++)
        dbsum += db[i];
    cout << dbsum << endl;

    cin >> n;
    Array<Fract> fr(n);
    fr.input(n);
    Fract frsum(0, 1);
    for (unsigned int i = 0; i < n; i++)
        frsum += fr[i];
    frsum.show();
}
