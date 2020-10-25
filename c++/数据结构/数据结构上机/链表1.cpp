#include <iostream>
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
    void insert( int value );
    bool isEmpty();
    bool getelem(int pos, int &value);
    bool remove( int pos, int &value );
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

void linkedList::insert(int value) {
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

bool linkedList::remove(int pos, int &value) {
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

bool linkedList::getelem(int pos, int &value) {
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
    int a[] = {12,90,89,90,23,32,43};
    int b[] = {99,12,34,45,1,33,12,89};
    linkedList list_a, list_b, list_c;
    for (int i = 0; i < 7; ++i) list_a.insert(a[i]);
    for (int i = 0; i < 8; ++i) list_b.insert(b[i]);
    int data1, data2;
    for (int j = 0; j < list_a.Length(); ++j) {
        if (list_a.getelem(j,data1)){
            list_c.insert(data1);
        }
    }
//    list_c.print();
    for (int j = 0; j < list_b.Length(); ++j) {
        if (list_b.getelem(j, data1)) {
            for (int i = 0; i < list_a.Length(); ++i) {
                if (list_a.getelem(i, data2)) {
                    if (data2 == data1) break;
                    if (i == list_a.Length() - 1) {
                        list_c.insert(data1);
                    }
                }
            }
        }
    }
    std::cout << "list_1: ";
    list_a.print();
    std::cout << "list_2: ";
    list_b.print();
    std::cout << "list_3: ";
    list_c.print();

    return 0;
}


