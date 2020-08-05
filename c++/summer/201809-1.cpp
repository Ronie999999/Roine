#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>

int main(){
    int num;
    std::vector<int> list;
    std::vector<int> list2;
    std::cin >> num;
    for (int i = 0; i < num; ++i) {
        int temp;
        std::cin >> temp;
        list.push_back(temp);
    }
    list2.push_back((list[0] + list[1])/2);
    for (int j = 1; j < list.size() - 1; ++j) {
        list2.push_back((list[j - 1] + list[j] + list[j + 1])/3);
    }
    list2.push_back((list[list.size() - 1] + list[list.size() - 2]) / 2);
    for (int k = 0; k < list2.size(); ++k) {
        std::cout << list2[k] << " ";
    }
    return 0;
}