#ifndef BUTTONNUM_H
#define BUTTONNUM_H

#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <QObject>
#include <QDebug>
#include "calculator.h"

class ButtonNum : public QPushButton {
Q_OBJECT
public:
    ButtonNum(int i);
    void sent();
public:
    int index;
signals:
    void clickButton(const int &index);
};

#endif // BUTTONNUM_H
