#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
bool has7(int num){
    std::string str = std::to_string(num);
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] - 48 == 7) return true;
    }
    return false;
}

int main(){
    int num, count = 0, pos = 1;
    std::cin >> num;
    std::map<char, int> map;
    for (int i = 0; i < 4; ++i) {
        map.insert(std::pair<char,int>('a' + i, 0));
    }
    while (true){
        if (count == num) break;
        if (pos % 4 == 1 and (pos % 7 == 0 or has7(pos))) map['a']++;
        else if (pos % 4 == 2 and (pos % 7 == 0 or has7(pos))) map['b']++;
        else if (pos % 4 == 3 and (pos % 7 == 0 or has7(pos))) map['c']++;
        else if (pos % 4 == 0 and (pos % 7 == 0 or has7(pos))) map['d']++;
        else count++;
        pos++;
    }
    for (int j = 0; j < 4; ++j) {
        std::cout << map['a' + j] << std::endl;
    }
    return 0;
}
