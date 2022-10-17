#include "buttonnum.h"
#include "calculator.h"
ButtonNum::ButtonNum(int i) : QPushButton(QString::number(i)), index(i) {
}

void ButtonNum::sent() {
    emit clickButton(index);
}

//void ButtonNum::clickButton() {
//    calculator::S += QString::number(index);
//    calculator::lineEdit->setText(calculator::S);
//    if (calculator::mark == 1) {
//        calculator::num1 = calculator::num1 * 10 + index;
//    } else {
//        calculator::num2 = calculator::num2 * 10 + index;
//    }
//}
