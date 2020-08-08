#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"
int find_pos(int num, std::vector<int> vec){
    for (int i = 0; i < 20; ++i) {
        if (num <= vec[i]) return i;
    }
    return -1;
}

int main(){
    int num;
    std::cin >> num;
    std::vector<int> vec;
    for (int i = 0; i < num; ++i) {
        int temp;
        std::cin >> temp;
        vec.push_back(temp);
    }
    std::vector<std::map<int, bool>> map;
    std::vector<int> list;
    for (int j = 0; j < 20; ++j) list.push_back(5);
    for (int k = 0; k < 20; ++k) {
        std::map<int ,bool> temp;
        for (int i = 0; i < 5; ++i) {
            temp.insert(std::pair<int, bool>(i, false));
        }
        map.push_back(temp);
    }

    for (int l = 0; l < vec.size(); ++l) {
        int pos = find_pos(vec[l], list);
        int count = 0;
        if (pos != -1){
            for (int i = 0; i < 5; ++i) {
                if (!map[pos][i]){
                    std::cout << 5 * pos + i + 1 << " ";
                    map[pos][i] = true;
                    count++;
                    if (count == vec[l]){
                        list[pos] -= count;
                        break;
                    }
                }
            }
        } else{
            bool finish = false;
            for (int i = 0; i < 20; ++i) {
                if (list[i] != 0){
                    for (int j = 0; j < 5; ++j) {
                        if (!map[i][j]) {
                            map[i][j] = true;
                            count++;
                            std::cout << i * 5 + j + 1 << " ";
                            if (count == vec[l]) {
                                finish = true;
                                list[l] -= count;
                                break;
                            }
                        }
                    }
                }
                if (finish) break;
            }
//            std::cout << -1 << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
