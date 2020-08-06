#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>

std::string check(int pos_x, int pos_y, int num){
    if (pos_x == 0 or pos_y == num - 1) return "right_up";
    if (pos_x == num - 1 or pos_y == 0) return "left_down";
    return "none";
}

int main(){
    int num;
    std::cin >> num;

    std::vector<std::vector<int>> list;
    for (int i = 0; i < num; ++i) {
        std::vector<int> temp_vec;
        for (int j = 0; j < num; ++j) {
            int temp;
            std::cin >> temp;
            temp_vec.push_back(temp);
        }
        list.push_back(temp_vec);
    }
    int x = 0, y = 0;
    bool second = false;
    std::string direction = "left_down";
    for (int k = 0; k < num * num; ++k) {
//        std::pair<int, int> pos(x, y);
        std::cout << list[y][x] << " ";
        if (x==0 and y==0) {
            x++;
            second = true;
        }
        else if (check(x, y, num) == "right_up" and !second) {
            second = true;
            direction = "right_up";
            if (y == num - 1) x++;
            else if (x == 0) y++;
        }
        else if (check(x, y, num) == "left_down" and  !second){
            second = true;
            direction = "left_down";
            if (x == num - 1) y++;
            else if (y == 0) x++;
        }
        else{
            second = false;
            if (direction == "right_up") {x++; y--;}
            if (direction == "left_down") {x--; y++;}
        }
//        std::cout<<second<<" ";
    }
    return 0;
}