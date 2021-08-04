#pragma once
#include"navigation.h"
#include <QWidget>
#include "ui_main_ui.h"
#include<QPaintEvent> //用于绘画事件
#include<QtGui> //引入用到的控件
extern class input_tri;
class main_ui;
extern class input_qua;
extern class result;
class main_ui : public QWidget
{
	Q_OBJECT

public:
	friend input_tri;
	friend result;
	friend input_qua;
	main_ui(QWidget *parent = Q_NULLPTR);
	~main_ui();
protected:
	void paintEvent(QPaintEvent*) {
		QPainter painter(this);
		painter.drawImage(0, 0, image);
	}
private:
	Ui::main_ui ui;
	QImage image;
	graph mp;
	Dijkstra_algorithm dijkstra;
	void main_ui::Paint();
	//void draw_point(const point&);
private slots:
	void on_re__clicked();//返回
	void on_add__clicked();//加点
	void on_clear__clicked();//清空画板
	void on_st__clicked();//设置起点
	void on_ed__clicked();//设置终点
	void on_cal__clicked();//求最短路
	void on_newe__clicked();//加边
	//void on_del__clicked();
	//void on_rme__clicked();
};

