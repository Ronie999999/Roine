//
// Created by ren on 2020/7/10.
//

#ifndef HOMEWORK_WORD_FREQUENCY_H
#define HOMEWORK_WORD_FREQUENCY_H
#include "vector"
#include "string"
#include<iterator>
#include<cctype>
#include<unordered_map>
#include <cmath>
#include "map"
class word_frequency {
public:
    word_frequency(std::vector<std::string> words[40]);

    std::vector<std::map<std::string, double>> start();
//    bool cmp(const std::pair<std::string, double>& a, const std::pair<std::string, double>& b);

private:
    std::vector<std::string> words[40];
    std::vector<std::map<std::string, double>> tf_idf;
    std::vector<std::map<std::string, double>> return_tf_idf;
    std::map<std::string, double> idf;
    std::vector<std::map<std::string, double>> TF();
    std::map<std::string, double> IDF();
    std::vector<std::map<std::string, double>> TF_IDF();
//    std::vector<std::map<std::string, double>> tf_idf;

};


#endif //HOMEWORK_WORD_FREQUENCY_H
