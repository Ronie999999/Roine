#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void sort(vector<float>&num) {
    for (int i = 0; i < num.size(); i++) { //控制n-1趟冒泡
        for (int j = 0; j < num.size() - 1 - i; j++) {
            if (num[j]- num[j+1] > 0) { //比较相邻的两个元素
                swap(num[j], num[j+1]);
            }
        }
    }
    for (int m = 0; m < num.size(); ++m) {
        cout << num[m] << endl;
    }
}
int main() {
    ifstream file(R"(E:\c++\homework10\a.txt)");
    vector<string>str;
    vector<float>num;
    string str_temp;
    string temp;
    int start = 0;
    getline(file,str_temp);
    for (int i = 0; i < str_temp.length(); ++i) {
        if (str_temp[i] == 32){
            temp = str_temp.substr(start,i - start);
            str.push_back(temp);
            start = i + 1;
        }
    }
//    for (int m = 0; m < str.size(); ++m) {
//        cout << str[m] << endl;
//    }
    str.push_back(str_temp.substr(start));
    cout << str.size() << endl;
    for (int l = 0; l < str.size(); ++l) {
        float a;
        stringstream ss;
        ss << str[l];
        ss >> a;
        num.push_back(a);
    }
//    for (int m = 0; m < num.size(); ++m) {
//        cout << num[m] << endl;
//    }

    sort(num);
    file.close();
    ofstream write_in(R"(E:\c++\homework10\b.txt)",ios::out);
    for (int k = 0; k < str.size(); ++k) {
        write_in << num [k];
        write_in << " ";
    }
    write_in.close();

}
