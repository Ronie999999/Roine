#include "iostream"

class list{
public:
    bool InitList(int *p, int l);
    bool DestoryList();
    bool ListEmpty();
    bool GetElem(int pos, int &data);
    bool ListInsert(int pos, int data);
    bool DeleteElem(int pos, int &data);
    int ListLength();

private:
    int *elem;
    int length;
    int size;
    int init_size = 10;
    int increase_size = 5;
};

bool list::InitList(int *p = nullptr, int l = 0) {
    this->elem = (int*)malloc(init_size * sizeof(int));
    size = init_size;
    length = 0;
    if (p){
        if (l > this->init_size){
            free(this->elem);
            this->elem = (int*)malloc(increase_size * ( l / increase_size + 1) * sizeof(int));
            size = increase_size * ( l / increase_size + 1);
        }
        for (int i = 0; i < l; ++i) {
            elem[i] = p[i];
        }
        length = l;
    }
    return true;
}

bool list::DestoryList() {
    free(this->elem);
    return true;
}

bool list::ListEmpty() {
    return !size;
}

bool list::GetElem(int pos, int &data) {
    if (pos > length or pos < 1){
        return false;
    }
    data = elem[pos - 1];
    return true;
}

bool list::ListInsert(int pos, int data) {
    if (pos > length + 1 or pos < 1) {
//        length--;
        return false;
    }
    if (length + 1 > size){
        int *p = this->elem;
        this->elem = (int*)malloc((size + increase_size) * sizeof(int));
        size += increase_size;
        for (int i = 0; i < length; ++i) {
            this->elem[i] = p[i];
        }
        free(p);
    }
    for (int j = length - 1; j > pos - 1; --j) {
        this->elem[j + 1] = this->elem[j];
    }
    length++;
    this->elem[pos - 1] = data;
    return true;
}

bool list::DeleteElem(int pos, int &data) {
    if (pos > length or pos < 1) return false;
    this->elem[pos - 1] = data;
    for (int j = pos; j < length + 1; --j) {
        this->elem[j - 1] = this->elem[j];
    }
    length--;
    return true;
}

int list::ListLength(){
    return length;
}

int main() {
    list a, b, c;
    int q[] = {0, 5, 6, 9, 12, 32, 2, 1, 99};
    int p[] = {1, 32, 12, 6, 58, 22, 33, 44};
    a.InitList(q, 9);
    b.InitList(p, 8);
    c.InitList();
    int data1, data2;
    for (int i = 0; i < a.ListLength(); ++i) {
        if (a.GetElem(i + 1, data1)) c.ListInsert(i + 1, data1);
//        for (int k = 0; k < c.ListLength(); ++k) {
//            std::cout << c.GetElem(k + 1, data1) << " ";
//            std::cout << data1 << std::endl;
//        }

    }

//    std::cout << std::endl;
    for (int j = 0; j < b.ListLength(); ++j) {
        if (b.GetElem(j + 1, data1)) {
//            std::cout << data1 << ":";
            for (int i = 0; i < a.ListLength(); ++i) {
                if (a.GetElem(i + 1, data2)) {
//                    std::cout << data2 << " ";
                    if (data2 == data1) break;
                    if (i == a.ListLength() - 1) {
                        c.ListInsert(c.ListLength() + 1, data1);
                    }
                }
            }
//            std::cout << std::endl;
        }
    }
//    std::cout << c.ListLength() << std::endl;
    std::cout << "list a : ";
    for (int l = 0; l < a.ListLength(); ++l) {
        if (a.GetElem(l + 1, data1)) std::cout << data1 << " ";
    }
    std::cout<<std::endl;
    std::cout << "list b : ";
    for (int l = 0; l < b.ListLength(); ++l) {
        if (b.GetElem(l + 1, data1)) std::cout << data1 << " ";
    }
    std::cout<<std::endl;
    std::cout << "list c : ";
    for (int k = 0; k < c.ListLength(); ++k) {
        if (c.GetElem(k + 1, data1)) std::cout << data1 << " ";
    }
}
