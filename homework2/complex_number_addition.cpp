#include <iomanip>
#include <iostream>
using namespace std;

int main(){
    float a, b, c, d;
    cin >> a >> b >> c >> d;
    a = a - c;
    b = b - d;
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    cout << a << ' ' << b << setprecision(2);
}
