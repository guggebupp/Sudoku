/*
 * SudokuRow.h
 *
 *  Created on: 14 dec. 2017
 *      Author: olssongr
 */



#ifndef SUDOKUROW_H_
#define SUDOKUROW_H_
#include "SudokuValidator.h"
#include <vector>
#include <utility>

using namespace std;

class SudokuRow: public SudokuValidator {
private:
	std::vector<std::vector<int>> myRows;
public:
	SudokuRow();

	virtual ~SudokuRow();
	bool validateAll(vector<vector<pair<bool, int>>> masterData);
	vector<int> findFixed(vector<vector<pair<bool, int>>> masterData, vector<int> avaliable, int rowToCheck);
};

#endif /* SUDOKUROW_H_ */
