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
	auto res1 =
			Http().get(
					"http://openshifttest-goran2.193b.starter-ca-central-1.openshiftapps.com/rest/sudoku/result/1513343929086").exec();
	cout << res1.body << endl;

//	string s =
//				"{\"data\":[1,0,0,0,7,0,0,0,0,0,4,0,0,0,0,0,9,0,2,0,0,0,4,9,0,0,0,0,0,8,4,0,6,2,0,0,0,6,0,0,0,0,4,0,3,4,0,3,5,0,8,0,0,0,0,0,1,7,0,3,0,0,0,0,0,0,0,8,0,0,1,0,0,0,0,1,0,0,6,0,5],\"status\":null}";
	string s = res1.body;
	s.erase(0, 9);
	cout << s << endl;
	s.erase(161, 16);
	cout << s << endl;
	vector<int> v1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ',') {
			v1.push_back((int) s[i] - 48);
		}
	}

	vector<vector<pair<bool, int>>> v;
	int j = 0;
	vector<pair<bool, int>> row;
	for (int i = 0; i < s.size(); i++) {
		if (j % 9 == 0) {
			row.clear();
		}
		if (s[i] != ',') {
			int value = (int) s[i] - 48;
			row.push_back({value != 0, value});
			j++;
			if (j % 9 == 0) {
						v.push_back(row);
			}
		}


	}

//	vector<vector<pair<bool, int>>> v =
//	{
//		{	{	v1[0] != 0, v1[0]}, {false, 0}, {false, 0}, {false, 0}, {true, 7}, {false, 0}, {false, 0}, {false, 0}, {false, 0}},
//		{	{	false, 0}, {true, 4}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 9}, {false, 0}},
//		{	{	true, 2}, {false, 0}, {false, 0}, {false, 0}, {true, 4}, {true, 9}, {false, 0}, {false, 0}, {false, 0}},
//		{	{	false, 0}, {false, 0}, {true, 8}, {true, 4}, {false, 0}, {true, 6}, {true, 2}, {false, 0}, {false, 0}},
//		{	{	false, 0}, {true, 6}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 4}, {false, 0}, {true, 3}},
//		{	{	true, 4}, {false, 0}, {true, 3}, {true, 5}, {false, 0}, {true, 8}, {false, 0}, {false, 0}, {false, 0}},
//		{	{	false, 0}, {false, 0}, {true, 1}, {true, 7}, {false, 0}, {true, 3}, {false, 0}, {false, 0}, {false, 0}},
//		{	{	false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 8}, {false, 0}, {false, 0}, {true, 1}, {false, 0}},
//		{	{	false, 0}, {false, 0}, {false, 0}, {true, 1}, {false, 0}, {false, 0}, {true, 6}, {false, 0}, {true, 5}}
//	};

	SudokuData sudokuData = SudokuData(v);
	sudokuData.getResult();

	return;
}
