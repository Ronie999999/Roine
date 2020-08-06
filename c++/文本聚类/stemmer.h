//
// Created by ren on 2020/7/10.
//

#ifndef HOMEWORK_STEMMER_H
#define HOMEWORK_STEMMER_H
#include "split.h"
#include "string"
#include "word_frequency.h"
#include "matrix.h"
#include "k_means.h"
#include "stemmer.h"
#include "iostream"
#include <cstdio>
struct stem {
    char * b;       /* buffer for word to be stemmed */
    int k;          /* offset to the end of the string */
    int j;          /* a general offset into the string */
};

class stemmer {
private:
    bool cons(struct stem *z, int i);
    int m(struct stem *z);
    int vowelinstem(struct stem *z);
    bool doublec(struct stem *z, int j);
    bool cvc(struct stem *z, int i);
    static bool ends(struct stem *z,const char *s);
    static void setto(struct stem * z, const char * s);
    void r(struct stem * z, const char * s);
    void step1ab(struct stem * z);
    void step1c(struct stem * z);
    void step2(struct stem * z);
    void step3(struct stem * z);
    void step4(struct stem * z);
    void step5(struct stem * z);
    static struct stem * create_stemmer();
    int st(struct stem * z, char * b, int k);
    std::string stemfile(struct stem * z, FILE * f);
public:
    void start(const std::vector<int>& center_list_start);
};


#endif //HOMEWORK_STEMMER_H
