//
// Created by ren on 2020/7/10.
//
#define LETTER(ch) (isupper(ch) || islower(ch))
#define INC 50
static int i_max = INC;
static char *s;

#include <cstdlib>
#include <cstring>
#include "stemmer.h"
#include <cstdio>
#include <cctype>
#include "iostream"

bool stemmer::cons(struct stem *z, int i) {
    switch (z->b[i])
    {  case 'a': case 'e': case 'i': case 'o': case 'u': return false;
        case 'y': return (i == 0) ? true : !cons(z, i - 1);
        default: return true;
    }
}

int stemmer::m(struct stem *z)
{  int n = 0;
    int i = 0;
    int j = z->j;
    while(true)
    {  if (i > j) return n;
        if (! cons(z, i)) break; i++;
    }
    i++;
    while(true){
        while(true){
            if (i > j) return n;
            if (cons(z, i)) break;
            i++;
        }
        i++;
        n++;
        while(true){
            if (i > j) return n;
            if (! cons(z, i)) break;
            i++;
        }
        i++;
    }
}

int stemmer::vowelinstem(struct stem * z) {
    int j = z->j;
    int i; for (i = 0; i <= j; i++) if (! cons(z, i)) return true;
    return false;
}

bool stemmer::doublec(struct stem * z, int j) {
    char * b = z->b;
    if (j < 1) return false;
    if (b[j] != b[j - 1]) return false;
    return cons(z, j);
}

bool stemmer::cvc(struct stem * z, int i){
    if (i < 2 || !cons(z, i) || cons(z, i - 1) || !cons(z, i - 2)) return false;
    {  int ch = z->b[i];
        if (ch  == 'w' || ch == 'x' || ch == 'y') return false;
    }
    return true;
}

bool stemmer::ends(struct stem * z, const char * s) {
    int length = s[0];
    char * b = z->b;
    int k = z->k;
    if (s[length] != b[k]) return false; /* tiny speed-up */
    if (length > k + 1) return false;
    if (memcmp(b + k - length + 1, s + 1, length) != 0) return false;
    z->j = k-length;
    return true;
}

void stemmer::setto(struct stem * z, const char * s) {
    int length = s[0];
    int j = z->j;
    memmove(z->b + j + 1, s + 1, length);
    z->k = j+length;
}

void stemmer::r(struct stem * z, const char * s) {
    if (m(z) > 0) setto(z, s);
}

void stemmer::step1ab(struct stem * z){
    char * b = z->b;
    if (b[z->k] == 's')
    {  if (ends(z, "\04" "sses")) z->k -= 2; else
        if (ends(z, "\03" "ies")) setto(z, "\01" "i"); else
        if (b[z->k - 1] != 's') z->k--;
    }
    if (ends(z, "\03" "eed")) { if (m(z) > 0) z->k--; } else
    if ((ends(z, "\02" "ed") || ends(z, "\03" "ing")) && vowelinstem(z))
    {  z->k = z->j;
        if (ends(z, "\02" "at")) setto(z, "\03" "ate"); else
        if (ends(z, "\02" "bl")) setto(z, "\03" "ble"); else
        if (ends(z, "\02" "iz")) setto(z, "\03" "ize"); else
        if (doublec(z, z->k))
        {  z->k--;
            {  int ch = b[z->k];
                if (ch == 'l' || ch == 's' || ch == 'z') z->k++;
            }
        }
        else if (m(z) == 1 && cvc(z, z->k)) setto(z, "\01" "e");
    }
}

void stemmer::step1c(struct stem * z){
    if (ends(z, "\01" "y") && vowelinstem(z)) z->b[z->k] = 'i';
}

