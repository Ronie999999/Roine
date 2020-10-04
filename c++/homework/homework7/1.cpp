#include  <iostream>
using  namespace  std;
class  Book
{
//���ڴ˴�����Book��Ķ���
private:
    unsigned int m_ID;//���
    string m_Name;//����
    string m_Introductio; //���
    string m_Author;//����
    string m_Date;//����
    unsigned int m_Page;//ҳ��
public:
    Book(const Book& other){
        this -> m_ID = other.m_ID;
        this -> m_Page = other.m_Page;
        this -> m_Date = other.m_Date;
        this -> m_Introductio = other.m_Introductio;
        this -> m_Author = other.m_Author;
        this -> m_Name = other.m_Name;
    };//ʵ�����г�Ա�����Ŀ���
    Book(){
        this -> m_ID = 0;
    }
    void SetID(int id){
        this -> m_ID = id;
    }
    void SetName(string name){
        this -> m_Name = name;
    }
    void SetAuthor(string author){
        this -> m_Author = author;
    }
    void SetIntroduction(string introduction){
        this -> m_Introductio = introduction;
    }
    void SetDate(string date){
        this -> m_Date = date;
    }
    void SetPage(int page){
        this -> m_Page = page;
    }
    string get_name(){
        return this -> m_Name;
    }
    int GetID(){
        return m_ID;
    }
    string GetName(){
        return m_Name;
    }
    string get_author(){
        return m_Author;
    }
    string getdate(){
        return m_Date;
    }

};


//���ڴ˴�����Book��ĳ�Ա����ʵ��

class  Store
{
//���ڴ˴�����Store��Ķ���
public:
    void in(Book &b);
    Store();
    Book findbyName(string name);
    Store(int n);
    ~Store();
    Store(const Store& other);
    void set_m_count(int n);
    int GetCount();
    void out(string name);
    Book findbyID(int id);
    void printList();
private:
    int total = 0;
    Book *temp;
    Book *m_pBook;//ָ������new������̬������Book����
    unsigned int m_Count;//��ʾ�����ͼ�������
};


//���ڴ˴�����Store��ĳ�Ա����ʵ��
int Store::GetCount() {
    return this -> m_Count;
}

void Store::set_m_count(int n) {
    this -> m_Count = n;
}

Store::Store() {
    this -> m_Count = 0;
    m_pBook = nullptr;
    cout << "Store default constructor called!" << endl;
}

Store::Store(int n) {
    this -> m_Count = n;
    this -> m_pBook = new Book[n];
    cout << "Store constructor with (int n) called!" << endl;
}

Store::~Store() {
    this -> m_Count = 0;
    if (m_pBook != nullptr){
        delete[] m_pBook;
    }
    cout << "Store destructor called!" << endl;
}

Store::Store(const Store &other) {
    this -> m_pBook = other.m_pBook;
    this -> m_Count = other.m_Count;
}

void Store::in(Book &b) {
    temp = new Book[m_Count + 1];
    int i = 0;
    for (; i < m_Count; ++i) {
        temp[i] = m_pBook[i];
//        cout << temp[i].GetID() << endl;
    }
    temp[i] = b;
    m_pBook = temp;
    m_Count += 1;
    total += 1;
}

Book Store::findbyName(string name) {
    Book *t = nullptr;
    for (int i = 0; i < total; ++i) {
        if (m_pBook[i].get_name() == name) return m_pBook[i];
    }
    return *t;
}

void Store::out(string name) {
    for (int i = 0; i < total; ++i) {
//        cout << m_pBook[i].GetID() << endl;
        if (m_pBook[i].get_name() == name)
            m_pBook[i].SetID(0);
    }
//    this -> findbyName(name).SetName("");
    m_Count--;
}

Book Store::findbyID(int id) {
    Book *t = nullptr;
    for (int i = 0; i < total; ++i) {
        if (m_pBook[i].GetID() == id) return m_pBook[i];
    }
    return *t;
}

void Store::printList() {
    cout << "There are totally " << m_Count << " Books:" << endl;
    for (int i = 0; i < total; ++i) {
//        cout << m_pBook[i].GetID() << endl;
        if (m_pBook[i].GetID() == 0) continue;
        cout << "ID=" << m_pBook[i].GetID() << ";  ";
        cout << "Name:" << m_pBook[i].get_name() << ";  ";
        cout << "Author:" << m_pBook[i].get_author() << ";  ";
        cout << "Date:" << m_pBook[i].getdate() << ";" << endl;
    }
}

int  main()
{
    Store  s;
    Book  b1,b2,b3;
    b1.SetID(1);
    b1.SetName("C++  ���Գ������(��4��)");
    b1.SetAuthor("֣��");
    b1.SetIntroduction("����C++����������֪ʶ");
    b1.SetDate("201007");
    b1.SetPage(529);
    b2.SetID(2);
    b2.SetName("��ɢ��ѧ");
    b2.SetAuthor("��Т��");
    b2.SetIntroduction("���������߼���ν���߼��������ۡ�����ϵͳ��ͼ��");
    b2.SetDate("198209");
    b2.SetPage(305);
    b3.SetID(3);
    b3.SetName("c�������");
    b3.SetAuthor("̷��ǿ");
    b3.SetIntroduction("����C��������еĻ���֪ʶ��������ʽ���﷨��");
    b3.SetDate("201006");
    b3.SetPage(355);

    cout<<"��һ�������"<<endl;
    s.in(b1);
    cout<<"�ڶ��������"<<endl;
    s.in(b2);
    cout<<"�����������"<<endl;
    s.in(b3);
    cout  <<"���п���鼮������"<<s.GetCount()  <<  endl;
    cout  <<"���Ҳ�����ͼ�飺��ɢ��ѧ"  <<  endl;
    Book  tmpbook=s.findbyName("��ɢ��ѧ");
    if(tmpbook.GetID()!=0)
    {
        s.out("��ɢ��ѧ");
        cout  <<"��ɢ��ѧ  �ѳɹ�����"  <<  endl;
    }
    else
        cout<<"û���ҵ�nameΪ��ɢ��ѧ����"<<endl;
    cout  <<"���п���鼮������"<<s.GetCount()  <<  endl;
    cout  <<"����ͼ��  ID��3"  <<  endl;


    tmpbook=s.findbyID(3);
    if(tmpbook.GetID()!=0)
        cout<<"�ҵ�IDΪ"<<3<<"���飬������"<<tmpbook.GetName()<<endl;
    else
        cout<<"û���ҵ�IDΪ"<<3<<"����"<<endl;


    cout  <<"����ͼ��  name����ɢ��ѧ"  <<  endl;
    tmpbook=s.findbyName("��ɢ��ѧ");
    if(tmpbook.GetID()!=0)
        cout<<"�ҵ�nameΪ��ɢ��ѧ���飬ID��"<<tmpbook.GetID()<<endl;
    else
        cout<<"û���ҵ�nameΪ��ɢ��ѧ����"<<endl;

    cout<<"������п��ͼ�����Ϣ"<<endl;
    s.printList();
    cout<<"�������н���"<<endl;
    return  0;
}