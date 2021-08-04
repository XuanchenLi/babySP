#pragma once

#include <QWidget>
#include "ui_result.h"
#include<QPaintEvent> //用于绘画事件
#include<QtGui> //引入用到的控件
#include<qpen.h>
#include"main_ui.h"
#include"navigation.h"
extern class main_ui;
extern class graph;
class result : public QWidget
{
	Q_OBJECT

protected:
	void paintEvent(QPaintEvent*) {
		QPainter painter(this);
		painter.drawImage(0, 0, paper);
	}
public:
	result(main_ui& m,QWidget *parent = Q_NULLPTR);
	~result();

private:
	void Paint();
	Ui::result ui;
	main_ui& ma;
	QImage paper;
private slots:
	void on_close__clicked();
};
