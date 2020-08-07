#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>


int main(){
    int count = 0, score = 0;
    while (true) {
        int num;
        std::cin >> num;
        if (num == 0) break;
        else if (num == 1) {
            score++;
            count = 0;
        }
        else if (num == 2){
            count++;
            score += count * 2;
        }
    }
    std::cout << score <<std::endl;
    return 0;
}