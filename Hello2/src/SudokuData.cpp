/*
 * SudokuData.cpp
 *
 *  Created on: 14 dec. 2017
 *      Author: olssongr
 */

#include "sudokuData.hpp"
#include "sudokuRow.h"
#include "sudokuCol.h"
#include "sudokuBox.h"
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

SudokuData::SudokuData(std::vector<std::vector<pair<bool, int>>>inData) : masterData(inData) {

}

SudokuData::~SudokuData() {
	// TODO Auto-generated destructor stub
}

vector<vector<pair<bool, int>>> SudokuData::getResult() {
	for_each(masterData.begin(), masterData.end(), [this](vector<pair<bool, int>> row){
		for_each(row.begin(), row.end(), [](pair<bool, int> pa){
			cout << pa.second << " ";

		});
		cout << endl;
	});

	std::vector<std::vector<pair<bool, int>>> result;
	SudokuBox boxData = SudokuBox();
	SudokuCol colData = SudokuCol();
	SudokuRow rowData = SudokuRow();

	bool validated = boxData.validateAll(masterData) && colData.validateAll(masterData) && rowData.validateAll(masterData);
	if(validated) {

		validated = false;
		bool rollback = false;
		while(!validated) {
			//And then something magical happen...
			for(int row = 0;row<9;row++) {
				for(int col = 0;col<9;col++) {

					if(!masterData[row][col].first) {
						validated = false;
						rollback = false;
						while(!validated && masterData[row][col].second< 9) {
							masterData[row][col].second = masterData[row][col].second+1;
							validated = boxData.validateAll(masterData) && colData.validateAll(masterData) && rowData.validateAll(masterData);
						}
						//cout << "test:" << row << " " << col << " " << masterData[row][col].second << endl;
					}else{
						//cout << "fixed: " << row << " " << col << " " << masterData[row][col].second << endl;
					}
					if((!validated && !masterData[row][col].first) || rollback) {
						if(!masterData[row][col].first)
							masterData[row][col].second = 0;
						rollback = true;
						if(col > 0) {
							col -= 2;

						}else if(row > 0) {
							row -= 1;
							col = 7;
						}else {
							cout << "ERROR!!!" << endl;
							return result;
						}

					}
					//Col increased
				}
				//Row increased
			}
			validated = boxData.validateAll(masterData) && colData.validateAll(masterData) && rowData.validateAll(masterData);

		}

	} else {
		cout << "Error on indata" << endl;
	}
	for_each(masterData.begin(), masterData.end(), [this](vector<pair<bool, int>> row){
			for_each(row.begin(), row.end(), [](pair<bool, int> pa){
				cout << pa.second << " ";

			});
			cout << endl;
		});

	return result;

}

