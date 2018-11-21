#include "stdafx.h"
#include "MatrixMaxNumFinder.h"
#include <iostream>

using namespace std;
MatrixMaxNumFinder::MatrixMaxNumFinder()
{
}


/**
 * \brief 
 * \param i rows
 * \param j columns
 */
MatrixMaxNumFinder::MatrixMaxNumFinder(const int i, const int j)
{
	_matrix = vector<vector<int>>(i);
	for (auto column=0; column<i;column++)
	{
		vector<int> new_column(j);
		for (auto row = 0; row<j; row++)
		{			
			new_column[row] = rand() % 10;
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

MatrixMaxNumFinder::~MatrixMaxNumFinder()
{
}




