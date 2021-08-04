#pragma once

#include <QtWidgets/QWidget>
#include "ui_login.h"

class login : public QWidget
{
    Q_OBJECT

public:
    login(QWidget *parent = Q_NULLPTR);

private:
    Ui::loginClass ui;

private slots:
    void on_pushButton__clicked();
    void on_fur__clicked();
};
