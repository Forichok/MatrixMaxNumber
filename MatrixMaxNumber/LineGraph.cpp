#include "stdafx.h"
#include "LineGraph.h"
#include <string>
#include <thread>
#include <iostream> 
static std::vector<std::list<point>> all_lines;
static std::vector<std::vector<int>> _matrix;

LineGraph::LineGraph(int i, int j, std::vector<std::vector<int>> matrix)
{
	_cur_point = point(i, j);
	_matrix = matrix;
}

LineGraph::LineGraph(point cur_point, std::list<point> used_points)
{
	_cur_point = cur_point;
	_used_points = used_points;
}

LineGraph::LineGraph()
{
	_cur_point = point(0, 0);
}


LineGraph::~LineGraph()
{
}

void LineGraph::move_next(int i, int j)
{
	point new_point(i, j);
	auto new_used_points = _used_points;
	new_used_points.insert(new_used_points.cend(), new_point);
	LineGraph new_line(new_point, new_used_points);
	new_line.get_available_points();
	
}

void LineGraph::find_lines()
{
	
}

void LineGraph::get_available_points()
{
	bool is_moved_next = false;
	if (_cur_point.i-1>=0 && !is_point_used(_cur_point.i-1,_cur_point.j))
	{
		move_next(_cur_point.i - 1, _cur_point.j);
		is_moved_next = true;
	}
	if (_cur_point.i + 1 < _matrix.size() && !is_point_used(_cur_point.i + 1, _cur_point.j))
	{
		move_next(_cur_point.i + 1, _cur_point.j);
		is_moved_next = true;
	}
	if (_cur_point.j - 1 >= 0 && !is_point_used(_cur_point.i, _cur_point.j-1))
	{
		move_next(_cur_point.i, _cur_point.j - 1);
		is_moved_next = true;
	}
	if (_cur_point.j + 1 < _matrix[0].size() && !is_point_used(_cur_point.i, _cur_point.j+1))
	{		
		move_next(_cur_point.i, _cur_point.j + 1);
		is_moved_next = true;
	}
	if (!is_moved_next && _matrix.size()*_matrix[0].size() == _used_points.size())
	{
		all_lines.insert(all_lines.end(), _used_points);
	}
	
}



bool LineGraph::is_point_used(int i, int j)
{
	for (point p : _used_points)
	{
		if (i == p.i && j == p.j)
		{
			return true;
		}
	}
	return false;
}

std::string LineGraph::get_max()
{
	get_available_points();
	double max = 0;
	std::string max_str="";
	for (auto line : all_lines)
	{
		std::string str_num="";
		for (auto point : line)	
		{
			//str_num.append()
			str_num += _matrix[point.i][point.j]+'0';
		}
		double num = std::stod(str_num);
		if (num > max)
		{
			max = num;
			max_str = str_num;
		}
	}
	all_lines.clear();
	return max_str;
}
