#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>


int main(){
    int num, total = 0;
    std::cin >> num;
    std::vector<int> list;
    for (int i = 0; i < num; ++i) {
        int temp;
        std::cin >> temp;
        list.push_back(temp);
    }
    for (int j = 1; j < num - 1; ++j) {
        if ((list[j] > list[j - 1] and list[j] > list[j + 1]) or (list[j] < list[j - 1] and list[j] < list[j + 1])){
            total++;
        }
    }
    std::cout << total << std::endl;
    return 0;
}