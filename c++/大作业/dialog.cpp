#include "dialog.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <result.h>

Dialog::Dialog(QWidget *parent): QDialog(parent)
{
    //设置窗口
    setWindowTitle("房贷计算器");
    setWindowIcon(QIcon(":/pic/home.png"));
    setMinimumSize(800, 500);
    setMaximumSize(800, 500);
    //设置背景
//    QPixmap pixmap = QPixmap(":/pic/bg.PNG").scaled(this->size());
//    QPalette palette(this->palette());
//    palette.setBrush(QPalette::Background, QBrush(pixmap));
//    this->setPalette(palette);
    //设置主按钮
    main_button1 = new QPushButton(this);
    main_button1->setText("商业贷款");
    main_button1->setGeometry(75,225,100,50);
    main_button1->setObjectName("main1");

    main_button2 = new QPushButton(this);
    main_button2->setText("公积金贷款");
    main_button2->setGeometry(350,225,100,50);
    main_button2->setObjectName("main2");

    main_button3 = new QPushButton(this);
    main_button3->setText("组合贷款");
    main_button3->setGeometry(625,225,100,50);
    main_button3->setObjectName("main3");
    //设置组件
    set_items();
    //事件响应
    connect(main_button1,SIGNAL(clicked()),this,SLOT(show_area1()));
    connect(main_button2,SIGNAL(clicked()),this,SLOT(show_area2()));
    connect(main_button3,SIGNAL(clicked()),this,SLOT(show_area3()));
    connect(pub_Button,SIGNAL(clicked()),this,SLOT(check()));
    connect(return_button,SIGNAL(clicked()),this,SLOT(return_()));
    connect(radio1,SIGNAL(clicked()),this,SLOT(set_rates()));
    connect(radio2,SIGNAL(clicked()),this,SLOT(set_rates()));
    connect(interest1,SIGNAL(triggered()),this,SLOT(setrate1()));
    connect(interest2,SIGNAL(triggered()),this,SLOT(setrate2()));
    connect(interest3,SIGNAL(triggered()),this,SLOT(setrate3()));
    connect(interest4,SIGNAL(triggered()),this,SLOT(setrate4()));
    connect(interest5,SIGNAL(triggered()),this,SLOT(setrate5()));
}

void Dialog::set_rates(){
    if (Group1->checkedId() == 1){
        acc_rate->setText("4.00");
        bus_rate->setText("5.90");
    }
    else{
        acc_rate->setText("4.40");
        bus_rate->setText("6.49");
    }
}

void Dialog::set_items(){
        menu_button = new QPushButton(this);
        menu_button->setText("设置利率");
        menu_button->setObjectName("menu_button");
        menu = new QMenu();
        menu_button->setVisible(false);
        interest1=new QAction(menu);
        interest2=new QAction(menu);
        interest3=new QAction(menu);
        interest4=new QAction(menu);
        interest5=new QAction(menu);

        interest1->setText("最新基准利率8折");
        interest2->setText("最新基准利率9折");
        interest3->setText("最新基准利率");
        interest4->setText("最新基准利率1.1倍");
        interest5->setText("最新基准利率1.2倍");

        menu->addAction(interest1);
        menu->addAction(interest2);
        menu->addAction(interest3);
        menu->addAction(interest4);
        menu->addAction(interest5);

        menu_button->setMenu(menu);

        business_rate = new QLabel(this);
        business_rate->setText("商业贷款年利率(%)");
        business_rate->setVisible(false);
        business_rate->setObjectName("business_rate");

        accumulation_rate = new QLabel(this);
        accumulation_rate->setText("公积金贷款年利率(%)");
        accumulation_rate->setVisible(false);
        business_rate->setObjectName("business_rate");

        pub_year = new QLabel(this);
        pub_year->setText("贷款期限(年)");
        pub_year->setVisible(false);

        accumulation_money = new QLabel(this);
        accumulation_money->setText("公积金贷款金额(万元)");
        accumulation_money->setVisible(false);

        business_money = new QLabel(this);
        business_money->setText("商业贷款金额(万元)");
        business_money->setVisible(false);

        Buying_property = new QLabel(this);
        Buying_property->setText("购房性质");
        Buying_property->setVisible(false);
        Repayment_method = new QLabel(this);
        Repayment_method->setText("还款方式");
        Repayment_method->setVisible(false);

        acc_money = new QLineEdit(this);
        acc_money->setVisible(false);
        bus_money = new QLineEdit(this);
        bus_money->setVisible(false);
        year = new QLineEdit(this);
        year->setVisible(false);

        acc_rate = new QLineEdit(this);
        acc_rate->setVisible(false);

        bus_rate = new QLineEdit(this);
        bus_rate->setVisible(false);

        radio1 = new QRadioButton(this);
        radio1->setText("一套房");
        radio1->setVisible(false);

        radio2 = new QRadioButton(this);
        radio2->setText("两套房");
        radio2->setVisible(false);

        radio3 = new QRadioButton(this);
        radio3->setText("等额本息");
        radio3->setVisible(false);

        radio4 = new QRadioButton(this);
        radio4->setText("等额本金");
        radio4->setVisible(false);

        Group1 = new QButtonGroup(this);
        Group1->addButton(radio1,1);
        Group1->addButton(radio2,2);

        Group2 = new QButtonGroup(this);
        Group2->addButton(radio3,3);
        Group2->addButton(radio4,4);

        pub_Button = new QPushButton(this);
        pub_Button->setText("计算");
        pub_Button->setObjectName("pub_button");
        pub_Button->setIcon(QIcon(":/pic/c.png"));
        pub_Button->setVisible(false);

        return_button = new QPushButton(this);
        return_button->setText("返回");
        return_button->setObjectName("return");
        return_button->setVisible(false);

}

