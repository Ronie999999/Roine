#include <iostream>
using namespace std;

int main() {
    int matrix1[9], matrix2[9], matrix3[9];
    for (int i = 0; i < 9; ++i) {
        scanf("%d",&matrix1[i]);
    }
    for (int i = 0; i < 9; ++i) {
        scanf("%d",&matrix2[i]);
    }
    int raw = 0, line = 0;
    for (int j = 0; j < 9;++j) {
        if (line == 3) {
            line = 0;
            raw += 3;
        }
        matrix3[j] = matrix1[raw] * matrix2[line] + matrix1[raw + 1] * matrix2[line + 3] +matrix1[raw + 2] * matrix2[line + 6];
        line++;
    }
    for (int m = 0; m < 9; ++m) {
        cout<<matrix3[m];
        if ((m + 1) % 3 == 0) cout<<endl;
        else
            cout<<" ";
    }

}