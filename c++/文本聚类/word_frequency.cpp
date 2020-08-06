//
// Created by ren on 2020/7/10.
//
#include "iostream"
#include "word_frequency.h"
#include "string"
#include<iterator>
#include "unordered_map"
#include "map"
#include <algorithm>

bool cmp(const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {
    return a.second > b.second;
}


word_frequency::word_frequency(std::vector<std::string> *words) {
    for (int i = 0; i < 40; ++i) {
        this->words[i].assign(words[i].begin(),words[i].end());
    }
}

std::vector<std::map<std::string, double>> word_frequency::TF() {   // 文本频率
    for (int i = 0; i < 40 ; ++i) {
        std::map<std::string,double> strMap;
        for (auto & j : words[i]) {
            auto it = strMap.find(j);
            if (it == strMap.end()) //strMap中如果不存在当前单词则插入一个新键值对，出现频率为1
            {
                strMap.insert(std::map<std::string, double>::value_type(j, 1.0));
            } else                   //如果存在则出现频率+1
                strMap[j]++;
        }
        for (auto iter = strMap.begin(); iter != strMap.end(); ++iter) {
            strMap[iter->first] = iter->second/words[i].size();
        }
//        std::cout << strMap.size() << ":" << i <<std::endl;

//        for (auto iter = strMap.begin(); iter != strMap.end(); ++iter) {
//            std::cout << iter->first <<" : " << iter->second << std::endl;
//        }
        tf_idf.push_back(strMap);
    }
    return tf_idf;
}

std::map<std::string, double> word_frequency::IDF() {
    std::vector<std::string> s;
    std::vector<std::string>::iterator ret;
    for (int i = 0; i < 40; ++i) {
        for (int j = 0; j < words[i].size(); ++j) {
            ret = std::find(s.begin(), s.end(), words[i][j]);
            if (ret == s.end()){
                s.push_back(words[i][j]);
            }
        }
    }

    for (int k = 0; k < s.size(); ++k) {
        int num = 0;
        for (int i = 0; i < 40; ++i) {
            auto it = tf_idf[i].find(s[k]);
            if (it != tf_idf[i].end()){
                num++;
            }
        }
        idf.insert(std::map<std::string, double>::value_type(s[k],std::log2(40.0/(num + 1))));
    }
    return idf;
}

std::vector<std::map<std::string, double>> word_frequency::TF_IDF() {
    for (int i = 0; i < tf_idf.size(); ++i) {
        for (auto iter = tf_idf[i].begin(); iter != tf_idf[i].end(); ++iter) {
            tf_idf[i][iter->first] = tf_idf[i][iter->first] * idf[iter->first];
        }
    }
//    std::cout << tf_idf.size() << std::endl;
    for (int j = 0; j < tf_idf.size(); ++j) {
        std::vector<std::pair<std::string, double>> vec(tf_idf[j].begin(), tf_idf[j].end());
        //对线性的vector进行排序
        sort(vec.begin(), vec.end(), cmp);
        std::map<std::string, double> temp_map;
        for (int k = 0; k < 6; ++k) {
//            std::cout << vec[k].second << std::endl;

            temp_map.insert(std::map<std::string, double>::value_type(vec[k].first, vec[k].second));
        }
        return_tf_idf.push_back(temp_map);
    }
    return return_tf_idf;
}

std::vector<std::map<std::string, double>> word_frequency::start() {
    TF();
    IDF();
    return TF_IDF();
//    for (int i = 0; i < tf_idf.size(); ++i) {
//        std::cout << i << std::endl;
//        for (auto iter = tf_idf[i].begin(); iter != tf_idf[i].end(); ++iter) {
//            std::cout << tf_idf[i][iter->first] << std::endl;
//        }
//    }
}


