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
    for (int j = 0; j < list.size(); ++j) {
        for (int i = j + 1; i < list.size(); ++i) {
            if (list[j] - 1 == list[i] or list[j] + 1 == list[i]) total += 1;
        }
    }
    std::cout << total << std::endl;
    return 0;
}