void stemmer::step2(struct stem * z) {
    switch (z->b[z->k-1])
    {
        case 'a': if (ends(z, "\07" "ational")) { r(z, "\03" "ate"); break; }
            if (ends(z, "\06" "tional")) { r(z, "\04" "tion"); break; }
            break;
        case 'c': if (ends(z, "\04" "enci")) { r(z, "\04" "ence"); break; }
            if (ends(z, "\04" "anci")) { r(z, "\04" "ance"); break; }
            break;
        case 'e': if (ends(z, "\04" "izer")) { r(z, "\03" "ize"); break; }
            break;
        case 'l': if (ends(z, "\03" "bli")) { r(z, "\03" "ble"); break; } /*-DEPARTURE-*/

            /* To match the published algorithm, replace this line with
               case 'l': if (ends(z, "\04" "abli")) { r(z, "\04" "able"); break; } */

            if (ends(z, "\04" "alli")) { r(z, "\02" "al"); break; }
            if (ends(z, "\05" "entli")) { r(z, "\03" "ent"); break; }
            if (ends(z, "\03" "eli")) { r(z, "\01" "e"); break; }
            if (ends(z, "\05" "ousli")) { r(z, "\03" "ous"); break; }
            break;
        case 'o': if (ends(z, "\07" "ization")) { r(z, "\03" "ize"); break; }
            if (ends(z, "\05" "ation")) { r(z, "\03" "ate"); break; }
            if (ends(z, "\04" "ator")) { r(z, "\03" "ate"); break; }
            break;
        case 's': if (ends(z, "\05" "alism")) { r(z, "\02" "al"); break; }
            if (ends(z, "\07" "iveness")) { r(z, "\03" "ive"); break; }
            if (ends(z, "\07" "fulness")) { r(z, "\03" "ful"); break; }
            if (ends(z, "\07" "ousness")) { r(z, "\03" "ous"); break; }
            break;
        case 't': if (ends(z, "\05" "aliti")) { r(z, "\02" "al"); break; }
            if (ends(z, "\05" "iviti")) { r(z, "\03" "ive"); break; }
            if (ends(z, "\06" "biliti")) { r(z, "\03" "ble"); break; }
            break;
        case 'g': if (ends(z, "\04" "logi")) { r(z, "\03" "log"); break; } /*-DEPARTURE-*/

            /* To match the published algorithm, delete this line */

    }
}

void stemmer::step3(struct stem * z) {
    switch (z->b[z->k])
    {
        case 'e': if (ends(z, "\05" "icate")) { r(z, "\02" "ic"); break; }
            if (ends(z, "\05" "ative")) { r(z, "\00" ""); break; }
            if (ends(z, "\05" "alize")) { r(z, "\02" "al"); break; }
            break;
        case 'i': if (ends(z, "\05" "iciti")) { r(z, "\02" "ic"); break; }
            break;
        case 'l': if (ends(z, "\04" "ical")) { r(z, "\02" "ic"); break; }
            if (ends(z, "\03" "ful")) { r(z, "\00" ""); break; }
            break;
        case 's': if (ends(z, "\04" "ness")) { r(z, "\00" ""); break; }
            break;
    }
}

void stemmer::step4(struct stem * z){
    switch (z->b[z->k-1])
    {  case 'a': if (ends(z, "\02" "al")) break; return;
        case 'c': if (ends(z, "\04" "ance")) break;
            if (ends(z, "\04" "ence")) break; return;
        case 'e': if (ends(z, "\02" "er")) break; return;
        case 'i': if (ends(z, "\02" "ic")) break; return;
        case 'l': if (ends(z, "\04" "able")) break;
            if (ends(z, "\04" "ible")) break; return;
        case 'n': if (ends(z, "\03" "ant")) break;
            if (ends(z, "\05" "ement")) break;
            if (ends(z, "\04" "ment")) break;
            if (ends(z, "\03" "ent")) break; return;
        case 'o': if (ends(z, "\03" "ion") && z->j >= 0 && (z->b[z->j] == 's' || z->b[z->j] == 't')) break;
            if (ends(z, "\02" "ou")) break; return;
            /* takes care of -ous */
        case 's': if (ends(z, "\03" "ism")) break; return;
        case 't': if (ends(z, "\03" "ate")) break;
            if (ends(z, "\03" "iti")) break; return;
        case 'u': if (ends(z, "\03" "ous")) break; return;
        case 'v': if (ends(z, "\03" "ive")) break; return;
        case 'z': if (ends(z, "\03" "ize")) break; return;
        default: return;
    }
    if (m(z) > 1) z->k = z->j;
}

