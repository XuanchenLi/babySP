#include "input_qua.h"
#include <qpen.h>
#include "navigation.h"
#include<QPaintEvent> //用于绘画事件
#include<QtGui> //引入用到的控件
input_qua::input_qua(int o, main_ui& m,QWidget *parent)
	: QWidget(parent), ma(m), op(o)
{
	ui.setupUi(this);
	this->setWindowModality(Qt::ApplicationModal);
}

input_qua::~input_qua()
{

}
void input_qua::on_re__clicked()
{
	point p1, p2;
	QString text1 = ui.name->toPlainText();
	p1.name = text1.toStdString();
	p1.x = ui.ordx->value();
	p1.y = ui.ordy->value();
	text1 = ui.name_2->toPlainText();
	p2.name = text1.toStdString();
	p2.x = ui.ordx_2->value();
	p2.y = ui.ordy_2->value();
	if (p1 == point() || p2 == point()) return;
	if (!ma.mp.is_exist(p1) || !ma.mp.is_exist(p2)) return;
	line edge = line(p1, p2);
	if (op == 1)
	{
		if (ma.mp.is_exist(edge)) return;
		ma.mp.add_e(edge);
		QPen pen;
		pen.setColor(Qt::black);

		QPainter painter(&(ma.image));
		painter.setPen(QPen(Qt::black, 2));
		painter.setRenderHint(QPainter::Antialiasing, true);
		int pointx = 250, pointy = 1000;//确定坐标轴起点坐标，
		painter.drawLine(pointx+edge.get_left().x, pointy - edge.get_left().y, pointx + edge.get_right().x, pointy- edge.get_right().y);
		painter.setPen(QPen(Qt::darkYellow));
		painter.drawText((pointx + edge.get_left().x+ pointx + edge.get_right().x)/2-10, (pointy - edge.get_left().y+ pointy - edge.get_right().y)/2, QString::number(edge.lenth()));
	}
	/*else if (op == 2)
	{
		if (!ma.mp.is_exist(edge)) return;
		ma.mp.rm_e(edge);
		QPen pen;
		pen.setColor(Qt::white);

		QPainter painter(&(ma.image));
		painter.setPen(pen);
		painter.setPen(QPen(Qt::white, 2));
		painter.setRenderHint(QPainter::Antialiasing, true);
		int pointx = 250, pointy = 1000;//确定坐标轴起点坐标，
		painter.drawLine(pointx + edge.get_left().x, pointy - edge.get_left().y, pointx + edge.get_right().x, pointy - edge.get_right().y);
		painter.drawLine(pointx + edge.get_left().x, pointy - edge.get_left().y, pointx + edge.get_right().x, pointy - edge.get_right().y);

	}
	*/
	this->close();
	return;

}