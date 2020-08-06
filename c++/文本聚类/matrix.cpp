//
// Created by ren on 2020/7/13.
//

#include "matrix.h"
#include <algorithm>
#include "iostream"
#include "string"
#include<iterator>
#include "map"

matrix::matrix(std::vector<std::map<std::string, double>> map, std::vector<std::string> *words) {
    for (int i = 0; i < map.size(); ++i) {
        this->map.push_back(map[i]);
    }
    for (int i = 0; i < 40; ++i) {
        this->words[i].assign(words[i].begin(),words[i].end());
    }
}

std::vector<std::vector<double>> matrix::deal() {
    std::map<std::string, double> ret;
    for (int i = 0; i < map.size(); ++i) {
        for (auto iter = map[i].begin(); iter != map[i].end(); ++iter) {
            auto it = ret.find(iter->first);
            if (it == ret.end()) {
                ret.insert(std::map<std::string, double>::value_type(iter->first, iter->second));
                str_.push_back(iter->first);
            }
        }
    }
     //words里的词频统计
    for (int i = 0; i < 40; ++i) {
        std::map<std::string, double> strMap;
        for (auto &j : words[i]) {
            auto it = strMap.find(j);
            if (it == strMap.end()) {
                strMap.insert(std::map<std::string, int>::value_type(j, 1.0));
            } else
                strMap[j]++;
        }
        temp.push_back(strMap);
    }
     // 向量生成
    for (int k = 0; k < 40; ++k) {
        std::vector<double> list;
        for (int i = 0; i < str_.size(); ++i) {
            auto it = temp[k].find(str_[i]);
            if (it == temp[k].end()) list.push_back(0);
            if (it != temp[k].end()) list.push_back(it->second);
        }
        words_matrix.push_back(list);
    }
    return words_matrix;

}