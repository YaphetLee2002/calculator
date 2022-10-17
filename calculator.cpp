#include "calculator.h"
#include "ui_calculator.h"
#include<QGridLayout>
#include "ButtonNum.h"

calculator::calculator(QWidget *parent)
        : QDialog(parent) {
    //初始化功能按钮指针
    button_plus = new QPushButton("+");
    button_minus = new QPushButton("-");
    button_multiply = new QPushButton("*");
    button_devide = new QPushButton("/");
    button_equal = new QPushButton("=");
    button_clearAll = new QPushButton("c");
    lineEdit = new QLineEdit("C");
    //初始化数字按钮指针
    for (int i = 0; i < 10; i++) {
        button_num[i] = new ButtonNum(i);//对10个数字产生对象指针
    }
    //网格布局基本原理是把窗口划分为若干个单元格
    //每个子部件被放置于一个或多个单元格之中
    auto *Grid = new QGridLayout;
    Grid->addWidget(lineEdit, 1, 1, 1, 4, Qt::Alignment());//首先将文本框添加到布局中
    //6个参数的含义：1为待放入部件的指针，2、3指所在行和列
    //4、5指占用几行和几列，最后一个是对齐方式
    for (int i = 2; i <= 5; i++) {//这里的i和j表示按钮所在的行数和列数，建议不要修改
        for (int j = 1; j <= 4; j++) {
            Grid->addWidget((QPushButton *) button_num[(i - 2) * 4 + j - 1], i, j, Qt::Alignment());
            //将数字按钮添加到布局中
        }
    }
    //把布局设置给当前创建的对话框对象
    this->setLayout(Grid);
    //实现连接函数
    for (int i = 0; i < 10; ++i) {
        connect(button_num[i], &QPushButton::pressed, button_num[i], &ButtonNum::sent);
        connect(button_num[i], SIGNAL(clickButton(int)), this, SLOT(on_button_num_clicked(int)));//数字连接函数
    }
    //功能按钮函数
    connect(button_plus, SIGNAL(clicked(bool)), this, SLOT(on_button_plus_clicked()));
    connect(button_minus, SIGNAL(clicked(bool)), this, SLOT(on_button_minus_clicked()));
    connect(button_multiply, SIGNAL(clicked(bool)), this, SLOT(on_button_multiply_clicked()));
    connect(button_devide, SIGNAL(clicked(bool)), this, SLOT(on_button_devide_clicked()));
    connect(button_equal, SIGNAL(clicked(bool)), this, SLOT(on_button_equal_clicked()));
    connect(button_clearAll, SIGNAL(clicked(bool)), this, SLOT(on_button_clearAll_clicked()));
}

calculator::~calculator() = default;

float calculator::num1 = 0;
float calculator::num2 = 0;
float calculator::result = 0.0;
QString calculator::S = "";
char calculator::sign = ' ';
int calculator::mark = 1;
//初始化文本框按钮指针
//QLineEdit *calculator::lineEdit = new QLineEdit("C");

void calculator::on_button_plus_clicked() {
    S += "+";   //把“+”连接到字符串S后面
    sign = '+';  //设置标记为“+”
    mark = 2;   //单击其他数字按钮后，将该数字作为加法运算的第2个数字
    lineEdit->setText(S);
}

void calculator::on_button_minus_clicked() {
    S += "-";
    sign = '-';
    mark = 2;
    lineEdit->setText(S);
}

void calculator::on_button_multiply_clicked() {
    S += "*";
    sign = '*';
    mark = 2;
    lineEdit->setText(S);
}

void calculator::on_button_devide_clicked() {
    S += "/";
    sign = '/';
    mark = 2;
    lineEdit->setText(S);
}

void calculator::on_button_equal_clicked() {
    S += "=";
    switch (sign) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            break;
    }
    //S+=QString::number(result, 10);  //就这个函数而言，result必须是整型
    S += QString("%1").arg(result);//float转QString
    //S+= result+'0'; //不能这样写，result大于等于10就会报错
    lineEdit->setText(S);
}

void calculator::on_button_clearAll_clicked() {
    S = "";
    lineEdit->setText(S);
    mark = 1;
    num1 = 0.0;
    num2 = 0.0;
    result = 0.0;
}

void calculator::on_button_num_clicked(const int &index) {
    S += QString::number(index);
    lineEdit->setText(S);
    if (mark == 1) {
        num1 = num1 * 10 + index;
    } else {
        num2 = num2 * 10 + index;
    }
}
