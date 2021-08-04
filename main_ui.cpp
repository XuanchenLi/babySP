#include "main_ui.h"
#include"login.h"
#include"navigation.h"
#include"input_tri.h"
#include"input_qua.h"
#include<QPaintEvent> //���ڻ滭�¼�
#include<QtGui> //�����õ��Ŀؼ�
#include<qpen.h>
#include"result.h"
main_ui::main_ui(QWidget *parent)
	: QWidget(parent),dijkstra(mp)
{
	ui.setupUi(this);
	image = QImage(2000, 1500, QImage::Format_RGB32);  //�����ĳ�ʼ����С��ʹ��32λ��ɫ
	QColor backColor = qRgb(255, 255, 255);    //������ʼ������ɫʹ�ð�ɫ
	image.fill(backColor);//�Ի����������
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
	painter.setRenderHint(QPainter::Antialiasing, true);//���÷����ģʽ���ÿ�һ��
	int pointx = 250, pointy = 1000;//ȷ��������������꣬
	int width = 1900 - pointx, height = 1400;//ȷ���������ȸ��߶� 
	painter.drawLine(pointx, pointy, width + pointx, pointy);//������x���Ϊwidth
	painter.drawLine(pointx, pointy - height, pointx, pointy);//������y�߶�Ϊheight

	QPen penDegree;
	penDegree.setColor(Qt::black);
	penDegree.setWidth(2);
	painter.setPen(penDegree);

	//����x��̶���
	for (int i = 0; i < 15; i++)//�ֳ�10��
	{
		//ѡȡ���ʵ����꣬����һ�γ���Ϊ4��ֱ�ߣ����ڱ�ʾ�̶�
		painter.drawLine(pointx + (i + 1) * 100, pointy, pointx + (i + 1) * 100, pointy + 4);
		painter.drawText(pointx + (i + 0.8) * 100,pointy + 10, QString::number((int)((i + 1) * ((double)100))));
	}

	//y��̶���
	double _maStep = (double)height/ 10;//y��̶ȼ����������ֵ����ʾ
	for (int i = 0; i < 9; i++)
	{
		//��Ҫ����ȷ��һ��λ�ã�Ȼ��һ���̶̵�ֱ�߱�ʾ�̶ȡ�
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