#include "calculate.h"
#include<iostream>
#include<math.h>
calculate::calculate()
{

}

void calculate::ca1(double *money_month, double *interest_month, double *total_month, double value_money, double value_rates, int month){
    double money = value_money;
    for (int i = 0; i < month; i++){
        total_month[i] = value_money * value_rates * (pow(1+value_rates, month))/(pow(1+value_rates,month)-1);
        interest_month[i] = money * value_rates;
        money_month[i] = total_month[i] - interest_month[i];
        money -= money_month[i];
    }
}

void calculate::ca2(double *money_month, double *interest_month, double *total_month, double value_money, double value_rates, int month, int value_year){
    double money = value_money;
    for (int i = 0; month > 0; month--, i++){
         money_month[i] = value_money/(value_year*12); //月固定还款额
         interest_month[i] = money*value_rates;
         total_month[i] = money_month[i]+interest_month[i];
         money -= money_month[i];
//         std::cout << interest_month[i]<<'\t';
    }
}
