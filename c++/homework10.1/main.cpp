//#include <iostream>
//#include <fstream>
//using namespace std;
//struct student{
//    int stu_id;
//    int score;
//};
//
//int main(){
//    int num_stu;
//    cin >> num_stu;
//    auto *p = new student[num_stu];
//    for (int i = 0; i < num_stu; ++i) {
//        student stu{};
//        cin >> stu.stu_id >> stu.score;
//        p[i] = stu;
//    }
//
//    ofstream in(R"(out.txt)",ios::binary|ios::out);
//    in.write(reinterpret_cast<char *>(p), sizeof(student)*num_stu);
//    in.close();
//
//    ifstream out(R"(out.txt)",ios::binary|ios::in);
//    auto *m = new student[num_stu];
//    for (int j = 0; j < num_stu; ++j) {
//        out.read(reinterpret_cast<char *>(m+j), sizeof(student));
//    }
////    for (int j = 0; j < num_stu; ++j) {
////        cout << m[j].score<<"  "<<m[j].stu_id<<endl;
////    }
//    out.close();
//
//    ofstream i(R"(out.txt)",ios::app);
//    i.write(reinterpret_cast<char *>(m), sizeof(student)*num_stu);
//    i.close();
//}
