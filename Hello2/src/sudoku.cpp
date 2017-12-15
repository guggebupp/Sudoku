//============================================================================
// Name        : Hello2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "restless.hpp"
#include "sudoku.hpp"
#include "sudokuData.hpp"
using namespace std;

// for a more readable name
using Http = asoni::Handle;

void Sudoku::solvesudoku() {
	cout << "!!!Start sudoku!!!" << endl; // prints !!!Hello World!!!
	auto res1 = Http().get("http://openshifttest-goran2.193b.starter-ca-central-1.openshiftapps.com/rest/members/ping")
	            .exec();
	cout << res1.body << endl;

	vector<vector<pair<bool, int>>> v =
	{
			{{true, 1},{false, 0},{false, 0},{false, 0},{true, 7},{false, 0},{false, 0},{false, 0},{false, 0}},
			{{false, 0},{true, 4},{false, 0},{false, 0},{false, 0},{false, 0},{false, 0},{true, 9},{false, 0}},
			{{true, 2},{false, 0},{false, 0},{false, 0},{true, 4},{true, 9},{false, 0},{false, 0},{false, 0}},
			{{false, 0},{false, 0},{true, 8},{true, 4},{false, 0},{true, 6},{true, 2},{false, 0},{false, 0}},
			{{false, 0},{true, 6},{false, 0},{false, 0},{false, 0},{false, 0},{true, 4},{false, 0},{true, 3}},
			{{true, 4},{false, 0},{true, 3},{true, 5},{false, 0},{true, 8},{false, 0},{false, 0},{false, 0}},
			{{false, 0},{false, 0},{true, 1},{true, 7},{false, 0},{true, 3},{false, 0},{false, 0},{false, 0}},
			{{false, 0},{false, 0},{false, 0},{false, 0},{true, 8},{false, 0},{false, 0},{true, 1},{false, 0}},
			{{false, 0},{false, 0},{false, 0},{true, 1},{false, 0},{false, 0},{true, 6},{false, 0},{true, 5}}
	};

	SudokuData sudokuData = SudokuData(v);
	sudokuData.getResult();







	return;
}
