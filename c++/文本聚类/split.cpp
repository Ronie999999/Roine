//
// Created by ren on 2020/7/8.
//

#include "split.h"
#include "iostream"
#include "fstream"

std::vector<std::string> split::start(std::string passage){
    std::vector<std::string> str_list_temp;
    std::vector<std::string> str_list;
    std::string temp;
    int start = 0;
    for (int i = 0; i < passage.length(); ++i) {
        if (passage[i] == 32){
            int length = i - start;
            temp = passage.substr(start, length);
            str_list_temp.push_back(temp);
            start = i + 1;
        }
    }
    str_list_temp.push_back(passage.substr(start));
//    for (int j = 0; j < str_list_temp.size(); ++j) {
//        std::cout << str_list_temp[j] << std::endl;
//    }
//    std::cout << "\n" << std::endl;


    // 去除stopwords
    std::ifstream read("E:\\homework\\stopwords.txt");
    std::string line;
    if (not read.good()){
        std::cout << "open stopwords file failed" << std::endl;
    }
    for (int i = 0; i < str_list_temp.size(); ++i) {
        int num = 0; bool find = false;
        while (std::getline(read, line)){
            if (str_list_temp[i] == line) {
                find = true;
                break;
            }
        }
        if (not find){
            unsigned long long int tmp = str_list_temp[i].length() - 1;
            if (97 > str_list_temp[i][tmp] or str_list_temp[i][tmp] > 122) str_list_temp[i] = str_list_temp[i].substr(0,tmp);
            if (97 > str_list_temp[i][0] or str_list_temp[i][0] > 122) continue;
            str_list.push_back(str_list_temp[i]);
        }
        read.clear();
        read.seekg(0, std::ios::beg);
    }

    read.close();
    std::cout << "split success" << std::endl;
    return str_list;
}




