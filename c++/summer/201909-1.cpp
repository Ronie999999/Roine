#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"

int main(){
    int tree_number, time, pass_total = 0, total_apples = 0;
    std::cin >> tree_number >> time;
    std::vector<std::vector<int>> list;
    for (int i = 0; i < tree_number; ++i) {
        std::vector<int> temp;
        for (int j = 0; j < time + 1; ++j) {
            int t;
            std::cin >> t;
            temp.push_back(t);
        }
        list.push_back(temp);
    }
    std::vector<int> pass_each;
    for (int k = 0; k < list.size(); ++k) {
        int temp = 0;
        total_apples += list[k][0];
        for (int i = 1; i < list[k].size(); ++i) {
            temp += list[k][i];
        }
        pass_each.push_back(temp);
        pass_total += temp;
    }
    auto max = std::min_element(pass_each.begin(), pass_each.end());
    int max_e = 0;
    for (int l = 0; l < pass_each.size(); ++l) {
        if (*max == pass_each[l]) {
            max_e = l + 1;
            break;
        }
    }
    std::cout << total_apples + pass_total << " " << max_e << " " << abs(pass_each[max_e - 1]) << std::endl;
    return 0;
}
