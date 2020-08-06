#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>


int main(){
    int n,m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> list;
    std::vector<std::vector<int>> hang;
    std::vector<std::vector<int>> lie;
    for (int i = 0; i < n; ++i) {
        std::vector<int> temp_vec;
        for (int j = 0; j < m; ++j) {
            int temp;
            std::cin >> temp;
            temp_vec.push_back(temp);
        }
        list.push_back(temp_vec);
    }
// 行
    for (int k = 0; k < n; ++k) {
        int number = list[k][0], count = 0, start = 0;
        std::vector<int> h; //1.行位置 2.start 3.end
        for (int i = 0; i < m; ++i) {
            if (number == list[k][i]) {
                count++;
            }
            if (number != list[k][i]) {
                number = list[k][i];
                if (count >= 3){
                    h.push_back(k);
                    h.push_back(start);
                    h.push_back(i);
                    hang.push_back(h);
                    h.clear();
                    count = 1;
                    start = i;
                } else{
                    start = i;
                    count = 1;
                }
            }
            else if (i == m - 1){
                if (count >= 3){
                    h.push_back(k);
                    h.push_back(start);
                    h.push_back(i + 1);
                    hang.push_back(h);
                }
            }
        }
    }

    for (int k = 0; k < m; ++k) {
        int number = list[0][k], count = 0, start = 0;
        std::vector<int> h; //1.列位置 2.start 3.end
        for (int i = 0; i < n; ++i) {
            if (number == list[i][k]) {
                count++;
            }
            if (number != list[i][k]) {
                number = list[i][k];
                if (count >= 3){
                    h.push_back(k);
                    h.push_back(start);
                    h.push_back(i);
                    lie.push_back(h);
                    h.clear();
                    count = 1;
                    start = i;
                } else{
                    start = i;
                    count = 1;
                }
            }
            else if (i == n - 1){
                if (count >= 3){
                    h.push_back(k);
                    h.push_back(start);
                    h.push_back(i + 1);
                    lie.push_back(h);
                }
            }
        }
    }
    
    
    for (int l = 0; l < hang.size(); ++l) {
        for (int i = hang[l][1]; i < hang[l][2]; ++i) {
            list[hang[l][0]][i] = 0;
        }
    }
    for (int l = 0; l < lie.size(); ++l) {
        for (int i = lie[l][1]; i < lie[l][2]; ++i) {
            list[i][lie[l][0]] = 0;
        }
    }
    for (int i1 = 0; i1 < n; ++i1) {
        for (int i = 0; i < m; ++i) {
            std::cout << list[i1][i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}