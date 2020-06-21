#ifndef DIALOG_H
#define DIALOG_H
#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<qaction.h>
#include<QRadioButton>
#include<QButtonGroup>
#include<QPropertyAnimation>
#include<QAbstractAnimation>
#include<QPropertyAnimation>
#include<QAccessibleWidget>
#include<math.h>
#include<iostream>
#include<QGraphicsOpacityEffect>
#include<QString>
#include<sstream>
#include<string>
#include<qmenu.h>
#include<qmessagebox.h>
#include<calculate.h>
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    template<typename o>
    void animation_opacity(o *item, int start, int end,int pos_x, int pos_y, int height, int width);
    template<typename t>
    void animation_scale(t *item, int pos_x1, int pos_y1, int height1,
                   int width1, int pos_x2, int pos_y2, int height2, int width2);
    ~Dialog();
private:
    bool check_num(QString str);
    void set_result(int month_, double value_money, double interest_month[], double total_month[]);
//    void ca2(double money_month[], double interest_month[], double total_month[], double value_money, double value_rates, int month, int value_year);
//    void ca1(double money_month[], double interest_month[], double total_month[], double value_money, double value_rates, int month);
    void set_pub_visible();
    void set_invisible();
    void set_items();
    void setrates();
    QMenu *menu;
    QWidget *m_pWidget;
    QLabel *accumulation_money, *business_money, *accumulation_rate,*business_rate, *pub_year
    , *Buying_property, * Repayment_method;
    QLineEdit *acc_money,*bus_money, *year, *acc_rate, *bus_rate;
    QPushButton *menu_button, *pub_Button, *main_button1, *main_button2, *main_button3, *return_button;
    QRadioButton *radio1,*radio2,*radio3,*radio4;
    QButtonGroup *Group1, *Group2;
    int area;
//    QLabel *r_month, *r_all_money, *r_interest, *r_first_month;
    QAction *interest1,*interest2,*interest3,*interest4,*interest5,*interest6,*interest7,*interest8;
private slots:
    void check();
    void show_area1();
    void show_area2();
    void show_area3();
    void return_();
    void caculate();
    void set_rates();
    void setrate1();
    void setrate2();
    void setrate3();
    void setrate4();
    void setrate5();

};
#endif // DIALOG_H
