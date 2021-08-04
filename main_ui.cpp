#include "main_ui.h"
#include"login.h"
#include"navigation.h"
#include"input_tri.h"
#include"input_qua.h"
#include<QPaintEvent> //用于绘画事件
#include<QtGui> //引入用到的控件
#include<qpen.h>
#include"result.h"
main_ui::main_ui(QWidget *parent)
	: QWidget(parent),dijkstra(mp)
{
	ui.setupUi(this);
	image = QImage(2000, 1500, QImage::Format_RGB32);  //画布的初始化大小，使用32位颜色
	QColor backColor = qRgb(255, 255, 255);    //画布初始化背景色使用白色
	image.fill(backColor);//对画布进行填充
	Paint();
	
}
main_ui::~main_ui()
{
}
void main_ui::on_re__clicked()
{
	login* log = new login;
	this->close();
	log->show();
}
void main_ui::Paint()
{
	QPainter painter(&image);
	painter.setRenderHint(QPainter::Antialiasing, true);//设置反锯齿模式，好看一点
	int pointx = 250, pointy = 1000;//确定坐标轴起点坐标，
	int width = 1900 - pointx, height = 1400;//确定坐标轴宽度跟高度 
	painter.drawLine(pointx, pointy, width + pointx, pointy);//坐标轴x宽度为width
	painter.drawLine(pointx, pointy - height, pointx, pointy);//坐标轴y高度为height

	QPen penDegree;
	penDegree.setColor(Qt::black);
	penDegree.setWidth(2);
	painter.setPen(penDegree);

	//画上x轴刻度线
	for (int i = 0; i < 15; i++)//分成10份
	{
		//选取合适的坐标，绘制一段长度为4的直线，用于表示刻度
		painter.drawLine(pointx + (i + 1) * 100, pointy, pointx + (i + 1) * 100, pointy + 4);
		painter.drawText(pointx + (i + 0.8) * 100,pointy + 10, QString::number((int)((i + 1) * ((double)100))));
	}

	//y轴刻度线
	double _maStep = (double)height/ 10;//y轴刻度间隔需根据最大值来表示
	for (int i = 0; i < 9; i++)
	{
		//主要就是确定一个位置，然后画一条短短的直线表示刻度。
		painter.drawLine(pointx, pointy - (i + 1) * 100,pointx - 4, pointy - (i + 1) * 100);
		painter.drawText(pointx - 20, pointy - (i + 1) * 100, QString::number((int)((i + 1) * ((double)100))));
	}

	
}

void main_ui::on_add__clicked()
{
	input_tri* input = new input_tri(1,*this);
	input->show();
	
}
void main_ui::on_clear__clicked()
{
	mp.clear();
	image = QImage(2000, 1500, QImage::Format_RGB32); 
	QColor backColor = qRgb(255, 255, 255);
	image.fill(backColor);
	Paint();
	
}
/*void main_ui::on_del__clicked()
{
	input_tri* input = new input_tri(2,*this);
	input->show();
}*/
void main_ui::on_st__clicked()
{
	input_tri* input = new input_tri(3, *this);
	input->show();
}
void main_ui::on_ed__clicked()
{
	input_tri* input = new input_tri(4, *this);
	input->show();
}
void main_ui::on_cal__clicked()
{
	result* res = new result(*this);
	res->show();
}
void main_ui::on_newe__clicked()
{
	input_qua* input = new input_qua(1, *this);
	input->show();
}
/*void main_ui::on_rme__clicked()
{
	input_qua* input = new input_qua(2, *this);
	input->show();
}*/