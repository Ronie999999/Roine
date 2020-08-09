#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"
#include "iomanip"
int main(){
    int num, final;
    std::cin >> num;
    std::vector<int> list;
    for (int i = 0; i < num; ++i) {
        int temp;
        std::cin >> temp;
        list.push_back(temp);
    }
    final = abs(list[0] - list[1]);
    for (int j = 0; j < num - 1; ++j) {
        for (int i = j + 1; i < num; ++i) {
            if (final > abs(list[j] - list[i])) final = abs(list[j] - list[i]);
        }
    }
    std::cout << final << std::endl;
    return 0;
}