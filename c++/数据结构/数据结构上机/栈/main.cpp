#include <iostream>
#include "map"
#include "vector"
#include "sstream"
#include "stack.h"

typedef std::string elemType;
// >:1 <:-1 =:0
int priority(char a, char b){
    int p[7][7] = {{1,  1, -1, -1, -1,  1,  1},
                   {1,  1, -1, -1, -1,  1,  1},
                   {1,  1,  1,  1, -1,  1,  1},
                   {1,  1,  1,  1, -1,  1,  1},
                   {-1,-1, -1, -1, -1,  0,  2},
                   {1,  1,  1,  1, 2,  1,  1},
                   {-1,-1, -1, -1, -1, 2,  0}};
    std::map<char,int> map;
    char list[] = {'+', '-', '*', '/', '(', ')', '#'};
    for (int i = 0; i < 4; ++i) {
        std::pair<char, int> temp{list[i],i};
        map.insert(temp);
    }
    return p[map[a]][map[b]];
}

void calculate_middle(){
    stack stack_num, stack_operator;
    stack_operator.push("#");
    std::vector<std::string> list;
    std::string a;
    while(true){
        std::cin >> a;
        if (a == "q") break;
        list.push_back(a);
    }
    for (int i = 0; i < list.size(); ++i) {
        int m = atoi(list[i].c_str());
        if (m) stack_num.push(list[i]);
        else{
            if (list[i] == "(") stack_operator.push("(");
            else if (list[i] == ")") {
                while (true){
                    if (stack_operator.getTop() == "(") {
                        stack_operator.pop();
                        break;
                    }
                    std::string operator_; int num_a, num_b;
                    num_a = atoi(stack_num.getTop().c_str());
                    stack_num.pop();
                    num_b = atoi(stack_num.getTop().c_str());
                    stack_num.pop();
                    operator_ = stack_operator.getTop();
                    stack_operator.pop();
//                    std::cout << num_b << " "<<num_a << std::endl;
                    if (operator_ == "*") stack_num.push(std::to_string(num_b * num_a));
                    else if (operator_ == "/") stack_num.push(std::to_string(num_b / num_a));
                    else if (operator_ == "-") stack_num.push(std::to_string(num_b - num_a));
                    else if (operator_ == "+")
                        stack_num.push(std::to_string(num_b + num_a));
//                    std::cout <<"q"<< stack_num.getTop() << " ";
                }
            }
            else{
//                std::cout << list[i] << stack_operator.getTop()<< std::endl;
                if (priority(list[i][0], stack_operator.getTop()[0]) == 1) stack_operator.push(list[i]);
                else if (priority(list[i][0], stack_operator.getTop()[0]) <= 0) {
                    while (true){
                        if (priority(list[i][0], stack_operator.getTop()[0]) == 1 or stack_operator.getTop() == "#") {
                            stack_operator.push(list[i]);
                            break;
                        }
                        std::string operator_; int num_a, num_b;
                        num_a = atoi(stack_num.getTop().c_str());
                        stack_num.pop();
                        num_b = atoi(stack_num.getTop().c_str());
                        stack_num.pop();
                        operator_ = stack_operator.getTop();
                        stack_operator.pop();
//                        std::cout << num_b << num_a << std::endl;
                        if (operator_ == "*") stack_num.push(std::to_string(num_b * num_a));
                        else if (operator_ == "/") stack_num.push(std::to_string(num_b / num_a));
                        else if (operator_ == "-") stack_num.push(std::to_string(num_b - num_a));
                        else if (operator_ == "+") stack_num.push(std::to_string(num_b + num_a));
//                        std::cout <<"q"<< stack_num.getTop() << " ";
                    }
                }
            }
        }
    }
    while (stack_operator.getTop() != "#"){
        std::string operator_; int num_a, num_b;
        num_a = atoi(stack_num.getTop().c_str());
        stack_num.pop();
        num_b = atoi(stack_num.getTop().c_str());
        stack_num.pop();
        operator_ = stack_operator.getTop();
        stack_operator.pop();
//        std::cout << num_b <<" " << num_a << std::endl;
        if (operator_ == "*") stack_num.push(std::to_string(num_b * num_a));
        else if (operator_ == "/") stack_num.push(std::to_string(num_b / num_a));
        else if (operator_ == "-") stack_num.push(std::to_string(num_b - num_a));
        else if (operator_ == "+") stack_num.push(std::to_string(num_b + num_a));
    }

    std::cout << stack_num.getTop() << std::endl;


}

void calculate_front(){
    stack stack_num;
    std::vector<std::string> list;
    std::string a;
    while(true){
        std::cin >> a;
        if (a == "q") break;
        list.push_back(a);
    }
    for (int i = list.size() - 1; i >= 0; --i) {
        int m = atoi(list[i].c_str());
        if (m) stack_num.push(list[i]);
        else{
            std::string a, b, c;
            a = stack_num.getTop();
            stack_num.pop();
            b = stack_num.getTop();
            stack_num.pop();
            int num_a = atoi(a.c_str()), num_b = atoi(b.c_str());
//            std::cout << num_a << " " << num_b << std::endl;
            if (list[i] == "*") stack_num.push(std::to_string(num_b * num_a));
            else if (list[i] == "/") stack_num.push(std::to_string(num_a / num_b));
            else if (list[i] == "-") stack_num.push(std::to_string(num_a - num_b));
            else if (list[i] == "+") stack_num.push(std::to_string(num_b + num_a));
        }
    }
    std::cout << stack_num.getTop() << std::endl;
}