template <typename t>
void Dialog::animation_scale(t *item, int pos_x1, int pos_y1, int height1, int width1,
               int pos_x2, int pos_y2, int height2, int width2){
    QPropertyAnimation *pScaleAnimation = new QPropertyAnimation(item, "geometry");
    pScaleAnimation->setDuration(200);
    pScaleAnimation->setStartValue(QRect(pos_x1, pos_y1, width1, height1));
    pScaleAnimation->setEndValue(QRect(pos_x2, pos_y2, width2, height2));
    pScaleAnimation->start();
}
template <typename o>
void Dialog::animation_opacity(o *item,int start, int end,int pos_x, int pos_y, int width, int height){
    item->setGeometry(pos_x, pos_y, height, width);
    item->setVisible(true);
    QGraphicsOpacityEffect *pButtonOpacity = new QGraphicsOpacityEffect(this);
    pButtonOpacity->setOpacity(start);
    item->setGraphicsEffect(pButtonOpacity);
    QPropertyAnimation *pOpacityAnimation = new QPropertyAnimation(pButtonOpacity, "opacity");
    pOpacityAnimation->setDuration(1000);
    pOpacityAnimation->setStartValue(start);
    pOpacityAnimation->setEndValue(end);
    pOpacityAnimation->start();
}

void Dialog::set_pub_visible(){
    return_button->setVisible(true);
    pub_year->setVisible(true);
    pub_Button->setVisible(true);
    radio1->setVisible(true);
    radio2->setVisible(true);
    radio3->setVisible(true);
    radio4->setVisible(true);
    Buying_property->setVisible(true);
    Repayment_method->setVisible(true);
    year->setVisible(true);
//    menu_button->setVisible(true);
}

