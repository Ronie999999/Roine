#ifndef RESULT_H
#define RESULT_H

#include<QLabel>
#include <QDialog>
#include<QString>

class result:public QDialog
{
    Q_OBJECT
public:
    result(std::string month, std::string all_money, std::string interest, std::string first_month, std::string aver, std::string m);
    void set_result();
private:
    QLabel *r_month, *r_all_money, *r_interest, *r_first_month, *aver_month, *mm;
    std::string month, all_money, interest, first_month, aver, m;
};

#endif // RESULT_H
