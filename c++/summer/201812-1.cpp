#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"
#include "iomanip"

int main(){
    int red, yellow, green, num, time = 0;
    std::cin >> red >> yellow >> green >> num;
    std::vector<std::pair<int ,int>> list;
    for (int i = 0; i < num; ++i) {
        int a, b;
        std::cin >> a >> b;
        std::pair<int, int> temp(a, b);
        list.push_back(temp);
    }
    for (int j = 0; j < num; ++j) {
        if (list[j].first == 0) time += list[j].second;
        else if (list[j].first == 1) time += list[j].second;
        else if (list[j].first == 2) time += (list[j].second + red);
    }
    std::cout << time << std::endl;
    return 0;
}

