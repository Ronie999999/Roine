#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"
#include "iomanip"
#include <stack>
#include "unordered_map"

int main(){
    std::ios::sync_with_stdio(false);
    int n, a, b;
    std::cin >> n >> a >> b;
    std::unordered_map<int, int> first_map;
    std::unordered_map<int, int> second_map;
    for (int i = 0; i < a; ++i) {
        int temp1, temp2;
        std::cin >> temp1 >> temp2;
        first_map[temp1] = temp2;
    }
    for (int i = 0; i < b; ++i) {
        int temp1, temp2;
        std::cin >> temp1 >> temp2;
        second_map[temp1] = temp2;
    }
    long long int total = 0;
    for (auto it = first_map.begin(); it != first_map.end(); it++) {
        auto i = second_map.find(it->first);
        if (i == second_map.end()) continue;
        else{
            total += it->second * i->second;
        }
    }
    std::cout << total << std::endl;
    return 0;
}