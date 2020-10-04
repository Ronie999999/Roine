//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//template <typename T>
//struct node
//{
//    T data;
//    node<T> * next;
//};
//
//
//
//template <typename T>
//class linkedList
//{
//public:
//    linkedList();//构造函数
//    virtual ~linkedList();//析构函数，注意要链表中所有节点的资源
//    void insert( T value );//警告：必须初始化才能使用！
//    bool initiate();//初始化单链表，使用new操作创建头结点。如果创建失败，则返回false，否则返回true
//    bool isEmpty();//判断单链表是否为空
//    //删除单链表中第pos个元素结点，并将删除的节点的值存在value中。
//    //注意：如果链表为空、删除位置大于链表长度、以及删除位置为0的情况，需要终止删除并输出相应信息
//    bool remove( int pos, T& value );
//    void print();//顺序打印单链表，如果是单链表为空，则输出 Empty
//    int Length();//返回单链表长度。如果是单链表为空，则返回-1
//private:
//    node<T> *head;
//    int len;
//};
//
//
//template <typename T>
//linkedList<T>::linkedList(){}
//
//template <typename T>
//linkedList<T>::~linkedList() {
//    node<T> *temp;
//    while (true){
//        if (head->next == nullptr) {
//            free(head);
//            break;
//        }
//        else{
//            temp=head->next;
//            free(head);
//            head = temp;
//        }
//    }
//}
//
//template <typename T>
//void linkedList<T>::print()
//{
//    if( isEmpty() )
//    {
//        cout << "Empty" << endl;
//        return;
//    }
//    node<T>* tmp = head->next;
//    while(tmp)
//    {
//        cout <<tmp->data << " ";
//        tmp = tmp->next;
//    }
//    cout << endl;
//}
//template <typename T>
//bool linkedList<T>::initiate() {
//    len = 0;
//    head = new node<T>;
//    head->next = nullptr;
//    return true;
//}
//template <typename T>
//void linkedList<T>::insert(T value) {
//    len++;
//    node<T> *temp = head;
//    while (true){
//        if(temp->next == nullptr) {
//            auto *p = (node<T> *)malloc(sizeof(node<T>));
//            p->data = value;
//            p->next = nullptr;
//            temp->next = p;
//            break;
//        }
//        else{
//            temp = temp->next;
//        }
//    }
//}
//template <typename T>
//bool linkedList<T>::isEmpty() {
//    return head->next == nullptr;
//}
//template <typename T>
//int linkedList<T>::Length() {
//    return len;
//}
//template <typename T>
//bool linkedList<T>::remove(int pos, T &value) {
//    if(pos > len){
//        cout << "pos > len, failed" << endl;
//        return false;
//    }
//    else if(pos <= 0){
//        cout << "pos <= 0, failed" << endl;
//        return false;
//    }
//    else {
//        len--;
//        node<T> *temp = head, *t;
//        int num = 0;
//        while (true) {
//            num++;
//            if (num == pos) break;
//            temp = temp->next;
//        }
//        t = temp->next;
//        value = t->data;
//        temp->next = temp->next->next;
//
//        free(t);
//        return true;
//    }
//}
//
//int main(int argc, char* argv[])
//{
//    linkedList<double> L1;
//    int n;
//    double val;
//    //初始化链表
//    if(!L1.initiate())
//        return 0;
//
//    cin>>n;//输入链表中数据个数
//    for(int i=0; i<n; i++) //输入n个数，并插入链表
//    {
//        cin>>val;
//        L1.insert(val);
//    }
//    cout << "Origin Length:" << L1.Length() << endl;//输出链表长度
//    cout << "data:" ;
//    L1.print();//打印链表
//
//    cin>>n;//输入需要删除的数据的位置
//    if (L1.remove(n,val))
//    {
//        //删除位置n的数据，并将删除的数据值放在val中
//        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
//        cout<< "New Length:" << L1.Length()<< endl;//输出链表长度
//        cout<< "data:" ;
//        L1.print();//打印链表
//    }
//    return 0;
//}
#include <iostream>
#include <iomanip>
using namespace std;
template<class T>
struct node
{
    T  data;
    node<T> *next;
};
template<class T>
class linkedList
{
public:
    linkedList();
    virtual ~linkedList();
    void insert( T value );
    bool initiate();
    bool isEmpty();
    bool remove( int pos, T& value );
    void print();
    int Length();
private:
    node<T> *head;
    int len;

};
template<class T>
bool linkedList<T>::initiate()
{
    head= (node<T>*)malloc(sizeof(node<T>));
    head->next = nullptr;
    return head != nullptr;
}
template<class T>
linkedList<T>::linkedList()
{
    head= (node<T>*)malloc(sizeof(node<T>));
    len=0;
}
template<class T>
linkedList<T>::~linkedList()
{

}
template<class T>
void linkedList<T>::insert(T value)
{
    len++;
    node<T> *p=head;
    while(true)
    {
        if(p->next==nullptr)
        {
            auto*tem= (node<T>*)malloc(sizeof(node<T>));
            tem->data=value;
            tem->next=nullptr;
            p->next=tem;
            break;

        }
        else
        {
            p=p->next;
        }
    }


}


template<class T>
bool  linkedList<T>::isEmpty()
{
    return head->next == nullptr;

}
template<class T>
bool  linkedList<T>::remove(int pos, T& value)
{
    if(head->next==nullptr||pos==0)
    {
        cout<<"pos <= 0, failed"<<endl;
        return false;
    }
    else if(pos>len)
    {
        cout<<"pos > len, failed"<<endl;
        return false;
    }
    else
    {
        node<T> *p=head;
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        node<T> *tem=p->next;
        p->next=tem->next;
        value=tem->data;
        free(tem);
        len=len-1;
        return true;
    }


}
template<class T>
int  linkedList<T>::Length()
{
    return len;
}

//成员函数print
template<class T>
void  linkedList<T>::print()
{
    if( isEmpty() )
    {
        cout << "Empty" << endl;
        return;
    }
    node<T>* tmp = head->next;
    while(tmp)
    {
        cout <<tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    linkedList<int> L1;
    int n;
    int val;
    //初始化链表
    if(!L1.initiate())
        return 0;

    cin>>n;//输入链表中数据个数
    for(int i=0; i<n; i++) //输入n个数，并插入链表
    {
        cin>>val;
        L1.insert(val);
    }
    cout << "Origin Length：" << L1.Length() << endl;//输出链表长度
    cout << "data：" ;
    L1.print();//打印链表

    cin>>n;//输入需要删除的数据的位置
    if (L1.remove(n,val))
    {
        //删除位置n的数据，并将删除的数据值放在val中
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length：" << L1.Length()<< endl;//输出链表长度
        cout<< "data：" ;
        L1.print();//打印链表
    }

    return 0;
}
