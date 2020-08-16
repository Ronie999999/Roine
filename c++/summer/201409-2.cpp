#include <iostream>


int main(){
    int paper[100][100] = {0};
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j < x2; ++j) {
            for (int k = y1; k < y2; ++k) {
                paper[j][k] = 1;
            }
        }
    }
    int count = 0;
    for (int l = 0; l < 100; ++l) {
        for (int i = 0; i < 100; ++i) {
            if (paper[l][i] == 1) count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}