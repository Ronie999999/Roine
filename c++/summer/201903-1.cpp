#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"
#include "iomanip"

int main(){
    int num;
    std::cin >> num;
    std::vector<int> list;
    for (int i = 0; i < num; ++i) {
        int temp;
        std::cin >> temp;
        list.push_back(temp);
    }
    double double_mid = 0; int int_mid = 0;
    int max = *std::max_element(list.begin(), list.end());
    int min = *std::min_element(list.begin(), list.end());
    if (list.size() % 2 == 0){
        if ((list[list.size()/2 - 1] + list[list.size()/2]) % 2 == 0) int_mid = (list[list.size()/2 - 1] + list[list.size()/2]) / 2;
        else double_mid = (list[list.size()/2 - 1] + list[list.size()/2]) / 2.0;
    } else int_mid = list[list.size()/2];
    std::cout << max << " ";
    if (double_mid) {
        std::cout << std::fixed;
        std::cout << std::setprecision(1) << double_mid << " ";
    }
    else std::cout << int_mid << " ";
    std::cout << min;
    return 0;
}
