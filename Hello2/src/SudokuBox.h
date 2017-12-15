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

using namespace std;

class SudokuBox
: public SudokuValidator {
private:
	std::vector<std::vector<int>> myBoxes;
public:
	SudokuBox();
	virtual ~SudokuBox();
	bool validateAll(vector<vector<pair<bool, int>>> masterData);
};

#endif /* SUDOKUBOX_H_ */

