//
// Created by ren on 2020/10/27.
//

#include "iostream"

#ifndef C___STACK_H
#define C___STACK_H

typedef std::string elemType;
class stack{
public:
    explicit stack();
    bool pop();
    bool push(elemType e);
    int stackLength();
    bool stackEmpty();
    elemType getTop();
    bool increase();

private:
    int top;
    elemType *p;
    int init_size = 20;
    int increase_size = 10;
    int size;
};


#endif //C___STACK_H
