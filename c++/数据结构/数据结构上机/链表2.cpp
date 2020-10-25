#include <iostream>
#include <iomanip>
#include <exception>

#include "vector"
using namespace std;


typedef std::pair<int,int> elementType;
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
    void insert( elementType value );
    bool isEmpty();
    bool getelem(int pos, elementType &value);
    bool remove( int pos, elementType &value );
    void print();
    int Length();
    friend void Plus(linkedList &list1, linkedList &list2);
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
    {   if (tmp->next)
            cout << tmp->data.first << "x" << "^" << tmp->data.second << "+";
        else cout << tmp->data.first << "x" << "^" << tmp->data.second;
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

void Plus(linkedList &list1, linkedList &list2 ) {
    PList p1 = list1.head->next, p2 = list2.head->next;
    linkedList temp;
    PList p3 = temp.head;
    while(p1 and p2){
        if (p1->data.second < p2->data.second){
            p3->next=p1;
            p1=p1->next;
            p3=p3->next;
        }
        else if (p1->data.second > p2->data.second){
            p3->next=p2;
            p2=p2->next;
            p3=p3->next;
        }
        else{
            p1->data.first += p2->data.first;
            if (p1->data.first){
                p3->next=p1;
                p1=p1->next;
                p3=p3->next;
                PList p=p2;
                p2=p2->next;
                free(p);
            }
            else{
                PList p= p1;
                p1=p1->next;
                free(p);
                p=p2;
                p2=p2->next;
                free(p);}
            }
        }
    if (p1) p3->next = p1;
    if (p2) p3->next = p2;
    if (!p1&&!p2) p3->next= nullptr;
    free(p2);
    temp.print();
}

int main(){
    int a, b;
    linkedList list_a;
    linkedList list_b;
    for (int i = 0; i < 4; ++i) {
        std::cin >> a >> b;
        std::pair<int, int> l(a, b);
        list_a.insert(l);
    }
    for (int j = 0; j < 3; ++j) {
        std::cin >> a >> b;
        std::pair<int, int> l(a, b);
        list_b.insert(l);
    }
    Plus(list_b, list_a);
}


//7 0 3 1 9 8 5 17
//8 1 22 7 -9 8