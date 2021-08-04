#pragma once
#include"main_ui.h"
#include <QWidget>
#include "ui_input_tri.h"
#include <string>
#include "navigation.h"
using namespace std;
class input_tri;
extern class graph;
extern class main_ui;
class input_tri : public QWidget
{
	Q_OBJECT

public:
	friend main_ui;
	input_tri(int o,main_ui&,QWidget *parent = Q_NULLPTR);
	~input_tri();

private:
	Ui::input_tri ui;
	main_ui& ma;
	int op;
private slots:
	void on_re__clicked();
};
