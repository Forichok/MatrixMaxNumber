#pragma once
#include <list>
#include <vector>


class point
{
public:
	point()
	{
		
	}
	point(int i, int j)
	{
		this->i = i;
		this->j = j;
	}
	int i;
	int j;
};


class LineGraph
{	
	point _cur_point;	
	std::list<point> _used_points;

public:
	LineGraph(int i,int j, std::vector<std::vector<int>> matrix);
	LineGraph(point cur_point,std::list<point> used_points);
	LineGraph();
	~LineGraph();

	void move_next(int i, int j);	
	void find_lines();
	void get_available_points();
	bool is_point_used(int i, int j);
	std::string get_max();
};

