#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"
#include "iomanip"
#include <stack>

int find(std::map<int, std::pair<int, int>> &position, int pos, int direction, int num){
    if (direction > 0){
        for (int i = 0; i < num; ++i) {
            if (pos == position[i].first and position[i].second < 0) return i;
        }
    }
    if (direction < 0){
        for (int i = 0; i < num; ++i) {
            if (pos == position[i].first and position[i].second > 0) return i;
        }
    }
}
int main(){
    int n, l, t;
    std::cin >> n >> l >> t; l++;
    std::vector<std::pair<int, int>> list; // 编号，位置
    std::vector<std::pair<int, int>> list2;
    std::map<int, int> map;
    std::map<int, std::pair<int, int>> position; // 编号，位置，方向
    std::map<int, bool> line; // 位置是否被占用 位置，占用:true
    for (int m = 0; m < l - 1; ++m) {
        line.insert(std::pair<int, bool>(m, false));
    }
    for (int i1 = 0; i1 < n; ++i1) {
        int temp;
        std::cin >> temp;
        list.push_back(std::pair<int, int>(i1, temp));
    }

    for (int i = 0; i < n; ++i) {
        line[list[i].second] = true;
        std::pair<int, int> a(list[i].second, 1);
        position.insert(std::pair<int, std::pair<int ,int>>(i, a));
    }

    if (line[l]) position[l].second = -1;
    for (int j = 0; j < t; ++j) {
        for (int i = 0; i < n; ++i) {
            if (position[i].second > 0){
                line[position[i].first] = false;
                position[i].first++;
                if (line[position[i].first]){
                    position[i].second = -1;
                    position[find(position, position[i].first, 1, n)].second = 1;
                }
                line[position[i].first] = true;
                if (position[i].first == l - 1) position[i].second = -1;
//                std::cout <<i<< ":"<<position[i].first << " "<< position[i].second <<"\t";
            }
            else if (position[i].second < 0){
                line[position[i].first] = false;
                position[i].first--;
                if (line[position[i].first]){
                    position[i].second = 1;
                    position[find(position, position[i].first, -1, n)].second = -1;
                }
                line[position[i].first] = true;
                if (position[i].first == 0) position[i].second = 1;
//                std::cout <<i<<":"<< position[i].first << " " << position[i].second <<"\t";
            }
        }
    }
    for (int k = 0; k < position.size(); ++k) {
        std::cout << position[k].first << " ";
    }
    return 0;
}