void Dialog::show_area1(){
    area = 1;
    main_button1->setVisible(false);
    main_button2->setVisible(false);
    main_button3->setVisible(false);
    //组件显示
    bus_rate->setVisible(true);
    bus_money->setVisible(true);
    business_rate->setVisible(true);
    business_money->setVisible(true);
    menu_button->setVisible(true);
    set_pub_visible();
    //动画显示
    animation_scale(menu_button, 0, 0, 0, 0, 700, 50, 25, 100);
    animation_scale(return_button, 0, 0, 0, 0, 700, 0, 25, 100);
    animation_scale(business_money, 0, 0, 0, 0, 50, 50, 25, 150);
    animation_scale(bus_money, 0, 0, 0, 0, 300, 50, 25, 150);
    animation_scale(pub_year, 0, 0, 0, 0, 50, 100, 25, 150);
    animation_scale(year, 0, 0, 0, 0, 300, 100, 25, 150);
    animation_scale(Buying_property, 0, 0, 0, 0, 50, 150, 25, 150);
    animation_scale(radio1,0, 0, 0, 0, 300, 150, 25, 100);
    animation_scale(radio2,0, 0, 0, 0, 390, 150, 25, 100);
    animation_scale(menu_button,0, 0, 0, 0, 300, 200, 25, 100);
    animation_scale(business_rate, 0, 0, 0, 0, 50, 200, 25, 150);
    animation_scale(bus_rate, 0, 0, 0, 0, 400, 200, 25, 50);
    animation_scale(Repayment_method, 0, 0, 0, 0, 50, 250, 25, 150);
    animation_scale(radio3,0, 0, 0, 0, 300, 250, 25, 100);
    animation_scale(radio4,0, 0, 0, 0, 390, 250, 25, 100);
    animation_scale(pub_Button, 0, 0, 0, 0, 200, 300, 25, 125);
}
void Dialog::show_area2(){
    area = 2;
    main_button1->setVisible(false);
    main_button2->setVisible(false);
    main_button3->setVisible(false);
    //组件显示
    set_pub_visible();
    acc_rate->setVisible(true);
    acc_money->setVisible(true);
    accumulation_rate->setVisible(true);
    accumulation_money->setVisible(true);

    animation_scale(return_button, 800, 500, 0, 0, 700, 0, 25, 100);
    animation_scale(accumulation_money, 800, 500, 0, 0, 100, 50, 25, 150);
    animation_scale(acc_money, 800, 500, 0, 0, 350, 50, 25, 150);
    animation_scale(pub_year, 800, 500, 0, 0, 100, 100, 25, 150);
    animation_scale(year, 800, 500, 0, 0, 350, 100, 25, 150);
    animation_scale(Buying_property, 800, 500, 0, 0, 100, 150, 25, 150);
    animation_scale(radio1,800, 500, 0, 0, 350, 150, 25, 100);
    animation_scale(radio2,800, 500, 0, 0, 440, 150, 25, 100);
    animation_scale(accumulation_rate, 800, 500, 0, 0, 100, 200, 25, 150);
    animation_scale(acc_rate, 800, 500, 0, 0, 350, 200, 25, 150);
    animation_scale(Repayment_method, 800, 500, 0, 0, 100, 250, 25, 150);
    animation_scale(radio3,800, 500, 0, 0, 350, 250, 25, 100);
    animation_scale(radio4,800, 500, 0, 0, 440, 250, 25, 100);
    animation_scale(pub_Button,800, 500, 0, 0, 250, 300, 25, 125);
}

void Dialog::show_area3(){
    area = 3;
    main_button1->setVisible(false);
    main_button2->setVisible(false);
    main_button3->setVisible(false);
    //组件显示
    set_pub_visible();
    acc_rate->setVisible(true);
    acc_money->setVisible(true);
    accumulation_rate->setVisible(true);
    accumulation_money->setVisible(true);
    bus_rate->setVisible(true);
    bus_money->setVisible(true);
    business_rate->setVisible(true);
    business_money->setVisible(true);
    menu_button->setVisible(true);

    animation_opacity(return_button,0, 1, 700, 0, 25, 100);

    animation_opacity(accumulation_money,  0, 1, 100, 50, 25, 150);
    animation_opacity(acc_money,  0, 1, 350, 50, 25, 150);
    animation_opacity(business_money,  0, 1, 100, 100, 25, 150);
    animation_opacity(bus_money, 0, 1, 350, 100, 25, 150);

    animation_opacity(pub_year,  0, 1, 100, 150, 25, 150);
    animation_opacity(year,  0, 1, 350, 150, 25, 150);
    animation_opacity(Buying_property,  0, 1, 100, 200, 25, 150);
    animation_opacity(radio1, 0, 1, 350, 200, 25, 100);
    animation_opacity(radio2, 0, 1, 440, 200, 25, 100);
    animation_opacity(accumulation_rate,0, 1, 100, 250, 25, 150);
    animation_opacity(acc_rate,  0, 1, 350, 250, 25, 150);
    animation_opacity(business_rate,  0, 1, 100, 300, 25, 150);
    animation_opacity(menu_button, 0, 1, 350, 300, 25, 100);
    animation_opacity(bus_rate,  0, 1, 450, 300, 25, 50);

    animation_opacity(Repayment_method, 0, 1, 100, 350, 25, 150);
    animation_opacity(radio3,0, 1, 350, 350, 25, 100);
    animation_opacity(radio4, 0,1, 440, 350, 25, 100);
    animation_opacity(pub_Button, 0, 1, 250, 400, 25, 125);

}
void Dialog::return_(){
    area = 0;
    menu_button->setVisible(false);
    main_button1->setVisible(true);
    main_button2->setVisible(true);
    main_button3->setVisible(true);
    business_rate->setVisible(false);
    accumulation_rate->setVisible(false);
    pub_year->setVisible(false);
    accumulation_money->setVisible(false);
    business_money->setVisible(false);
    Buying_property->setVisible(false);
    Repayment_method->setVisible(false);
    acc_money->setVisible(false);
    bus_money->setVisible(false);
    year->setVisible(false);
    acc_rate->setVisible(false);
    bus_rate->setVisible(false);
    radio1->setVisible(false);
    radio2->setVisible(false);
    radio3->setVisible(false);
    radio4->setVisible(false);
    pub_Button->setVisible(false);
    return_button->setVisible(false);
//    r_month->setVisible(false);
//    r_all_money->setVisible(false);
//    r_interest->setVisible(false);
//    r_first_month->setVisible(false);
    bus_money->setText("");
    acc_money->setText("");
    year->setText("");
    bus_rate->setText("");
    acc_rate->setText("");
}

