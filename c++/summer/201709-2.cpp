#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"
#include "iomanip"
#include <stack>
#include "unordered_map"
bool cmp(std::pair<int, int> &a, std::pair<int, int> &b)
{
    return a.first < b.first;
}

int main(){
    std::ios::sync_with_stdio(false);
    int n ,k;
    std::cin >> n >> k;
    std::vector<int> room;
    room.reserve(n);
    for (int j = 0; j < n; ++j) {
        room.push_back(j + 1);
    }
    std::vector<int> number_room;
    std::vector<int> start;
    std::vector<int> end;
    int max;
    for (int i = 0; i < k; ++i) {
        int w, s, c;
        std::cin >> w >> s >> c;
        if (i == 0)
            max = c + s;
        if (c + s > max) max = c + s;
        number_room.push_back(w);
        start.push_back(s);
        end.push_back(c + s);
    }

    for (int l = 1; l < max + 1; ++l) {
        std::vector<std::pair<int, int>> return_list;
        while (true){
            auto it = std::find(end.begin(), end.end(), l);
            int xia = it - end.begin();
            if (it == end.end()) break;
            else {
                return_list.emplace_back(number_room[xia],xia);
//                auto r = std::find(room.begin(), room.end(), -1);
//                *r = number_room[xia];
                *it = -1;
            }
        }
        std::sort(return_list.begin(), return_list.end(), cmp);
        for (int i = 0; i < return_list.size(); ++i) {
            auto r = std::find(room.begin(), room.end(), -1);
            *r = number_room[return_list[i].second];
        }
        while (true){
            auto it = std::find(start.begin(), start.end(), l);
            int xia = it - start.begin();
            if (it == start.end()) break;
            else{
                auto b = std::find(room.begin(), room.end(), number_room[xia]);
                *it = -1;
                *b = -1;
            }
        }
    }
    for (int m = 0; m < n; ++m) {
        std::cout << room[m] << " ";
    }
    return 0;
}