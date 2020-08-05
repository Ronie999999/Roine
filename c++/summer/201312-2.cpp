#include "iostream"
#include "string"
#include "vector"
int main(){
    std::string str, str2;
    std::vector<std::string> list;
    long long int number = 0;
    std::cin >> str;
//    std::cout << str << std::endl;
    int end, start = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == 45) {
            std::string temp;
            end = i;
            for (start; start < end; start++) {
                temp.append(1, str[start]);
            }
            list.push_back(temp);
            start++;
        }
    }
    list.push_back(str.substr(start));

    for (int j = 0; j < 3; ++j) {
        str2.append(list[j]);
    }
    for (int k = 0; k < str2.length(); ++k) {
        number += (str2[k] - 48) * (k + 1);
    }
//    std::cout << number % 11 << "  " << str[str.length() - 1] - 48 << std::endl;
    if (number % 11 == str[str.length() - 1] - 48 or number % 11 == str[str.length() - 1] - 78){
        std::cout << "Right" << std::endl;
    } else{
        std::string temp;
        for (int i = 0; i < 3; ++i) {
            temp.append(list[i]);
            temp.append(1, '-');
        }
        if (number % 11 == 10){
            temp.append(1, 'X');
        } else
            temp.append(1,(number % 11) + 48);
        std::cout << temp << std::endl;
    }
    return 0;
}