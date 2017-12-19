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
#include "SudokuList.h"
using namespace std;

// for a more readable name
using Http = asoni::Handle;

void Sudoku::solvesudoku() {
	cout << "!!!Start sudoku!!!" << endl; // prints !!!Hello World!!!
	auto list =
			Http().get(
					"http://openshifttest-goran2.193b.starter-ca-central-1.openshiftapps.com/rest/sudoku/list").exec();
	cout << list.body << endl;

	SudokuList sudokuList = SudokuList();
	vector<pair<string, string>> sudokus = sudokuList.translate(list.body);
	for_each(sudokus.begin(), sudokus.end(),
			[](pair<string, string> sudoku) {
				if(sudoku.second == "IDLE") {
					cout << "Solving: " << sudoku.first << endl;
					auto res1 =
					Http().get(
							"http://openshifttest-goran2.193b.starter-ca-central-1.openshiftapps.com/rest/sudoku/result/" + sudoku.first).exec();


					//	string s =
					//				"{\"data\":[1,0,0,0,7,0,0,0,0,0,4,0,0,0,0,0,9,0,2,0,0,0,4,9,0,0,0,0,0,8,4,0,6,2,0,0,0,6,0,0,0,0,4,0,3,4,0,3,5,0,8,0,0,0,0,0,1,7,0,3,0,0,0,0,0,0,0,8,0,0,1,0,0,0,0,1,0,0,6,0,5],\"status\":null}";
					string s = res1.body;
					s.erase(0, 9);

					s.erase(161, 16);

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
							row.push_back( {value != 0, value});
							j++;
							if (j % 9 == 0) {
								v.push_back(row);
							}
						}

					}


					SudokuData sudokuData = SudokuData(v);
					vector<vector<pair<bool, int>>> res = sudokuData.getResult();
					string result = "{\"data\":[";
					for_each(res.begin(), res.end(), [&result](vector<pair<bool, int>> row) {
								for_each(row.begin(), row.end(), [&result](pair<bool, int> pa) {
											result.append((char)1, pa.second+48);
											result.append(",");
										});
							});
					result.pop_back();
					result.append("],\"status\":\"SOLVED\"}");

					auto resPost =
					Http().content("application/json", result).post(
							"http://openshifttest-goran2.193b.starter-ca-central-1.openshiftapps.com/rest/sudoku/solved/" + sudoku.first).exec();
					cout << resPost.body << endl;
				}else{
					cout << "Already Solved id: " << sudoku.first << " , Status: " << sudoku.second << endl;
				}
			});

	return;
}