bool Dialog::check_num(QString str){
    for (int i = 0; i < str.length(); i++){
        if (str[i] < 48 or str[i] > 57){
            return false;
        }
    }
    return true;
}

void Dialog::check(){
    QString value1, value2;
    bool rate_acc=true, rate_bus=true, year = false, acc = false, bus=false;
    for (int i = 0; i < 1; i++){

        //检查金额输入
        value1 = bus_money->text();
        value2 = acc_money->text();
        if (value1.length() > 6 or value1.length() < 0 or value2.length() > 6 or value2.length() < 0 or !check_num(value1) or !check_num(value2)){
            QMessageBox message(QMessageBox::NoIcon,"warning","金额过大或者错误可能产生不可预估的错误，是否继续",QMessageBox::Yes | QMessageBox::No, NULL);
            if (message.exec() == QMessageBox::No){
                break;
            }
        }
        acc = true;
        bus = true;

        //检查时间输入
        value1 = this->year->text();
        if (check_num(value1) == false){
            QMessageBox message(QMessageBox::NoIcon,"warning","你在贷款期限处可能填入了非法字符，这可能导致不可预期的错误，是否继续",QMessageBox::Yes | QMessageBox::No, NULL);
            if (message.exec() == QMessageBox::No){
                break;
            }
            else year = true;
        }
        else year = true;


        //检查利率输入
        value1 = acc_rate->text();
        value2 = bus_rate->text();
        for (int j = 0; j < value1.length(); j++){
            if (value1[j]>57 or value1[j]==47 or value1[j] < 46){
                QMessageBox message(QMessageBox::NoIcon,"warning","你在贷款利率bus处可能填入了非法字符，这可能导致不可预期的错误，是否继续",QMessageBox::Yes | QMessageBox::No, NULL);
                if (message.exec() == QMessageBox::Yes){
                    break;
                }
                else{
                    rate_acc = false;
                    break;
                }
            }
        }
        for (int j = 0; j < value2.length(); j++){
            if (value2[j] > 57 or value2[j] == 47 or value2[j] < 46){
                QMessageBox message(QMessageBox::NoIcon,"warning","你在贷款利率acc处可能填入了非法字符，这可能导致不可预期的错误，是否继续",QMessageBox::Yes | QMessageBox::No, NULL);
                if (message.exec() == QMessageBox::Yes){
                    break;
                }
                else{
                    rate_bus = false;
                    break;
                }
            }
        }
        if (acc == true and bus == true and rate_acc == true and rate_bus == true and year == true) caculate();
    }
}

