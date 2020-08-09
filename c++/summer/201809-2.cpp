
#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"
#include "iomanip"

// 买菜
int main(){
    int num, time = 0;
    std::vector<std::pair<int ,int>> H, W;
    std::cin >> num;
    for (int i = 0; i < num; ++i) {
        int a, b;
        std::cin >> a >> b;
        std::pair<int, int> pair(a, b);
        H.push_back(pair);
    }
    for (int i = 0; i < num; ++i) {
        int a, b;
        std::cin >> a >> b;
        std::pair<int, int> pair(a, b);
        W.push_back(pair);
    }
    for (int j = 0; j < num; ++j) {
        for (int i = 0; i < num; ++i) {
            if (H[j].second > W[i].second){
                if (H[j].first >= W[i].second) time += 0;
                else {
                    if (H[j].first >= W[i].first) time += W[i].second - H[j].first;
                    if (H[j].first < W[i].first) time += W[i].second - W[i].first;
                }
            }
            else if (H[j].second < W[i].second){
                if (W[i].first >= H[j].second) time += 0;
                else {
                    if (W[i].first >= H[j].first) time += H[j].second - W[i].first;
                    if (W[i].first < H[j].first) time += H[j].second - H[j].first;
                }
            }
            else if (H[j].second == W[i].second){
                if (H[j].first == W[i].first) time += abs(H[j].second - W[i].first);
                else if (H[j].first > W[i].first) time += H[j].second - H[j].first;
                else time += W[i].second - W[i].first;
            }
        }
    }
    std::cout << time << std::endl;
    return 0;
}