void calculate_back(){
    stack stack_num;
    std::vector<std::string> list;
    std::string a;
    while(true){
        std::cin >> a;
        if (a == "q") break;
        list.push_back(a);
    }
    for (int i = 0; i < list.size(); ++i) {
        int m = atoi(list[i].c_str());
        if (m) stack_num.push(list[i]);
        else{
            std::string a, b, c;
            a = stack_num.getTop();
            stack_num.pop();
            b = stack_num.getTop();
            stack_num.pop();
            int num_a = atoi(a.c_str()), num_b = atoi(b.c_str());
//            std::cout << num_a << " " << num_b << std::endl;
            if (list[i] == "*") stack_num.push(std::to_string(num_b * num_a));
            else if (list[i] == "/") stack_num.push(std::to_string(num_b / num_a));
            else if (list[i] == "-") stack_num.push(std::to_string(num_b - num_a));
            else if (list[i] == "+") stack_num.push(std::to_string(num_b + num_a));
        }
    }
    std::cout << stack_num.getTop() << std::endl;
}

void front(){
    stack stack1, stack2;
    std::vector<std::string> list;
    std::string a;
    while(true){
        std::cin >> a;
        if (a == "q") break;
        list.push_back(a);
    }
    for (int i = list.size() - 1; i >= 0; --i) {
        int m = atoi(list[i].c_str());
        if (m) stack2.push(list[i]);
        else if (list[i][0] == ')') stack1.push(list[i]);

        else if (list[i][0] == '(') {
            while (true){
                elemType data = stack1.getTop();
                if (data[0] == ')') {
                    stack1.pop();
                    break;
                }
                stack1.pop();
                stack2.push(data);
            }
        }
        else{
            while (true) {
                if (stack1.stackEmpty() or stack1.getTop()[0] == ')') {
                    stack1.push(list[i]);
                    break;
                }
                else{
                    if (priority(list[i][0],stack1.getTop()[0]) >= 0){
                        stack1.push(list[i]);
                        break;
                    }
                    else{
                        elemType data = stack1.getTop();
                        stack1.pop();
                        if (data[0] != '(') {
                            stack2.push(data);
                        }
                    }
                }
            }
        }
    }
    while (!stack1.stackEmpty()){
        elemType data = stack1.getTop();
        stack1.pop();
        stack2.push(data);
    }
    std::cout << "Prefix expression : ";
    int length = stack2.stackLength();
    for (int i = 0; i < length; ++i) {
        std::cout << stack2.getTop() << " ";
        stack2.pop();
    }
}

void back(){
    stack stack1, stack2;
    std::vector<std::string> list;
    std::string a;
    while(true){
        std::cin >> a;
        if (a == "q") break;
        list.push_back(a);
    }
    for (int i = 0; i < list.size(); ++i) {
        int m = atoi(list[i].c_str());
        if (m) stack2.push(list[i]);
        else if (list[i][0] == '(') stack1.push(list[i]);
        else if (list[i][0] == ')') {
            while (true){
                elemType data = stack1.getTop();
                if (data[0] == '(') {
                    stack1.pop();
                    break;
                }
                stack1.pop();
                stack2.push(data);
            }
        }
        else{
            while (true) {
                if (stack1.stackEmpty() or stack1.getTop()[0] == '(') {
                    stack1.push(list[i]);
                    break;
                }
                else{
                    if (priority(list[i][0],stack1.getTop()[0]) >= 0){
                        stack1.push(list[i]);
                        break;
                    }
                    else{
                        elemType data = stack1.getTop();
                        stack1.pop();
                        if (data[0] != ')') {
                            stack2.push(data);
                        }
                    }
                }
            }
        }
    }
    while (!stack1.stackEmpty()){
        elemType data = stack1.getTop();
        stack1.pop();
        stack2.push(data);
    }
    int length = stack2.stackLength();
    std::string str;
    for (int i = 0; i < length; ++i) {
        str.append(stack2.getTop());
        stack2.pop();
    }
    std::cout << "Postfix Expression : ";
    for (int i = str.size() - 1; i >= 0 ; --i) {
        std::cout << str[i] << " ";
    }
}

int main() {
    std::cout << "Input infix expression: ";
    front();
    std::cout << std::endl;
    std::cout << "Input infix expression: ";
    back();
    std::cout << std::endl;
    std::cout << "Input prefix expression: ";
    calculate_front();
    std::cout << "Input infix expression: ";
    calculate_middle();
    std::cout << "Input postfix Expression: ";
    calculate_back();
}

//  9*8+(14-8/2)*3

//stack.cpp stack.h

//( 1 + 2 * ( 3 + 4 ) ) / 5 * ( 7 - 6 )

// 1 + ( 2 + 3 ) * 4 - 5

// 2 * ( 6 - 4 ) + 8 / 4