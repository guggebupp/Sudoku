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
	for_each(masterData.begin(), masterData.end(), [this](vector<pair<bool, int>> row) {
		vector<int> newRow;
		for_each(row.begin(), row.end(), [&newRow](pair<bool, int> p) {
					newRow.push_back(p.second);
				});
		myRows.push_back(newRow);
	});

	bool validated = true;
	for_each(myRows.begin(), myRows.end(), [this, &validated](vector<int> row) {
		validated &= validate(row);
	});

	return validated;
}

vector<int> SudokuRow::findFixed(vector<vector<pair<bool, int>>> masterData, vector<int>avaliable, int rowToCheck){

	for_each(masterData[rowToCheck].begin(), masterData[rowToCheck].end(), [&avaliable](pair<bool, int> row){
									std::vector<int>::iterator iter = avaliable.begin();
								    std::vector<int>::iterator endIter = avaliable.end();
								    for(; iter != endIter; ++iter)
								    {
								        if(*iter == row.second)
								        {
					//			        	cout << " Remove1 " << row[i].second << endl;
								        	avaliable.erase(iter);
								        }
								    }
					});

		return avaliable;
}



