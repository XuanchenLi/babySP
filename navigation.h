#pragma once
#include<iostream>
#include<vector>
#include<map>
#include <QWidget>
#include<string>
using namespace std;
class line;
class graph;
extern class result;
extern class main_ui;
extern class input_qua;
extern class input_tri;
class Dijkstra_algorithm;
class point
{
	friend input_qua;
	friend input_tri;
	friend main_ui;
	friend result;
	friend line;
	friend graph;
	inline friend bool operator<(const point&, const point&);
	friend ostream& operator<<(ostream&, const point&);
private:
	string name;
	double x, y;
public:
	const double& get_x()const { return x; }//�ⲿ���ʺ�����
	const double& get_y()const { return y; }//�ⲿ����������
	point(string nm="Undefined", double a = 0, double b = 0) :name(nm),x(a), y(b) {}//���캯��
	point(const point&) = default;
	~point() = default;
	point& operator=(const point& b) = default;
	bool operator==(const point& b)const
	{
		return x == b.x && y == b.y && name == b.name;
	}
	bool operator!=(const point& b)const
	{
		return x != b.x || y != b.y || name != b.name;
	}
};
class line
{
	friend graph;
	friend bool operator<(const line&, const line&);
private:
	point p1, p2;//����ȷ��ֱ��
	double distance;
public:
	const point& get_left()const { return p1; }
	const point& get_right()const { return p2; }
	line(double x1, double y1, string n1, double x2, double y2, string n2) :p1(n1, x1, y1), p2(n2, x2, y2)
	{
		if (p1 < p2) swap(p1, p2);
		distance = lenth();
	}
	line(const point& a, const point& b) :p1(a), p2(b)
	{
		if (p1 < p2)swap(p1, p2);
		distance = lenth();
	}
	bool operator==(const line& b) { return p1 == b.p1 && p2 == b.p2; }
	line& operator=(const line&) = default;
	double lenth()const;

};

class graph
{
	friend Dijkstra_algorithm;
	friend main_ui;
	friend result;
	friend input_tri;
private:
	std::map<point, unsigned int>order;//�㵽��ŵ�ӳ��
	std::vector<std::vector<pair<point, double> > >edges;//�ڽӱ�
	std::vector<point>pts;//�㼯
	unsigned int num_of_pts, num_of_edges;//�����ͱ���
	void clear();//���

public:
	graph();
	graph(const graph&) = default;
	~graph() = default;
	void add_e(const line&);//�ӱ�
	void add_p(const point&);//�ӵ�
	//void rm_e(const line&);
	//void rm_p(const point&);//���ȫ���ı�
	const unsigned int& p_size()const { return num_of_pts; }//�����ʵ���
	const unsigned int& e_size()const { return num_of_edges; }//�����ʱ���
	unsigned int get_order(const point&)const;//�õ���ı��
	inline bool is_exist(const point&)const;//���Ƿ����
	bool is_exist(const line&)const;//���Ƿ����
	bool is_e_empty()const { return num_of_edges == 0; }//���Ƿ�Ϊ��
	bool is_p_empty()const { return num_of_pts == 0; }//���Ƿ�Ϊ��
	bool is_empty()const { return is_e_empty() && is_p_empty(); }//ͼ�Ƿ�Ϊ��
	point get_p(unsigned int num);//���ͨ����ŷ��ʵ�
};
class Dijkstra_algorithm
{
	friend result;
private:
	const graph& G;
	point start;
	point dest;
	vector<unsigned int> path;
public:
	Dijkstra_algorithm(const graph& g, const point& a=point(), const point& b=point()) :G(g), start(a), dest(b) {}
	Dijkstra_algorithm(const Dijkstra_algorithm&) = default;
	void set_st(const point&);//ȷ�����
	void set_dest(const point&);//ȷ���յ�
	double dijkstra();//�������·��������С����
};
