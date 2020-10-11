#include <iostream>
#include <iomanip>
#include <exception>

#include "vector"
using namespace std;


typedef char elementType;
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
    int str1_num, str2_num;
    std::cin >> str1_num >> str2_num;
    linkedList str1 ,str2;
    for (int i = 0; i < str1_num; ++i) {
        char temp;
        std::cin >> temp;
        str1.insert(temp);
    }
    for (int i = 0; i < str2_num; ++i) {
        char temp;
        std::cin >> temp;
        str2.insert(temp);
    }
    std::string a;
    for (int j = str1_num - 1, i = str2_num - 1; j >= 0 and i >= 0; --j, --i) {
        char s1, s2;
        str1.getelem(j, s1);
        str2.getelem(i, s2);
        if (s1 == s2) a.append(1, s1);
        else break;
    }
    for (int k = a.size() - 1; k >= 0; --k) {
        std::cout << a[k];
    }

    return 0;
}


//7 5
//loading
//being
