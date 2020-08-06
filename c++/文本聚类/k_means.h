//
// Created by ren on 2020/7/14.
//

#ifndef HOMEWORK_K_MEANS_H
#define HOMEWORK_K_MEANS_H
#include "vector"
#include "iostream"
#include "cmath"
#include "algorithm"
class k_means {
public:
    k_means(std::vector<std::vector<double>> matrix, const std::vector<int>& center_list_start);
    double cos_(std::vector<double> first, std::vector<double> second);
    void len();
private:
    std::vector<std::vector<double>> matrix;
    std::vector<std::vector<double>> center_matrix;
    std::vector<double> center;
    std::vector<std::vector<int>> final;
    bool mark = true;
    int time = 1;
};


#endif //HOMEWORK_K_MEANS_H
