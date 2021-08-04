#include "input_tri.h"
#include <qpen.h>
#include<QPaintEvent> //用于绘画事件
#include<QtGui> //引入用到的控件
input_tri::input_tri(int o,main_ui&m,QWidget *parent)
	: QWidget(parent),ma(m),op(o)
{
	ui.setupUi(this);
	this->setWindowModality(Qt::ApplicationModal);
}

input_tri::~input_tri()
{

}
void input_tri::on_re__clicked()
{
	QString text = ui.name->toPlainText();
	string str= text.toStdString();
	point p;
	p.name = str;
	p.x = ui.ordx->value();
	p.y = ui.ordy->value();
	if (p==point()||p.name=="\0") return;
	else if(op==1)
	{
		if (!ma.mp.is_exist(p))
		{
			ma.mp.add_p(p);
			QPen pen;
			pen.setColor(Qt::blue);
			pen.setWidth(20);
			QPainter painter(&(ma.image));
			painter.setRenderHint(QPainter::Antialiasing, true);
			painter.setPen(pen);
			int pointx = 250, pointy = 1000;//确定坐标轴起点坐标，
			painter.drawPoint(pointx + p.x, pointy - p.y);
			QPen word;
			word.setColor(Qt::green);
			painter.setPen(word);
			QString pos = text + "(" + QString::number(p.x) + "," + QString::number(p.y) + ")";
			painter.drawText(pointx + p.x+10, pointy - p.y - 5,pos);
		}
	}
	/*else if(op==2)
	{
		if (ma.mp.is_exist(p))
		{
			int num = ma.mp.get_order(p);
			for (int i = 0; i < ma.mp.edges[num].size(); ++i)
			{
				QPen pen;
				pen.setColor(Qt::white);

				QPainter painter(&(ma.image));
				painter.setPen(pen);
				painter.setPen(QPen(Qt::white, 2));
				painter.setRenderHint(QPainter::Antialiasing, true);
				int pointx = 250, pointy = 1000;//确定坐标轴起点坐标，
				painter.drawLine(pointx + p.x, pointy - p.y, pointx + ma.mp.edges[num][i].first.x, pointy - ma.mp.edges[num][i].first.y);
				painter.drawLine(pointx + p.x, pointy - p.y, pointx + ma.mp.edges[num][i].first.x, pointy - ma.mp.edges[num][i].first.y);
			}
			ma.mp.rm_p(p);
			QPen pen;
			pen.setColor(Qt::white);
			pen.setWidth(20);
			QPainter painter(&(ma.image));
			painter.setRenderHint(QPainter::Antialiasing, true);
			painter.setPen(pen);
			int pointx = 250, pointy = 1000;//确定坐标轴起点坐标，
			painter.drawPoint(pointx + p.x, pointy - p.y);
			QPen word;
			word.setColor(Qt::white);
			painter.setPen(word);
			painter.setRenderHint(QPainter::Antialiasing, true); painter.setRenderHint(QPainter::Antialiasing, true);
			QString pos = text + "(" + QString::number(p.x) + "," + QString::number(p.y) + ")";
			painter.drawText(pointx + p.x + 10, pointy - p.y - 5, pos);
			painter.drawText(pointx + p.x + 10, pointy - p.y - 5, pos);
			
		}
	}*/
	else if (op == 3)
	{
		ma.dijkstra.set_st(p);
	}
	else if (op == 4)
	{
		ma.dijkstra.set_dest(p);
	}
	
	this->close();
	return;

}
