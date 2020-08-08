#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"

int main(){
    int num, weight, count = 0, total = 0;
    std::cin >> num;
    std::cin >> weight;
    std::vector<int> list;
    for (int i = 0; i < num; ++i) {
        int temp;
        std::cin >> temp;
        list.push_back(temp);
    }
    for (int j = 0; j < num; ++j) {
        total += list[j];
        if (total >= weight) {
            count++;
            total = 0;
        }
        else if (j == num - 1) count++;
    }
    std::cout << count << std::endl;
    return 0;
}
