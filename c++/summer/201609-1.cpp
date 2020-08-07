#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"

int main(){
    int num, max;
    std::cin >> num;
    std::vector<int> list;
    for (int i = 0; i < num; ++i) {
        int temp;
        std::cin >> temp;
        list.push_back(temp);
    }
    max = abs(list[0] - list[1]);
    for (int j = 0; j < num - 1; ++j) {
        if (abs(list[j] - list[j + 1]) > max) max = abs(list[j] - list[j + 1]);
    }
    std::cout << max << std::endl;
    return 0;
}
