#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
int main(){
    int m, n;
    std::cin >> m >> n;
//    int list[m][n];
    std::vector<std::vector<int>> l;
    for (int i = 0; i < m; ++i) {
        std::vector<int> temp_vec;
        for (int j = 0; j < n; ++j) {
//            std::cin >> list[i][j];
            int temp;
            std::cin >> temp;
            temp_vec.push_back(temp);
        }
        l.push_back(temp_vec);
    }
    for (int k = n - 1; k >= 0; --k) {
        for (int i = 0; i < m; ++i) {
            std::cout << l[i][k] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}