void stemmer::step5(struct stem * z) {
    char * b = z->b;
    z->j = z->k;
    if (b[z->k] == 'e')
    {  int a = m(z);
        if (a > 1 || a == 1 && !cvc(z, z->k - 1)) z->k--;
    }
    if (b[z->k] == 'l' && doublec(z, z->k) && m(z) > 1) z->k--;
}

int stemmer::st(struct stem * z, char * b, int k) {
    if (k <= 1) return k; /*-DEPARTURE-*/
    z->b = b; z->k = k; /* copy the parameters into z */

    /* With this line, strings of length 1 or 2 don't go through the
       stemming process, although no mention is made of this in the
       published algorithm. Remove the line to match the published
       algorithm. */

    step1ab(z);
    if (z->k > 0) {
        step1c(z); step2(z); step3(z); step4(z); step5(z);
    }
    return z->k;
}
struct stem * stemmer::create_stemmer()
{
    return (struct stem *) malloc(sizeof(struct stem));
    /* assume malloc succeeds */
}

std::string stemmer::stemfile(struct stem * z, FILE * f)
{
    std::string passage;
    while(true){
        int ch = getc(f);
        if (ch == EOF) return passage;
        if (LETTER(ch)){
            int i = 0;
            while(true){
                if (i == i_max){
                    i_max += INC;
                    s = static_cast<char *>(realloc(s, i_max + 1));
                }
                ch = tolower(ch); /* forces lower case */
                s[i] = ch; i++;
                ch = getc(f);
                if (!LETTER(ch)) { ungetc(ch,f); break; }
            }
            s[st(z, s, i - 1) + 1] = 0;
//            printf("%s",s);
            passage.append(s);
        }
        else {
//            putchar(ch);
            passage.append(1,ch);
        }
    }
}

void stemmer::start(const std::vector<int>& center_list_start) {
    std::string msg;
    std::vector<std::string> words[40];
    std::vector<std::string> temp;
    std::vector<std::map<std::string, double>> fre;
    std::vector<std::vector<double>> ma;
    std::vector<double> center;
//    std::vector<int> center_list_start = {6,13,21,39};
    struct stem * z = this->create_stemmer();
    s = (char *) malloc(i_max + 1);
    for (int i = 0; i < 40; ++i){
        std::string passage;
        char num[3];
        itoa( i+1, num, 10);
        char file_name[50] = R"(E:\homework\Testing-40\)";
        strcat(file_name,num);
        strcat(file_name,".txt");
        FILE * f = fopen(file_name,"r");
        if (f == nullptr) {
            fprintf(stderr,"File not found -> %s\n",file_name);
            exit(1);
        }
        passage = stemfile(z , f);
        if (passage != " ") printf("successfully open file -> %s\n", file_name);
        printf("successfully read and deal the file -> %s\n", file_name);
        printf("start to split the passage -> %s\n", file_name);
        words[i] = split::start(passage);
        std::cout << std::endl;
    }
    word_frequency frequency(words);
    std::cout << "Calculating word frequency" << std::endl;

    fre = frequency.start(); //统计词频，
    std::cout << "Done" << std::endl;
    matrix mat(fre, words);
    std::cout << "Generating vectors" << std::endl;
    ma = mat.deal(); // 生成向量
    std::cout << "Done" << std::endl;
    k_means k(ma, center_list_start);
    std::cout << "Start clustering\n" << std::endl;
    k.len(); // 聚类

    free(s);
    free(z);
}
