#include "result.h"
#include<stack>
using namespace std;
result::result(main_ui&m,QWidget *parent)
	: QWidget(parent),ma(m)
{
	ui.setupUi(this);
	//this->setWindowModality(Qt::ApplicationModal);
	paper = QImage(2000, 1500, QImage::Format_RGB32);  //画布的初始化大小，使用32位颜色
	QColor backColor = qRgb(255, 255, 255);    //画布初始化背景色使用白色
	paper.fill(backColor);//对画布进行填充
	Paint();
}

result::~result()
{

}
void result::Paint()
{
	double res = ma.dijkstra.dijkstra();
	QPainter painter(&paper);
	painter.setRenderHint(QPainter::Antialiasing, true);
	int pointx = 250, pointy = 1000;//确定坐标轴起点坐标，
	int width = 1900 - pointx, height = 1400;//确定坐标轴宽度跟高度 
	painter.drawLine(pointx, pointy, width + pointx, pointy);//坐标轴x宽度为width
	painter.drawLine(pointx, pointy - height, pointx, pointy);//坐标轴y高度为height
	for (auto it : ma.mp.pts)
	{
		QString text = QString::fromStdString(it.name);
		QPen pen;
		pen.setColor(Qt::blue);
		pen.setWidth(20);
		painter.setPen(pen);
		painter.drawPoint(pointx + it.x, pointy - it.y);
		QPen word;
		word.setColor(Qt::green);
		painter.setPen(word);
		QString pos = text + "(" + QString::number(it.x) + "," + QString::number(it.y) + ")";
		painter.drawText(pointx + it.x + 10, pointy - it.y - 5, pos);
	}
	QPen pen;
	pen.setColor(Qt::black);
	pen.setWidth(2);
	painter.setPen(QPen(Qt::black, 2));
	painter.setRenderHint(QPainter::Antialiasing, true);

	for (int i=0;i<ma.mp.edges.size();++i)
	{
		point p1 = ma.mp.get_p(i);
		for (int j = 0; j < ma.mp.edges[i].size(); ++j)
		{
			point p2 = ma.mp.edges[i][j].first;
			if (p1 != point() && p2 != point()) {
				int pointx = 250, pointy = 1000;//确定坐标轴起点坐标，
				painter.drawLine(pointx + p1.x, pointy - p1.y, pointx + p2.x, pointy - p2.y);
			}
		}
	}

	QPen penDegree;
	penDegree.setColor(Qt::black);
	penDegree.setWidth(2);
	painter.setPen(penDegree);
	//画上x轴刻度线
	for (int i = 0; i < 15; i++)//分成15份
	{
		//选取合适的坐标，绘制一段长度为4的直线，用于表示刻度
		painter.drawLine(pointx + (i + 1) * 100, pointy, pointx + (i + 1) * 100, pointy + 4);
		painter.drawText(pointx + (i + 0.8) * 100, pointy + 10, QString::number((int)((i + 1) * ((double)100))));
	}

	//y轴刻度线
	double _maStep = (double)height / 10;//y轴刻度间隔需根据最大值来表示
	for (int i = 0; i < 9; i++)
	{
		//主要就是确定一个位置，然后画一条短短的直线表示刻度。
		painter.drawLine(pointx, pointy - (i + 1) * 100, pointx - 4, pointy - (i + 1) * 100);
		painter.drawText(pointx - 20, pointy - (i + 1) * 100, QString::number((int)((i + 1) * ((double)100))));
	}
	if (ma.mp.is_empty()) return;
	if (ma.dijkstra.path.size() == 1) return;
	if (ma.dijkstra.start == point() || ma.dijkstra.dest == point()) return;
	pen.setColor(Qt::red);
	painter.setPen(QPen(Qt::red, 2));//连线
	unsigned int pre=ma.mp.get_order(ma.dijkstra.dest);
	unsigned int aft = ma.dijkstra.path[pre];
	stack<point> s;
	s.push(ma.mp.get_p(pre));

	point f,r;
	while(aft!=-1)
	{

		f = ma.mp.get_p(aft);
		s.push(f);
		r = ma.mp.get_p(pre);
		painter.setPen(QPen(Qt::red));
		painter.drawLine(pointx + r.x, pointy - r.y, pointx + f.x, pointy - f.y);
		painter.setPen(QPen(Qt::darkYellow));
		painter.drawText((pointx + r.x + pointx + f.x) / 2 - 10, (pointy - r.y + pointy - f.y) / 2, QString::number(line(f,r).lenth()));
		pre = aft;
		aft = ma.dijkstra.path[aft];
	}
	QString result= QString::fromLocal8Bit("最短路径全长为：");
	result += QString::number(res)+" (";
	result += QString::fromStdString((s.top().name));
	s.pop();
	while (!s.empty())
	{
		result +="->"+ QString::fromStdString((s.top().name));
		s.pop();
	}
	result += ")";
	painter.setPen(QPen(Qt::darkGray));
	painter.drawText(pointx+50, pointy-950,result);
}
void result::on_close__clicked()
{
	this->close();
}