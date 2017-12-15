/*
 * SudokuCol.h
 *
 *  Created on: 14 dec. 2017
 *      Author: olssongr
 */



#ifndef SUDOKUCOL_H_
#define SUDOKUCOL_H_

#include "SudokuValidator.h"
#include <vector>
#include <utility>

using namespace std;

class SudokuCol : public SudokuValidator {
private:
	std::vector<std::vector<int>> myCols;
public:
	SudokuCol();
	virtual ~SudokuCol();
	bool validateAll(vector<vector<pair<bool, int>>> masterData);
};

#endif /* SUDOKUCOL_H_ */


