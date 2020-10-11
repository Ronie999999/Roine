#include <iostream>
#include <iomanip>
#include <exception>

#include "vector"
using namespace std;


typedef int elementType;
typedef struct node
{
    elementType data;
    node* next;
} LList, *PList;

class linkedList
{
public:
    linkedList();
    virtual ~linkedList();
    void insert(elementType value );
    bool isEmpty();
    bool getelem(int pos, elementType &value);
    bool remove( int pos, elementType &value );
    void print();
    int Length();
private:
    LList *head;
    int len;
};

linkedList::linkedList(){
    len = 0;
    head = new node;
    head->next = nullptr;
}

linkedList::~linkedList() {
    node *temp;
    while (true){
        if (head->next == nullptr) {
            free(head);
            break;
        }
        else{
            temp=head->next;
            free(head);
            head = temp;
        }
    }
}

void linkedList::print()
{
    if( isEmpty() )
    {
        cout << "Empty" << endl;
        return;
    }
    LList* tmp = head->next;
    while(tmp)
    {
        cout <<tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void linkedList::insert(elementType value) {
    len++;
    node *temp = head;
    while (true){
        if(temp->next == nullptr) {
            node *p = (PList)malloc(sizeof(LList));
            p->data = value;
            p->next = nullptr;
            temp->next = p;
            break;
        }
        else{
            temp = temp->next;
        }
    }
}

bool linkedList::isEmpty() {
    return head->next == nullptr;
}

int linkedList::Length() {
    return len;
}

bool linkedList::remove(int pos, elementType &value) {
    if(pos > len){
        cout << "pos > len, failed" << endl;
        return false;
    }
    else if(pos <= 0){
        cout << "pos <= 0, failed" << endl;
        return false;
    }
    else {
        len--;
        node *temp = head, *t;
        int num = 0;
        while (true) {
            num++;
            if (num == pos) break;
            temp = temp->next;
        }
        t = temp->next;
        value = t->data;
        temp->next = temp->next->next;
        free(t);
        return true;
    }
}

bool linkedList::getelem(int pos, elementType &value) {
    if (pos > len or pos < 0) return false;
    node *p = head->next;
    int pos_ = 0;
    while (true){
        if (pos_ == pos) {
            value = p->data;
            break;
        }
        pos_++;
        p = p->next;

    }
    return true;
}


int main(int argc, char* argv[])
{
    int num, max, min;
    linkedList list;
    std::cin >> num;
    for (int i = 0; i < num; ++i) {
        int temp;
        std::cin >> temp;
        list.insert(temp);
    }
    std::cin >> min >> max;
    for (int j = num; j > 0; --j) {
        int value;
        list.getelem(j - 1, value);
        if (min <= value and value <= max){
            list.remove(j,value);
        }
    }
    list.print();
    return 0;
}
//5
//1 2 3 4 5
//1 4
