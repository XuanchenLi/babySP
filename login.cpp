#include "login.h"
#include"main_ui.h"
login::login(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}
void login::on_pushButton__clicked()
{
    QApplication* app;
    app->exit(0);
}
void login::on_fur__clicked()
{
    main_ui* navi = new main_ui;
    this->close();
    navi->show();
}
