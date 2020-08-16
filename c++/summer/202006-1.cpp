#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"
#include "iomanip"
#include <stack>

int main(){
    int n, m;
    std::cin >> n >> m;
    std::map<std::pair<int, int>, char> dot;
    std::vector<std::vector<int>> list;
    for (int i = 0; i < n; ++i) {
        int first, second;
        char c;
        std::cin >> first >> second >> c;
        std::pair<int, int> temp(first, second);
        dot[temp] = c;
    }
    for (int j = 0; j < m; ++j) {
        int a, b, c;
        std::cin >> a >> b >> c;
        std::vector<int> temp = {a, b, c};
        list.push_back(temp);
    }

    for (int k = 0; k < list.size(); ++k) {
        std::vector<char> a;
        std::vector<char> b;
        bool check = true;
        for (auto it = dot.begin(); it != dot.end(); it++) {
            int num = list[k][0] + list[k][1] * it->first.first + list[k][2] * it->first.second;
            if (num > 0) {
                a.push_back(it->second);
            }
            else{
                b.push_back(it->second);
            }
        }
        for (int i = 0; i < a.size() - 1; ++i) {
            if (a[i] != a[i + 1]){
                check = false;
                break;
            }
        }
        for (int j = 0; j < b.size() - 1; ++j){
            if (b[j] != b[j + 1]){
                check = false;
                break;
            }
        }
        if (check) std::cout << "Yes" << std::endl;
        else std::cout << "No" << std::endl;
    }
    return 0;
}