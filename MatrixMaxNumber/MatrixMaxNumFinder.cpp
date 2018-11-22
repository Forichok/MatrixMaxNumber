#include "stdafx.h"
#include "MatrixMaxNumFinder.h"
#include <iostream>
#include "LineGraph.h"
#include <ctime>
#include <string>

using namespace std;
MatrixMaxNumFinder::MatrixMaxNumFinder()
{
}

MatrixMaxNumFinder::MatrixMaxNumFinder(vector<vector<int>> matrix)
{
	_matrix = matrix;
}


/**
 * \brief 
 * \param i rows
 * \param j columns
 */
MatrixMaxNumFinder::MatrixMaxNumFinder(const int i, const int j)
{
	srand(time(0));
	_matrix = vector<vector<int>>(i);
	for (auto column=0; column<i;column++)
	{
		vector<int> new_column(j);
		for (auto row = 0; row<j; row++)
		{			
			new_column[row] =rand()  % 10;
		}
		_matrix[column] = new_column;
	}
}

void MatrixMaxNumFinder::print_matrix()
{
	for (vector<int> column : _matrix)
	{
		for (int num : column)
		{
			std::cout << num << " ";
		}
		std::cout << endl;
	}
}

std::string MatrixMaxNumFinder::find_max()
{
	vector<double> max_nums;
	double max = 0;
	std::string str_num="";
	for (int i = 0; i < _matrix.size();i++)
	{
		for (int j = 0; j < _matrix[0].size();j++)
		{
			auto tmp = get_max_from_point(i, j);
			auto num = std::stod(tmp);
			if(num>max)
			{
				max = num;
				str_num = tmp;
			}
		}		
	}
	return str_num;
}

std::string MatrixMaxNumFinder::get_max_from_point(int i, int j)
{
	//if (_matrix[i][j] == 0) return 0;
	LineGraph line_graph(i, j, _matrix);
	std::string max_num = line_graph.get_max();
	if (max_num == "") return "0";
	return max_num;
}

MatrixMaxNumFinder::~MatrixMaxNumFinder()
{
}




