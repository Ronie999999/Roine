//
// Created by Ronie on 17/3/2020.
//

#include <iostream>
using namespace std;

class CTime{
public:
    void showTime();
    int dayDiff(CTime time);
    int isvalid();
    CTime(int i_year = 0, int i_month = 0, int i_day = 0, int i_hour = 0, int i_min = 0, int i_second = 0);
    CTime(CTime & p);
    ~CTime();
private:
    int year; int month; int day; int hour; int min; int second; int t; int data; int time;
};

CTime::CTime(int i_year, int i_month, int i_day, int i_hour, int i_min , int i_second) {
    year = i_year;
    month = i_month;
    day = i_day;
    hour = i_hour;
    min = i_min;
    second = i_second;
    data = 1;
    time = 1;
//    if (!this -> isvalid()){
//        year = 0; month =0; day = 0; hour = 0; min = 0; second = 0;
//    }
    this -> isvalid();
    if (data == 0 and time == 0) {cout << "date and time error!" << endl;}
    else if (data == 0 and time != 0) {cout << "date error!" << endl;}
    else if (time == 0 and data != 0) {cout << "time error!" << endl;}
    cout << "构造函数被调用" << endl;
}

int CTime::dayDiff(CTime time) {
    int temp_year_max, temp_month_max, temp_day_max, days = 0,temp_day_min, temp_year_min, temp_month_min;
    if (year > time.year or (year == time.year and month > time.month) or (year == time.year and month == time.month and day > time.day)){ //如果time对象的时间小
        temp_day_max =day; temp_month_max = month; temp_year_max = year;
        temp_day_min = time.day; temp_month_min = time.month; temp_year_min = time.year;
    } else{
        temp_day_max =time.day; temp_month_max = time.month; temp_year_max = time.year;
        temp_day_min = day; temp_month_min = month; temp_year_min = year;
    }
    while (true){
            if (temp_day_min == temp_day_max and temp_month_min == temp_month_max and temp_year_min == temp_year_max) break; //如果两个时间相同
            days++;
            //处理月份 天
            if (temp_month_min == 1 or temp_month_min == 3 or temp_month_min == 5 or temp_month_min == 7 or temp_month_min == 8 or temp_month_min == 10){
                if (temp_day_min == 31) {
                    temp_month_min++;
                    temp_day_min = 1;
                }
                else temp_day_min++;
                continue;
            }
            if (temp_month_min == 4 or temp_month_min == 6 or temp_month_min == 9 or temp_month_min == 11){
                if (temp_day_min == 30) {
                    temp_month_min++;
                    temp_day_min = 1;
                }
                else temp_day_min++;
                continue;
            }
            if (temp_month_min == 12) {
                if (temp_day_min == 31) {
                    temp_year_min++;
                    temp_day_min = 1;
                    temp_month_min = 1;
                } else temp_day_min++;
                continue;
            }
            if (temp_month_min == 2){
                if (temp_year_min % 100 == 0) { //如果是世纪年
                    if (temp_year_min % 400 == 0) { //是闰年
                        if (temp_day_min == 29){
                            temp_day_min = 1;
                            temp_month_min++;
                        } else temp_day_min++;
                    }else{
                        if (temp_day_min == 28){
                            temp_day_min = 1;
                            temp_month_min++;
                        }else temp_day_min++;
                    }
                } else {     //普通年
                    if (temp_year_min % 4 == 0 and temp_year_min % 100 != 0) {//是闰年
                        if (temp_day_min == 29){
                            temp_day_min = 1;
                            temp_month_min++;
                        } else temp_day_min++;
                    } else{
                        if (temp_day_min == 28){
                            temp_day_min = 1;
                            temp_month_min++;
                        } else temp_day_min++;
                    }
                }
            }
        }
    return days;
}

void CTime::showTime() {
    if (data != 0 and time != 0) cout << year << "/" << month << "/" << day << " " << hour << ":" << min << ":" << second << endl;
    else cout << 0 << "/" << 0 << "/" << 0 << " " << 0 << ":" << 0 << ":" << 0 << endl;
}

int CTime::isvalid() {
    if (hour > 23 or min > 59 or second > 59){
        time = 0;
    }
    if(month > 12 ){
        data = 0;
    }
    if((month == 1 or month == 3 or month ==5 or month ==7 or month==8 or month ==10 or month ==12) and day > 31) data = 0;
    if((month == 4 or month == 6 or month ==9 or month ==11) and day > 30) data = 0;

    if (month == 2) {
        if (year % 100 == 0) { //如果是世纪年
            if (year % 400 == 0) { //是闰年
                if (day > 29) data = 0;
            } else { //不是闰年
                if (day > 28) data = 0;
            }
        } else {     //普通年
            if (year % 4 == 0 and year % 100 != 0) {//是闰年
                if (day > 29) data = 0;
            } else { //不是闰年
                if (day > 28) data = 0;
            }
        }
    }
    if (data == 0 and time == 0) { return  0;}
    else if (data == 0 and time != 0) {return 0;}
    else if (time == 0 and data != 0) {return 0;}
    else return 1;
}


CTime::CTime(CTime & p){
    year = p.year; month = p.month; day = p.day; hour = p.hour; min = p.min; second = p.second;
    cout << "拷贝构造函数被调用" << endl;
}

CTime::~CTime() {
    cout << "析构函数被调用" << endl;
}

int  main()
{
    int  year,  month,  day,  hour,  minute,  second;
    cin  >>  year  >>  month  >>  day  >>  hour  >>  minute  >>  second;
    CTime  t1(year,  month,  day,  hour,  minute,  second);
    t1.showTime();
    CTime  t2(2000,  1,  1, 0, 0,0);  //利用默认形参将时间初始化为00:00:00
    if  (t1.isvalid())          //如果日期和时间合法，则计算天数
    {
        int  days=0;
        days=t1.dayDiff(t2);
        cout  <<  "这两天之间相隔了"  <<  days  <<  "天"  <<  endl;
        days=t2.dayDiff(t1);
        cout  <<  "这两天之间相隔了"  <<  days  <<  "天"  <<  endl;
    }
}
