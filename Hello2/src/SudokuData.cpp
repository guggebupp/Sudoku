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

using namespace std;

SudokuData::SudokuData(std::vector<std::vector<pair<bool, int>>>inData) : masterData(inData) {

}

SudokuData::~SudokuData() {
	// TODO Auto-generated destructor stub
}

vector<vector<pair<bool, int>>> SudokuData::getResult() {
	return masterData;
}

string SudokuData::solveSoduko() {
	SudokuBox boxData = SudokuBox();
	SudokuCol colData = SudokuCol();
	SudokuRow rowData = SudokuRow();

	bool validated = boxData.validateAll(masterData)
			&& colData.validateAll(masterData)
			&& rowData.validateAll(masterData);
	if (validated) {

		cout << "Find fixed values" << endl;

		bool changed = true;
		while (changed) {
			changed = false;
			for (int row = 0; row < 9; row++) {
				for (int col = 0; col < 9; col++) {
					vector<int> avaliable;
					for (int j = 1; j < 10; j++) {
						avaliable.push_back(j);
					}
					avaliable = boxData.findFixed(masterData, avaliable,
							row / 3 * 3 + col / 3);
					avaliable = rowData.findFixed(masterData, avaliable, row);

					avaliable = colData.findFixed(masterData, avaliable, col);

					if (avaliable.size() == 1) {
						masterData[row][col].second = avaliable[0];
						changed = true;
					}
				}
			}
		}

		changed = true;
		while (changed) {
			changed = false;
			//Check each box
			for (int box = 0; box < 9; box++) {
				//Check each value for each position in box
				for (int value = 0; value < 9; value++) {
					vector<pair<int, int>> possiblePos;
					for (int rowInBox = 0; rowInBox < 3; rowInBox++) {
						for (int colInBox = 0; colInBox < 3; colInBox++) {
							if (boxData.valuePossible(masterData, value, box,
									(rowInBox + (box / 3 * 3)),
									(colInBox + ((box % 3) * 3))

									)) {
								possiblePos.push_back(
										{ (rowInBox + (box / 3 * 3)), (colInBox
												+ ((box % 3) * 3)) });
							}
						}
					}
					if (possiblePos.size() == 1) {
						cout << "Found pos: " << value << " , "
								<< possiblePos[0].first << " , "
								<< possiblePos[0].second << endl;
						masterData[possiblePos[0].first][possiblePos[0].second].second =
								value;
						masterData[possiblePos[0].first][possiblePos[0].second].first =
								true;
						changed = true;
					}
				}
			}
		}

		validated = false;
		bool rollback = false;
		while (!validated) {
			//And then something magical happen...
			for (int row = 0; row < 9; row++) {
				for (int col = 0; col < 9; col++) {

					if (!masterData[row][col].first) {
						validated = false;
						rollback = false;
						while (!validated && masterData[row][col].second < 9) {
							masterData[row][col].second =
									masterData[row][col].second + 1;
							validated = boxData.validateAll(masterData)
									&& colData.validateAll(masterData)
									&& rowData.validateAll(masterData);
						}
						//cout << "test:" << row << " " << col << " " << masterData[row][col].second << endl;
					} else {
						//cout << "fixed: " << row << " " << col << " " << masterData[row][col].second << endl;
					}
					if ((!validated && !masterData[row][col].first)
							|| rollback) {
						if (!masterData[row][col].first)
							masterData[row][col].second = 0;
						rollback = true;
						if (col > 0) {
							col -= 2;

						} else if (row > 0) {
							row -= 1;
							col = 7;
						} else {
							cout << "ERROR!!!" << endl;
							return "ERROR";
						}
					}
					//Col increased
				}
				//Row increased
				cout << "Row: " << row << " " << masterData[row][0].second
						<< " " << masterData[row][1].second << " "
						<< masterData[row][2].second << " "
						<< masterData[row][3].second << " "
						<< masterData[row][4].second << " "
						<< masterData[row][5].second << " "
						<< masterData[row][6].second << " "
						<< masterData[row][7].second << " "
						<< masterData[row][8].second << endl;
			}
			validated = boxData.validateAll(masterData)
					&& colData.validateAll(masterData)
					&& rowData.validateAll(masterData);

		}

	} else {
		cout << "Error on indata" << endl;
		return "ERROR";
	}

	return "SOLVED";

}

