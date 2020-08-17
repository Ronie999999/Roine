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
    long long int r, y, g, num;
    long long int time = 0;
    std::cin >> r >> y >> g >> num;
    long long int sum = r + y + g;
    std::vector<std::pair<long long int, long long int>> list;
    for (int i = 0; i < num; ++i) {
        long long int a, b;
        std::cin >> a >> b;
        list.emplace_back(a, b);
    }
    for (auto it = list.begin(); it != list.end(); it++) {
        if (it->first == 0) time += it->second;
        else if (it->first == 1) {
            long long int temp = time + r - it->second;
            long long int light = temp % sum;
            if (light >= 0 and light < r) time += r - light;
            else if (light >= r and light < r + g) time += 0;
            else if (light >= r + g and light < sum) time += sum - light + r;
        }
        else if (it->first == 2) {
            long long int temp = time + r + g + y - it->second;
            long long int light = temp % sum;
            if (light >= 0 and light < r) time += r - light;
            else if (light >= r and light < r + g) time += 0;
            else if (light >= r + g and light < sum) time += sum - light + r;
        }
        else if (it->first == 3){
            long long int temp = time + r + g - it->second;
            long long int light = temp % sum;
            if (light >= 0 and light < r) time += r - light;
            else if (light >= r and light < r + g) time += 0;
            else if (light >= r + g and light < sum) time += sum - light + r;
        }
    }
    std::cout << time;
    return 0;
}
