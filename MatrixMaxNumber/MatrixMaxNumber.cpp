// MatrixMaxNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MatrixMaxNumFinder.h"
#include <iostream>


int main()
{
	//MatrixMaxNumFinder a(vector<vector<int>>{
	//	vector<int>{1,7,4},
	//	vector<int>{0,9,4},
	//	vector<int>{8,8,2}}
	//);
	MatrixMaxNumFinder a(5, 5);
	
	a.print_matrix();
	auto max = a.find_max();
	std::cout << endl << max.c_str() << endl;
	cin.get();
    return 0;
}

