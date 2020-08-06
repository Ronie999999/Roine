//
// Created by ren on 2020/7/13.
//

#ifndef HOMEWORK_MATRIX_H
#define HOMEWORK_MATRIX_H
#include "vector"
#include "string"
#include "map"
#include<iterator>

class matrix {
public:
    matrix(std::vector<std::map<std::string, double>> map, std::vector<std::string> *words);
    std::vector<std::vector<double>> deal();

private:
    std::vector<std::map<std::string, double>> map;
    std::vector<std::string> str_;
    std::vector<std::vector<double>> words_matrix;
    std::vector<std::string> words[40];
    std::vector<std::map<std::string, double>> temp;
//    int words_matrix[40][]
};


#endif //HOMEWORK_MATRIX_H
