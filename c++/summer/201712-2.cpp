#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"
#include "iomanip"
bool check_pass(int number, int k){
    std::string str_number = std::to_string(number);
    std::string str_num = std::to_string(k);
    if (str_number[str_number.length() - 1] == str_num[0]) return true;
    return number % k == 0;
}

int main(){
    int child, num, say = 0, last;
    std::cin >> child >> num;
    last = child;
    std::vector<bool> list(child, true);
    while (true){
        for (int i = 0; i < child; ++i) {
            if (list[i] == true){
                bool temp = check_pass(++say, num);
                if (temp) {
                    list[i] = false;
                    last--;
                    if (last == 1) break;

                }
            }

        }
        if (last == 1) break;
    }
    for (int j = 0; j < child; ++j) {
        if (list[j] == true){
            std::cout << j+ 1 << std::endl;
            break;
        }
    }
    return 0;
}
