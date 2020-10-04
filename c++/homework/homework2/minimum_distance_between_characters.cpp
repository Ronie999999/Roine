#include <iostream>
#include <string>
using namespace std;

int main() {
    int num = 57, temp;
    string list_A, list_B;
    cin >> list_A; cin >> list_B;
    for (char & i : list_A) {
        if (i > 64 and i < 91)
            i += 32;
    }
    for (char & k : list_B) {
        if (k > 64 and k < 91)
            k += 32;
    }
    for (char j : list_A) {
        for (char i : list_B) {
            temp = abs(j - i);
            if (temp < num) num = temp;
        }
    }
    cout << num;
}
