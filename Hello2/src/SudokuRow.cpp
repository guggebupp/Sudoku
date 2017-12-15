/*
 * SudokuRow.cpp
 *
 *  Created on: 14 dec. 2017
 *      Author: olssongr
 */

#include "SudokuRow.h"
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

SudokuRow::SudokuRow() {
	myRows.clear();
}

SudokuRow::~SudokuRow() {
	myRows.clear();
}

bool SudokuRow::validateAll(vector<vector<pair<bool, int>>> masterData) {
	myRows.clear();
	for_each(masterData.begin(), masterData.end(), [this](vector<pair<bool, int>> row){
		vector<int> newRow;
				for_each(row.begin(), row.end(), [&newRow](pair<bool, int> p){
					newRow.push_back(p.second);
				});
				myRows.push_back(newRow);
	});

	bool validated = true;
	for_each(myRows.begin(), myRows.end(), [this, &validated](vector<int> row){
		validated &= validate(row);
	});

	return validated;
}



