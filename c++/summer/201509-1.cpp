#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>

int main(){
    int num, total = 0;
    std::vector<int> list;
    std::cin >> num;
    for (int i = 0; i < num; ++i) {
        int temp;
        std::cin >> temp;
        list.push_back(temp);
    }
    int number = list[0];
    for (int j = 0; j < num; ++j) {
        if (number != list[j]){
            number = list[j];
            total++;
        }
    }
    std::cout << total + 1 << std::endl;
    return 0;
}