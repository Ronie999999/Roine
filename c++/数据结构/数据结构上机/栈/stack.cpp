//
// Created by ren on 2020/10/27.
//

#include "stack.h"
stack::stack() {
    p = (std::string *)calloc(init_size,sizeof(std::string));
    this->top = -1;
    this->size = init_size;
}

bool stack::pop() {
    if (top < 0) return false;
    else{
        p[top] = '\0';
        top--;
    }
//    std::cout << "pop success   ";
    return true;
}
bool stack::push(elemType e) {
//    std::cout << e << " ";
    if (top + 1 >= this->size) this->increase();
    p[++top] = e;
    return true;
}

int stack::stackLength() {
    return top + 1;
}

bool stack::stackEmpty() {
    return top == -1;
}

elemType stack::getTop() {
    return p[top];
}

bool stack::increase() {
    elemType *q = p;
    p = (elemType *)calloc((size + increase_size),sizeof(std::string));
    for (int i = 0; i < top; ++i) {
        p[i] = q[i];
    }
    free(q);
    size = size + increase_size;
    return true;
}