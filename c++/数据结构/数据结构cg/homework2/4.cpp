#include "iostream"

class list{
public:
    bool InitList(int *p, int l);
    bool DestoryList();
    bool ListEmpty() const;
    bool GetElem(int pos, int &data);
    bool ListInsert(int pos, int data);
    bool DeleteElem(int pos, int &data);
    int ListLength() const;
    bool change(int pos, int value);
    void print();

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

bool list::ListEmpty() const {
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

int list::ListLength() const{
    return length;
}

bool list::change(int pos, int value) {
    elem[pos - 1] = value;
    return true;
}

void list::print() {
    for (int k = 0; k < length; ++k) {
        std::cout << elem[k] << " ";
    }
}

int main() {
    int num;
    list l;
    l.InitList();
    std::cin >> num;
    for (int i = 0; i < num; ++i) {
        int temp;
        std::cin >> temp;
        l.ListInsert(i+1, temp);
    }
//    l.print();
    int value1, value2;
    for (int j = 1, i = l.ListLength(); ; ++j, --i) {
        if (l.ListLength() % 2 == 0){
            if (i + 1 == j) break;
        } else if (i == j) break;
        l.GetElem(j, value1);
        l.GetElem(i, value2);
        l.change(i, value1);
        l.change(j, value2);
    }
    l.print();
    return 0;
}


//5
//1 2 3 4 5