#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"
#include "iomanip"

int main(){
    int students, num;
    std::cin >> students >> num;
    std::vector<int> vec;
    std::vector<std::pair<int ,int>> list;
    for (int i = 0; i < num; ++i) {
        int a, b;
        std::cin >> a >> b;
        std::pair<int, int> pair(a, b);
        list.push_back(pair);
    }
    vec.reserve(students);
    for (int j = 0; j < students; ++j) {
        vec.push_back(j + 1);
    }
    for (int k = 0; k < num; ++k) {
        auto it =  std::find(vec.begin(), vec.end(), list[k].first);
        int xb = it - vec.begin();
        int temp = *it;
        vec.erase(it);
        vec.insert(vec.begin() + (xb + list[k].second), temp);
    }
    for (int l = 0; l < students; ++l) {
        std::cout << vec[l] << " ";
    }

    return 0;
}
