#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>

int main(){
    int num;
    std::cin >> num;
    std::vector<int> list;
    for (int i = 0; i < num; ++i) {
        int temp;
        std::cin >> temp;
        list.push_back(temp);
    }
    std::map<int, int> map;
    for (int j = 0; j < num; ++j) {
//        std::cout << list[j] << std::endl;
        auto it = map.find(list[j]);
        if (it == map.end()) //strMap中如果不存在当前单词则插入一个新键值对，出现频率为1
        {
            map.insert(std::map<int, int>::value_type(list[j], 1.0));
            std::cout << map[list[j]] << " ";
        } else {                  //如果存在则出现频率+1
            map[list[j]]++;
            std::cout << map[list[j]] << " ";
        }
    }
    return 0;
}