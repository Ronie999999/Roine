#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"
std::vector<int>::iterator max(std::vector<int> &list){
    auto maxPosition = max_element(list.begin(), list.end());
    return maxPosition;
}

std::vector<int>::iterator min(std::vector<int> &list){
    auto maxPosition = min_element(list.begin(), list.end());
    return maxPosition;
}

int main(){
    int num, mid;
    std::cin >> num;
    std::vector<int> list;
    std::vector<int> list2;
    for (int i = 0; i < num; ++i) {
        int temp;
        std::cin >> temp;
        list.push_back(temp);
    }
    list2 = list;
    for (int j = 0; j < num; ++j) {
        auto max_ = max(list);
        auto min_ = min(list);
        if (max_ == list.end() and min_ == list.end()) {
            std::cout << -1 << std::endl;
            exit(0);
        }
        else if (*max_ == *min_) {
            mid = *max_;
            break;
        }
        else if (*max_ != *min_) {
            list.erase(max(list));
            list.erase(min(list));
        }
    }
    int min_count = 0, max_count = 0;
    for (int k = 0; k < list2.size(); ++k) {
        if (mid > list2[k]) min_count++;
        if (mid < list2[k]) max_count++;
    }
    if (max_count == min_count) std::cout << mid <<std::endl;
    if (max_count != min_count) std::cout << -1 << std::endl;
    return 0;
}
