#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
bool checkYear(int year){
    if (year % 400 == 0) return true;
    return year % 4 == 0 and year % 100 != 0;
}
int main(){
    int year, days, month = 0;
    bool y;
    std::cin >> year >> days;
    int list_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    y = checkYear(year);
    if (y) list_of_month[1] = 29;
    for (int i = 0; i < 12; ++i) {
        if (days > list_of_month[i]) {
            days -= list_of_month[i];
        } else{
            month = i + 1;
            break;
        }
    }
    std::cout << month << std::endl;
    std::cout << days << std::endl;
    return 0;
}