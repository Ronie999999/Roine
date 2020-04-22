#include  <iostream>
using  namespace  std;
class Point{
public:
    Point(int a = 0, int b = 0){
        m_x = a;
        m_y = b;
    }

    Point &operator ++() {
        this->m_x++;
        this->m_y++;
        return *this;
    }

    Point operator ++(int) {
        Point temp = *this;
        this->m_x++;
        this->m_y++;
        return temp;
    }

    friend ostream& operator << (ostream&, Point c);

private:
    int m_x;
    int m_y;
};

ostream & operator << (ostream & output, Point c) {
    output<<"("<<c.m_x<<","<<c.m_y<<")"<<endl;
    return output;
}

int  main()
{
    Point  a(1,3);
    cout<<a;
//    Point b = ++a;
    cout << ++a;
    cout << a++;
    return  0;
}
