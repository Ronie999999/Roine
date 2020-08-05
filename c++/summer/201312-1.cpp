#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second > b.second;
}
bool cmp2(const std::pair<int, int>& a, const std::pair<int, int>& b){
    return a.first < b.first;
}
int main() {
    int num; std::map<int, int> map;
    std::vector<int> list;
    std::cin >> num;
    for (int i = 0; i < num; ++i) {
        int temp;
        std::cin >> temp;
        list.push_back(temp);
    }
    for (int j = 0; j < list.size(); ++j) {
        auto it = find(list.begin(), list.end(), list[j]);
        if (it == list.end()) //strMap中如果不存在当前单词则插入一个新键值对，出现频率为1
        {
            map.insert(std::map<int, int>::value_type(list[j], 1.0));
        } else                   //如果存在则出现频率+1
            map[list[j]]++;
    }

    std::vector<std::pair<int, int>> vec(map.begin(), map.end());
    sort(vec.begin(), vec.end(), cmp);
    auto start = vec.begin(), end = vec.begin();
    for (auto iter = vec.begin(); iter != vec.end() + 1; ++iter) {
        if (start->second != iter->second) {
             end = iter;
             sort(start, end, cmp2);
             start = iter;
        }
        if (iter == vec.end()){
            sort(start, vec.end(), cmp2);
        }
    }
    std::cout << vec.begin()->first << std::endl;
//    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
//        std::cout << iter->first <<" "<< iter->second << std::endl;
//    }

    return 0;
}

