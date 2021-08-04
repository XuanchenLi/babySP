#include<iostream>
#include<vector>
#include<map>
#include<math.h>
#include<string>
#include<queue>
#include"navigation.h"
const double INF = 1e9;
bool operator<(const point& a, const point& b)
{
	if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}
ostream& operator<<(ostream& out, const point& p)
{
	out << "(" << p.x << "," << p.y << ")";
	return out;
}
bool operator<(const line& a, const line& b)
{
	return a.lenth() < b.lenth();
}
double line::lenth()const
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));

}
graph::graph()
{
	order.clear();
	edges.clear();
	pts.clear();
	num_of_pts = num_of_edges = 0;
}
unsigned int graph::get_order(const point& p)const
{
	if (!is_exist(p)) return -1;
	else return order.at(p);//const也可用

}
bool graph::is_exist(const line& L)const
{
	if (!is_exist(L.p1) || !is_exist(L.p2)) return false;
	unsigned int ord = get_order(L.p1);
	if (ord == -1) return false;
	auto pos = find(edges[ord].begin(), edges[ord].end(), pair<point, double>(L.p2, L.distance));
	if (pos == edges[ord].end())return 0;
	else return 1;
}
bool graph::is_exist(const point& p)const
{
	return order.count(p) != 0;
}
void graph::add_p(const point& p)//点的下标从0开始。
{
	if (is_exist(p)) return;
	pts.push_back(p);
	edges.push_back(vector<pair<point, double> >());//为其创建一个容器
	order[p] = num_of_pts++;
}
void graph::add_e(const line& e)//不可有重边
{
	if (is_exist(e)) return;
	point from = e.p1, to = e.p2;
	const double dis = e.distance;//需要先把distance存出来，因为pair的构造函数中类line的私有成员不可见
	if (!is_exist(from)) return;
	if (!is_exist(to)) return;
	unsigned int num1 = get_order(from), num2 = get_order(to);
	if (num1 == -1) return;
	if (num2 == -1) return;
	edges[num1].push_back(pair<point, double>(e.p2, dis));//无向边
	edges[num2].push_back(pair<point, double>(e.p1, dis));
	num_of_edges++;
}
/*void graph::rm_e(const line& e)
{
	if (!is_exist(e)) return;
	if (is_e_empty()) return;
	unsigned int num1 = get_order(e.p1), num2 = get_order(e.p2);
	auto pos = find(edges[num1].begin(), edges[num1].end(), pair<point, double>(e.p2, e.distance));
	if (pos != edges[num1].end())
		edges[num1].erase(pos);
	pos = find(edges[num2].begin(), edges[num2].end(), pair<point, double>(e.p1, e.distance));
	if (pos != edges[num2].end())
		edges[num2].erase(pos);
}*/
/*void graph::rm_p(const point& p)
{
	if (is_p_empty() || !is_exist(p)) return;
	else
	{
		auto pos = find(pts.begin(), pts.end(), p);
		pts.erase(pos);//从点集中删除
		unsigned int num = get_order(p);
		num_of_edges -= edges[num].size();//更新边数
		edges.erase(edges.begin() + num);//删除出边
		auto it = order.find(p);
		order.erase(it);//从序号中删除
		for (auto it1 : edges)//删除入边
		{
			for (auto pp = it1.begin(); pp != it1.end(); ++pp)
			{
				if (pp->first == p)
				{
					pp=it1.erase(pp);
					break;
				}
			}
		}
		for (auto it : order)//修改后面节点的序号
		{
			if (it.second > num)
			{
				it.second=it.second-1;
			}
		}
		num_of_pts = pts.size();//更新点数

	}
}*/
void Dijkstra_algorithm::set_st(const point& p)
{
	if (!G.is_exist(p))
	{
		return;
	}
	start = p;
}
void Dijkstra_algorithm::set_dest(const point& p)
{
	if (!G.is_exist(p))
	{
		return;
	}
	dest = p;
}
bool operator<(const pair<unsigned int, double>& a, const pair<unsigned int, double>& b)
{
	return a.second < b.second;
}
double Dijkstra_algorithm::dijkstra()
{
	if (start == point() || dest == point()) return 0;
	path.clear();
	path.resize(G.num_of_pts);
	for (int i = 0; i < G.num_of_pts; ++i)
		path[i] = -1;
	vector<bool> vis(G.p_size(), 0);
	vector<double> dis(G.p_size(), INF);
	unsigned int st = G.get_order(start);
	unsigned int ed = G.get_order(dest);
	if (st == -1 || ed == -1) return -1;
	dis[st] = 0;
	priority_queue<pair<unsigned int, double> > q;
	q.push(pair<unsigned int, double>(st, 0.0));
	while (!q.empty())
	{
		pair<unsigned int, double> cur = q.top();
		q.pop();
		if (vis[cur.first] == 1) continue;
		vis[cur.first] = 1;
		int u = cur.first;
		for (auto it : G.edges[cur.first])
		{
			unsigned int v = G.get_order(it.first);
			if (dis[v] > dis[u] + it.second)
			{
				dis[v] = dis[u] + it.second;
				path[v] = u;
				q.push(pair<unsigned int, double>(v, dis[v]));
			}
		}
	}
	if (vis[ed] == 0) return -1;
	else return dis[ed]; 
}
void graph::clear()
{
	order.clear();
	edges.clear();
	pts.clear();
	num_of_edges = num_of_pts = 0;
}
point graph::get_p(unsigned int num)
{
	for (auto it : order)
	{
		if (it.second == num)
		{
			point p = it.first;
			return p;
		}
	}
	return point();
}