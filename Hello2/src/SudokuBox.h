/*
 * SudokuBox.h
 *
 *  Created on: 14 dec. 2017
 *      Author: olssongr
 */

#ifndef SUDOKUBOX_H_
#define SUDOKUBOX_H_
#include "SudokuValidator.h"
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class SudokuBox
: public SudokuValidator {
private:
	std::vector<std::vector<int>> myBoxes;
public:
	SudokuBox();
	virtual ~SudokuBox();
	bool validateAll(vector<vector<pair<bool, int>>> masterData);
	vector<int> findFixed(vector<vector<pair<bool, int>>> masterData, vector<int> avaliable, int boxToCheck);
	bool valuePossible(vector<vector<pair<bool, int>>> masterData, int value, int boxToCheck, int rowToCheck, int colToCheck);
};

#endif /* SUDOKUBOX_H_ */

