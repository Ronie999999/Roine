//
// Created by ren on 2020/7/14.
//

#include "k_means.h"
#include <algorithm>
k_means::k_means(std::vector<std::vector<double>> matrix, const std::vector<int>& center_list_start) {
    for (int i = 0; i < matrix.size(); ++i) {
        this->matrix.push_back(matrix[i]);
    }
    for (int j = 0; j < center_list_start.size(); ++j) {
        center_matrix.push_back(matrix[center_list_start[j] - 1]);
        this->center.push_back(center_list_start[j] - 1);
    }

}

double k_means::cos_(std::vector<double> first, std::vector<double> second) {
    double top = 0, bottom, temp1 = 0, temp2 = 0;
    for (int i = 0; i < first.size(); ++i) {
        top += first[i] * second[i];
    }
    for (int j = 0; j < first.size(); ++j) {
        temp1 += pow(first[j], 2);
        temp2 += pow(second[j], 2);
    }
    bottom = sqrt(temp2) * sqrt(temp1);
    return top/bottom;
}


void k_means::len() {
//    int center[] = {6,13,21,39}; // 聚类中心
    bool finish = false;
    std::vector<std::vector<int>> final_local;
    std::vector<int> abcd[center.size()]; // 分类
    for (int i = 0; i < 40; ++i) {
        double fin[center.size()];
        for (int j = 0; j < center.size(); ++j) {
            fin[j] = cos_(matrix[i], center_matrix[j]);
        }
        double t[center.size()];
        for (int l = 0; l < center.size(); ++l) {
            t[l] = fin[l];
        }
        double *v = std::max_element(t, t + center.size());

        for (int k = 0; k < center.size(); ++k) {
            if (*v == fin[k]) abcd[k].push_back(i);
        }
    }
    for (int n = 0; n < center.size(); ++n) {
        final_local.push_back(abcd[n]);
    }
    if (mark) {
        for (int n = 0; n < center.size(); ++n) {
            final.push_back(abcd[n]);
        }
    }
    if (not mark) {
        for (int m = 0; m < final_local.size(); ++m) {
            if (final_local[m] != this->final[m]) {
                break;
            }
            if (m == final_local.size() - 1 and final_local[m] == this->final[m]) finish = true;
        }
        final.clear();
        for (int n = 0; n < center.size(); ++n) {
            final.push_back(abcd[n]);
        }
    }
    mark = false;
    std::vector<double> new_center_list;
    for (int l = 0; l < final_local.size()/* 4 */; ++l) {
        for (int k = 0; k < matrix[final_local[l][0]].size() /* 向量长度 */; ++k) {
            double temp = 0;
            for (int i = 0; i < final_local[l].size(); ++i) {
                temp += matrix[final_local[l][i]][k];// l类中第i篇文章的向量的第k个元素
            }
            temp = temp / final_local[l].size();
            new_center_list.push_back(temp);
        }
        center_matrix[l] = new_center_list;
        new_center_list.clear();
    }
    if (not finish){
        std::cout <<"The " <<time << " time" <<" clustering : " << std::endl;
        for (int i = 0; i < final_local.size(); ++i) {
            std::cout  << "The "<< i + 1 <<" category" << ": ";
            for (int j = 0; j < final_local[i].size(); ++j) {
                std::cout << final_local[i][j] + 1 << "  ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        time++;
        this->len();
    }
    if (finish){
        std::cout << "clustering success" << std::endl;
        for (int i = 0; i < final_local.size(); ++i) {
            std::cout  << "The "<< i + 1 <<" category" << ": ";
            for (int j = 0; j < final_local[i].size(); ++j) {
                std::cout << final_local[i][j] + 1 << "  ";
            }
            std::cout <<std::endl;
        }
    }
}
