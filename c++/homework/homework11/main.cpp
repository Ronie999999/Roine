////请补充合适的头文件
//#include <iostream>
//#include <exception>
//#include <typeinfo>
//using  namespace  std;
////请定义异常类MyException1
//class MyException1:public exception{
//public:
//    const char * what () const throw ()    {
//        return typeid(MyException1).name();
//    }
//};
////请定义异常类MyException2
//class MyException2:public exception{
//public:
//    const char * what () const throw ()    {
//        return typeid(MyException2).name();
//    }
//};
//
////请定义函数divide()，对除0操作引发异常
//class exp:public exception{
//public:
//    const char * what () const throw ()    {
//        return "0";
//    }
//};
//
//
//int divide(int a, int b){
//    if (b == 0) throw exp();
//    return a/b;
//}
#include <stdio.h>
int main(){
    int i;
    scanf("%d",&i);
    int num[i][i];
    num[0][0] = 1; num[1][0] = 1; num[1][1] = 1;
    for (int j = 2; j < i; ++j) {
        for (int k = 0; k < j+1; ++k) {
            if (k == 0 || k== j) num[j][k] = 1;
            else num[j][k] = num[j-1][k-1]+ num[j-1][k];
        }
    }
    for (int l = 0; l < i; ++l) {
        for (int j = 0; j < l+1; ++j) {
            printf("%d ", num[l][j]);
        }
        printf("\n");

    }
}

//    int  id,k;
//    cin>>id;
//    char  a;
//    string  s="hello";
//    try
//    {
//        switch  (id)
//        {
//            case  1:
//                throw  MyException1();
//                break;
//            case  2:
//                throw  MyException2();
//                break;
//            case  3:
//                k=divide(8,0);
//                break;
//            case  4:
//                a=s.at(10);
//                cout<<a<<endl;
//                break;
//            default:
//                break;
//        }
//    }
//    catch  (MyException1  &e)
//    {
//        cout  <<  "exception:  "<<e.what()<<  endl;
//    }
//    catch  (MyException2  &e)
//    {
//        cout  <<  "exception:  "<<e.what()<<  endl;
//    }
//    catch  (int  &e)
//    {
//        cout  <<  "exception:  "<<e<<  endl;
//    }
//    catch(exception  &e)
//    {
//        cout  <<  "exception:  "<<e.what()<<  endl;
//    }
//    cout<<"Return  to  main()"<<endl;
//    return  0;


//}
