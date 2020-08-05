#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>

int main(){
    int num, f = 0;
    std::cin >> num;
    std::vector<int> list;
    for (int i = 0; i < num; ++i) {
        int temp;
        std::cin >> temp;
        list.push_back(temp);
    }
    for (int j = 0; j < list.size(); ++j) {
        for (int i = j + 1; i < list.size(); ++i) {
            if (list[j] + list[i] == 0) f++;
        }
    }
    std::cout << f << std::endl;
    return 0;
}
