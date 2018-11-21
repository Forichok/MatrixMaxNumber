#pragma once
#include "vector"
using namespace std;
class MatrixMaxNumFinder // i - rows
						 // j - columns
{
public:
	MatrixMaxNumFinder();
	
	MatrixMaxNumFinder(int i,int j);

	void print_matrix();

	~MatrixMaxNumFinder();
private: 
	/**
	 * \brief 
	 */
	vector<vector<int>> _matrix{};
	
};

