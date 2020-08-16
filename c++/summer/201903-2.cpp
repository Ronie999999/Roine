#include <iostream>
#include <map>
#include "vector"
#include "iterator"
#include <algorithm>
#include "cmath"
#include "iomanip"
#include <stack>

int main(){
    int num;
    std::cin >> num;
    std::vector<std::string> list;
    for (int i = 0; i < num; ++i) {
        std::string temp;
        std::cin >> temp;
        list.push_back(temp);
    }
    std::stack<int> number;

    for (int k = 0; k < num; ++k) {
        for (int j = 0; j < 7; ++j) {
            if (list[k][j] >= '0' and list[k][j] <= '9') number.push(list[k][j] - 48);
            else{
                if (list[k][j] == '-'){
                    number.push((list[k][++j] - 48)*(-1));
                }
                else if (list[k][j] == 'x'){
                    int temp = number.top() * (list[k][++j] - 48);
                    number.pop();
                    number.push(temp);
                }
                else if (list[k][j] == '/'){
                    int temp = number.top() / (list[k][++j] - 48);
                    number.pop();
                    number.push(temp);
                }
            }
        }
        int total = 0;
        int range = number.size();
        for (int i = 0; i < range; ++i) {
            total += number.top();
            number.pop();
        }
        if (total == 24) std::cout << "Yes" << std::endl;
        else std::cout << "No" << std::endl;
    }
    return 0;
}
