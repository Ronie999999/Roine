#include <iostream>
using namespace std;

int water(int bottle, int bottle_cap){
    int sum;
    sum = bottle / 2 + bottle_cap / 3;
    bottle = sum + bottle % 2;
    bottle_cap = sum + bottle_cap % 3;
    if(bottle <= 1 and bottle_cap <=2)
        return sum;
    return sum + water(bottle, bottle_cap);
}

int main(){
    int money, bottle_cap, bottle, sum;
    cin >> money;
    bottle = money; bottle_cap = money; sum = money;
    sum += water(bottle, bottle_cap);
    cout << sum;
}