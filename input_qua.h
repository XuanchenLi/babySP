#pragma once

#include "ui_input_qua.h"
#include"main_ui.h"
#include <QWidget>
#include "ui_input_tri.h"
#include <string>
#include "navigation.h"
using namespace std;
class input_tri;
extern class graph;
extern class main_ui;

class input_qua : public QWidget
{
	Q_OBJECT

public:
	input_qua(int o, main_ui& ,QWidget *parent = Q_NULLPTR);
	~input_qua();

private:
	Ui::input_qua ui;
	main_ui& ma;
	int op;
private slots:
	void on_re__clicked();
};
