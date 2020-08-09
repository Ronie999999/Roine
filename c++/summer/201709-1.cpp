#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"
#include "iomanip"

int main(){
    int num, total, five, three;
    std::cin >> num;
    num /= 10;
    five = (num / 5) * 2;
    three = (num % 5) / 3;
    total = num + five + three;
    std::cout << total << std::endl;
    return 0;
}
