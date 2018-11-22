#pragma once
#include "vector"
using namespace std;
class MatrixMaxNumFinder // i - rows
						 // j - columns
{
public:
	MatrixMaxNumFinder();
	MatrixMaxNumFinder(vector<vector<int>> matrix);
	
	MatrixMaxNumFinder(int i,int j);

	void print_matrix();
	std::string find_max();
	std::string get_max_from_point(int i, int j);
	~MatrixMaxNumFinder();
private: 
	/**
	 * \brief 
	 */
	vector<vector<int>> _matrix{};
	
};

