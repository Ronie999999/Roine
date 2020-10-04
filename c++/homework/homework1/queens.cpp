#include <iostream>
using namespace std;

int check(int pos_raw,int pos_line, int list[8][8])
{
    //判断列
    for (int i = 0; i < 8; ++i)
    {
        if (pos_raw == i) continue;
        else
        if (list[i][pos_line] == 1)
        {
            return 0;
        }
    }
    //判断对角线
    int pos_x[4] = {pos_raw, pos_raw, pos_raw, pos_raw};
    int pos_y[4] = {pos_line, pos_line, pos_line, pos_line};
    while (true)
    {
        if (pos_x[0] != 0 and pos_y[0] != 0){
            pos_x[0] -= 1;pos_y[0] -= 1;
            if (list[pos_x[0]][pos_y[0]] == 1) return 0;
        }
        if (pos_x[1] != 7 and pos_y[1] != 7) {
            pos_x[1] += 1;pos_y[1] += 1;
            if (list[pos_x[1]][pos_y[1]] == 1) return 0;
        }
        if (pos_x[2] != 0 and pos_y[2] != 7) {
            pos_x[2] -= 1;pos_y[2] += 1;
            if (list[pos_x[2]][pos_y[2]] == 1) return 0;
        }
        if (pos_x[3] != 7 and pos_y[3] != 0) {
            pos_x[3] += 1;pos_y[3] -= 1;
            if (list[pos_x[3]][pos_y[3]] == 1) return 0;
        }
        if ((pos_x[0] == 0 or pos_y[0] == 0) and (pos_x[1] == 7 or pos_y[1] == 7) and
            (pos_x[2] == 0 or pos_y[2] == 7) and (pos_x[3] == 7 or pos_y[3] == 0)) break;
    }
    return 1;
}

int main() {
    int list[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0}};
    char pos_line[8]; int raw;
    cin >> pos_line;
    for (int i = 0; i < 8; ++i) {
        if (pos_line[i] == '*') continue;
        list[i][pos_line[i] - 49] = 1;
    }
    for (int i = 0; i < 8; ++i) if (pos_line[i] == '*') raw = i;
    for (int j = 0; j < 8; ++j) {
        if (check(raw, j, list) == 1){
            cout<<(j + 1)<<endl;
            break;
        }
        if (j == 7) cout<<"No Answer"<<endl;
    }



}