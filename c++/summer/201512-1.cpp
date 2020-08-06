#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>


int main(){
    std::string str;
    int total = 0;
    std::cin >> str;
    for (int i = 0; i < str.length(); ++i) {
        total += str[i] - 48;
    }
    std::cout << total << std::endl;
}