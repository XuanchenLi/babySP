#include <QtWidgets/QApplication>
#include "navigation.h"
#include "login.h"
#include"input_tri.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login w;
    w.show();
    return a.exec();
}