void Dialog::caculate(){
    //计算
    bool ok;
    int id2 = Group2->checkedId();
    int value_year = year->text().toInt(&ok);
    int month = value_year*12;
    int month_ = month;
    class calculate a,b;

    if (area == 1){
        double total_month[month], interest_month[month], money_month[month];
        for (int i = 0; i < month; i++){
            total_month[i] = 0;
        }
        double value_money = bus_money->text().toDouble(&ok);//金额
        double value_rates = bus_rate->text().toDouble(&ok)/(100*12);//月利率
        if (id2 == 4){
            a.ca2(money_month,interest_month, total_month, value_money, value_rates, month, value_year);
            set_result(month_,value_money,interest_month,total_month);
        }
        if (id2 == 3){
            a.ca1(money_month, interest_month, total_month, value_money, value_rates, month);
            set_result(month_,value_money,interest_month,total_month);
        }
    }

    if (area == 2){
        double total_month[month], interest_month[month], money_month[month];
        for (int i = 0; i < month; i++){
            total_month[i] = 0;
        }
        double value_money = acc_money->text().toDouble(&ok);//金额
        double value_rates = acc_rate->text().toDouble(&ok)/(100*12);//月利率
        if (id2 == 4){

            a.ca2(money_month,interest_month, total_month, value_money, value_rates, month, value_year);
            set_result(month_,value_money,interest_month,total_month);
        }
        if (id2 == 3){
            a.ca1(money_month,interest_month, total_month, value_money, value_rates, month);
            set_result(month_,value_money,interest_month,total_month);
        }
    }

    if (area ==3){
        double acc_money_month[month], acc_interest_month[month], acc_total_month[month];
        double bus_money_month[month], bus_interest_month[month], bus_total_month[month];
        double all_interest_month[month], all_total_month[month];
        double acc_value_money = acc_money->text().toDouble(&ok);
        double acc_value_rates = acc_rate->text().toDouble(&ok)/(100*12);
        double bus_value_money = bus_money->text().toDouble(&ok);
        double bus_value_rates = bus_rate->text().toDouble(&ok)/(100*12);
//        std::cout<<bus_value_money<<"   "<<bus_value_rates<<std::endl;
        if (id2 == 4){
            a.ca2(acc_money_month, acc_interest_month, acc_total_month, acc_value_money, acc_value_rates, month, value_year);
            a.ca2(bus_money_month, bus_interest_month, bus_total_month, bus_value_money, bus_value_rates, month, value_year);
            for (int i = 0; i < month_; i++){
                all_total_month[i] = acc_total_month[i] + bus_total_month[i];
                all_interest_month[i] = acc_interest_month[i] + bus_interest_month[i];
//                std::cout << i<<": "<<acc_interest_month[i] <<  "\t     "<<"| "<<bus_interest_month[i]<<std::endl;
            }
            double temp1 = 0,temp2 =0,temp3=0;
            for (int i = 0; i < month_; i++){
                temp1 += all_total_month[i] + all_interest_month[i];
                temp2 += all_total_month[i];
                temp3 += all_interest_month[i];
            }
//            std::cout << temp1<<"  "<<temp2<<"  "<<temp3 << std::endl;
            set_result(month_, acc_value_money + bus_value_money, all_interest_month, all_total_month);
        }

        if (id2 == 3){
            a.ca1(acc_money_month, acc_interest_month, acc_total_month, acc_value_money, acc_value_rates, month);
            a.ca1(bus_money_month, bus_interest_month, bus_total_month, bus_value_money, bus_value_rates, month);
            for (int i = 0; i < month_; i++){
                all_total_month[i] = acc_total_month[i] + bus_total_month[i];
                all_interest_month[i] = acc_interest_month[i] + bus_interest_month[i];
            }
            set_result(month_, acc_value_money + bus_value_money, all_interest_month, all_total_month);
        }
    }
}

void Dialog::set_result(int month_, double value_money, double interest_month[], double total_month[]){
    std::string month = std::to_string(month_);
    double total_i = 0;
    for (int i = 0; i < month_; i++){
        total_i += interest_month[i];
    }
    std::string intertest = std::to_string(total_i);
    std::string money = std::to_string(value_money + total_i);
    std::string first_month = std::to_string(total_month[0] * 10000);
    std::string aver_month = std::to_string(value_money*10000/month_);
    std::string m = std::to_string((total_month[0]- total_month[1])*10000);
    class result a(month, money, intertest, first_month, aver_month, m);
    a.exec();

}

void Dialog::setrate1(){
    if (Group1->checkedId() != 2){
        bus_rate->setText("4.72");
    }
    if (Group1->checkedId() != 1){
        bus_rate->setText("5.192");
    }
}

void Dialog::setrate2(){
    if (Group1->checkedId() != 2){
        bus_rate->setText("5.31");
    }
    if (Group1->checkedId() != 1){
        bus_rate->setText("5.841");
    }
}

void Dialog::setrate3(){
    if (Group1->checkedId() != 2){
        bus_rate->setText("5.90");
    }
    if (Group1->checkedId() != 1){
        bus_rate->setText("6.49");
    }
}

void Dialog::setrate4(){
    if (Group1->checkedId() != 2){
        bus_rate->setText("6.49");
    }
    if (Group1->checkedId() != 1){
        bus_rate->setText("7.139");
    }
}

void Dialog::setrate5(){
    if (Group1->checkedId() != 2){
        bus_rate->setText("7.08");
    }
    if (Group1->checkedId() != 1){
        bus_rate->setText("7.788");
    }
}

Dialog::~Dialog()
{
}
