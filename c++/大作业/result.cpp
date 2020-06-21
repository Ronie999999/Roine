

#include "result.h"

result::result(std::string month, std::string all_money, std::string interest, std::string first_month, std::string aver, std::string m){
    setWindowTitle("结果");
    setMinimumSize(400, 300);
    setMaximumSize(400, 300);
    this->month = month;
    this->all_money = all_money;
    this->interest = interest;
    this->first_month = first_month;
    this->aver = aver;
    this->m = m;
    set_result();
}

void result::set_result(){

    r_month = new QLabel(this);
//    r_month->setVisible(false);
    r_month->setText("还款月数 : " + QString::fromStdString(month));
    r_month->setGeometry(0,0,300,50);

    r_all_money = new QLabel(this);
//    r_all_money->setVisible(false);
    r_all_money->setText("还款总额(万) : " + QString::fromStdString(all_money));
    r_all_money->setGeometry(0,50,300,50);

    r_interest = new QLabel(this);
//    r_interest->setVisible(false);
    r_interest->setText("支付利息(万) : " + QString::fromStdString(interest));
    r_interest->setGeometry(0,100,300,50);

    r_first_month = new QLabel(this);
//    r_first_month->setVisible(false);
    r_first_month->setText("首月还款(元) : " + QString::fromStdString(first_month));
    r_first_month->setGeometry(0,150,300,50);

    aver_month = new QLabel(this);
    aver_month->setText("月均还款(元) : " + QString::fromStdString(aver));
    aver_month->setGeometry(0, 200, 300, 50);

    mm = new QLabel(this);
    mm->setText("每月递减(元) : " + QString::fromStdString(m));
    mm->setGeometry(0, 250, 300, 50);
}
