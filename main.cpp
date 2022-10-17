#include <QApplication>
#include "calculator.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    calculator calculator;
    calculator.show();
    return QApplication::exec();
}
