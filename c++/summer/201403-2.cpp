#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>

int main(){
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> list;
    std::vector<std::pair<int, int>> click_pos;
    for (int k = 0; k < N; ++k) {
        std::vector<int> tem;
        for (int i = 0; i < 4; ++i) {
            int temp;
            std::cin >> temp;
            tem.push_back(temp);
        }
        tem.push_back(k+1);
        list.push_back(tem);
    }
    for (int l = 0; l < M; ++l) {
        std::pair<int, int> temp;
        std::cin >> temp.first >> temp.second;
        click_pos.push_back(temp);
    }
    for (int j = 0; j < M; ++j) {
        bool check = false;
        for (int i = N - 1; i >= 0; --i) {
            if (click_pos[j].first >= list[i][0]
            and click_pos[j].first <= list[i][2]
            and click_pos[j].second >= list[i][1]
            and click_pos[j].second <= list[i][3]){
                std::cout << list[i][4] << std::endl;
                check = true;
                for (int k = i; k + 1 < N; ++k) {
                    std::swap(list[k],list[k+ 1]);
                }
                break;
            }
        }
        if (not check) std::cout << "IGNORED" << std::endl;
    }
    return 0;
}