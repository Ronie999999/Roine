#include "dialog.h"
#include<QFile>
#include<QApplication>
#include<iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qssFile(":/css/css.qss");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        QString qss = QLatin1String(qssFile.readAll());
        qApp->setStyleSheet(qss);
        qssFile.close();
        std::cout << "open qss file success"<< std::endl;
    }
    else{
        std::cout << "open qss file failed"<< std::endl;
    }
    Dialog w;
    w.show();
    return a.exec();
}

