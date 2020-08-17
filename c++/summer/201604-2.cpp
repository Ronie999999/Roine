#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"
#include "iomanip"
#include <stack>
#include "unordered_map"



int main(){
    std::ios::sync_with_stdio(false);
    int paper[15][10];
    int item[4][4];
    int pos;
    std::vector<std::pair<int, int>> list;
    std::vector<std::pair<int, int>> bottom;
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 10; ++j) {
            int temp;
            std::cin >> temp;
            paper[i][j] = temp;
        }
    }
    for (int k = 0; k < 4; ++k) {
        for (int i = 0; i < 4; ++i) {
            int temp;
            std::cin >> temp;
            item[k][i] = temp;
            if (temp == 1) list.emplace_back(k, i);
        }
    }
    std::cin >> pos;
    for (int l = 0; l < 4; ++l) {
        for (int i = 3; i >= 0; --i) {
            if (item[i][l] == 1) {
                bottom.emplace_back(std::make_pair(i, l + pos - 1));
                break;
            }
        }
    }
    for (int m = 0; m < list.size(); ++m) {
        list[m].second += pos - 1;
    }
    bool stop = false;
    for (int n = 0; n < 15; ++n) {
        for (int i = 0; i < bottom.size(); ++i) {
            if (paper[bottom[i].first + 1][bottom[i].second] == 1 or bottom[i].first == 14) {
                stop = true;
                break;
            }
        }
        if (!stop){
            for (int i = 0; i < list.size(); ++i) {
                list[i].first++;
            }
            for (int j = 0; j < bottom.size(); ++j) {
                bottom[j].first++;
            }
        }
        if (stop) break;
        
    }
    for (int i1 = 0; i1 < list.size(); ++i1) {
        paper[list[i1].first][list[i1].second] = 1;
    }
    for (int k1 = 0; k1 < 15; ++k1) {
        for (int i = 0; i < 10; ++i) {
            std::cout << paper[k1][i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
