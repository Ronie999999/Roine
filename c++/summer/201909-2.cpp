
#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"
#include "iomanip"

//2019/09/2
int main(){
    int num;
    std::vector<std::vector<int>> list;
    std::vector<int> final_apple;
    std::cin >> num;
    for (int i = 0; i < num; ++i) {
        int time;
        std::cin >> time;
        std::vector<int> temp;
        for (int j = 0; j < time; ++j) {
            int number;
            std::cin >> number;
            temp.push_back(number);
        }
        list.push_back(temp);
    }
    int total_apple = 0;
    for (int k = 0; k < num; ++k) {
        int final_apple_each;
        for (int i = list[k].size() - 1; i >= 0; --i) {
            if (list[k][i] > 0) {
                final_apple_each = list[k][i];
                for (int j = i + 1; j < list[k].size(); ++j) {
                    final_apple_each += list[k][j];
                }
                break;
            }
        }
//        final_apple.push_back(final_apple_each);
        total_apple += final_apple_each;
    }
    int fall_tree = 0;
    std::vector<bool> check_fall(num, false);
    for (int l = 0; l < num; ++l) {
        int fall = list[l][0];
        for (int i = 1; i < list[l].size(); ++i) {
            if (list[l][i] > 0){
                if (fall > list[l][i]) {
                    check_fall[l] = true;
                    fall_tree++;
                    break;
                }
            } else fall += list[l][i];
        }
    }
//    std::cout << 1;
    int number = 0;
    if (num > 2){
        for (int m = 0; m < num; ++m) {
            if (m == num - 2){
                if (check_fall[m] and check_fall[m + 1] and check_fall[0]) number++;
            }
            else if (m == num - 1){
                if (check_fall[m] and check_fall[0] and check_fall[1]) number++;
            }
            else if (check_fall[m] and check_fall[m + 1] and check_fall[m + 2]) number++;
        }
    }
    std::cout << total_apple << " " << fall_tree << " " << number;
    return 0;
}

