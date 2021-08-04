#pragma once
#include"navigation.h"
#include <QWidget>
#include "ui_main_ui.h"
#include<QPaintEvent> //���ڻ滭�¼�
#include<QtGui> //�����õ��Ŀؼ�
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
	void on_re__clicked();//����
	void on_add__clicked();//�ӵ�
	void on_clear__clicked();//��ջ���
	void on_st__clicked();//�������
	void on_ed__clicked();//�����յ�
	void on_cal__clicked();//�����·
	void on_newe__clicked();//�ӱ�
	//void on_del__clicked();
	//void on_rme__clicked();
};

