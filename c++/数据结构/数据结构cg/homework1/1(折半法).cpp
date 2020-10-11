#include <iostream>
#include "vector"
#include "string"
#include <sstream>
#include "cmath"
int main() {
    int total, num;
    std::string data;
    std::vector<int> list;
    std::vector<int> result;
    std::cin >> total;
    list.reserve(total);
    for (int i = 0; i < total - 1; ++i) {
        std::getline(std::cin, data, ',');
        int number = atoi(data.c_str());
        list.push_back(number);
    }
    std::getline(std::cin, data);
    int number = atoi(data.c_str());
    list.push_back(number);
    std::cin >> num;


    int pos_start = 0, pos_end = total;
    for (int j = 0; j < int(log2(total)); ++j) {
        int pos;
        pos = (pos_end - pos_start) / 2 + pos_start;
        int pos_num = list[pos];
        if (pos_num != num){
//            std::cout << pos_num << " ";
            result.push_back(pos_num);
            if (pos_num < num){
                pos_start = pos;
            }
            else if (pos_num > num){
                pos_end = pos;
            }
        }
        else {
            std::cout << pos << std::endl;
            for (int i = 0; i < result.size(); ++i) {
                std::cout << result[i] << ",";
            }
            std::cout << pos_num;
            exit(0);
        }
    }
    std::cout << "no" << std::endl;
    for (int i = 0; i < result.size(); ++i) {
        if (i == result.size() - 1) std::cout << result[i];
        else std::cout << result[i] << ",";
    }
    return 0;
}
//11
//2,5,8,11,15,16,22,24,27,35,50
//22

//11
//2,5,8,11,15,16,22,24,27,35,50
//10
