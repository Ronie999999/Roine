#include "stemmer.h"
#include "vector"
#include "fstream"
#include "string"
int main() {
//    std::vector<int> center_list_start = {6,13,21,39};
//    stemmer text;
//    text.start(center_list_start);
//    system("pause");
//    return 0;
    for (int i = 0; i < 40; ++i) {
        std::string msg, temp;
        std::ifstream in(R"(E:\homework\Testing-40\)"+std::to_string(i + 1)+".txt", std::ios::in);
        while (getline(in,temp)){
//            std::cout << temp << std::endl;
            msg.append(temp);
        }
        std::cout << msg <<"\n"<< std::endl;
    }
}