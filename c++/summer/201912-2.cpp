#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"

int main(){
    int num;
    std::cin >> num;
    std::map<std::pair<int, int>, int> map, map2;
    std::vector<std::pair<int, int>> vec;
    for (int i = 0; i < num; ++i) {
        int m,n;
        std::cin >> m >> n;
        std::pair<int, int> temp;
        temp.first = m;
        temp.second = n;
        vec.push_back(temp);
        map.insert(std::pair<std::pair<int ,int>, int>(temp, 0));
    }
    map2 = map;
    for (int j = 0; j < num; ++j) {
        std::pair<int ,int> temp1(vec[j].first + 1, vec[j].second);
        std::pair<int ,int> temp2(vec[j].first - 1, vec[j].second);
        std::pair<int ,int> temp3(vec[j].first, vec[j].second + 1);
        std::pair<int ,int> temp4(vec[j].first, vec[j].second - 1);

        if (map2.find(temp1) == map2.end() or map2.find(temp2) == map2.end() or map2.find(temp3) == map2.end() or map2.find(temp4) == map2.end()){
            map.erase(vec[j]);
        }
    }
    for (auto it = map.begin(); it != map.end() ; ++it) {
        std::pair<int, int> temp1(it->first.first + 1, it->first.second + 1);
        std::pair<int, int> temp2(it->first.first - 1, it->first.second - 1);
        std::pair<int, int> temp3(it->first.first + 1, it->first.second - 1);
        std::pair<int, int> temp4(it->first.first - 1, it->first.second + 1);
        if (std::find(vec.begin(), vec.end(), temp1) != vec.end()) map[it->first]++;
        if (std::find(vec.begin(), vec.end(), temp2) != vec.end()) map[it->first]++;
        if (std::find(vec.begin(), vec.end(), temp3) != vec.end()) map[it->first]++;
        if (std::find(vec.begin(), vec.end(), temp4) != vec.end()) map[it->first]++;
    }
    std::map<int, int> final;
    for (int k = 0; k < 5; ++k) {
        final.insert(std::pair<int, int>(k,0));
    }
    for (auto it = map.begin(); it != map.end() ; ++it) {
        if (it->second == 0) final[0]++;
        if (it->second == 1) final[1]++;
        if (it->second == 2) final[2]++;
        if (it->second == 3) final[3]++;
        if (it->second == 4) final[4]++;
    }
    for (auto it = final.begin(); it != final.end() ; ++it) {
        std::cout << it->second << std::endl;
    }
    return 0;
}
