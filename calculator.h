#ifndef CALCULATOR_H
#define CALCULATOR_H

#include<QPushButton>
#include<QLineEdit>
#include<QString>
#include <QDialog>
#include "buttonnum.h"

QT_BEGIN_NAMESPACE
namespace Ui { class calculator; }
QT_END_NAMESPACE
class ButtonNum;

class calculator : public QDialog {
Q_OBJECT
public:
    calculator(QWidget *parent = nullptr);

    ~calculator();

    //声明需要的部件
    ButtonNum *button_num[10]; //数组，含10个按钮
    QPushButton *button_plus;
    QPushButton *button_minus;
    QPushButton *button_multiply;
    QPushButton *button_devide;
    QPushButton *button_equal;
    QPushButton *button_clearAll;

    QLineEdit *lineEdit;

    //声明需要的变量
    //第1个数、第2个数、运算结果
    static float num1, num2, result;
    static QString S; //用于显示在lineEdit里面的字符串
    //是等号运算符的时候，判断是加、减、乘、除运算中的哪一个
    static char sign;
    static int mark; //若单击过“+”“-”“*”“/”按钮，mark=2，表示读入第2个数
private slots:

    //声明处理按钮单击信号的槽函数
    void on_button_plus_clicked();

    void on_button_minus_clicked();

    void on_button_multiply_clicked();

    void on_button_devide_clicked();

    void on_button_equal_clicked();

    void on_button_clearAll_clicked();

    void on_button_num_clicked(const int &index);
};

#endif // CALCULATOR_H
