/*
 * sudokuData.hpp
 *
 *  Created on: 14 dec. 2017
 *      Author: olssongr
 */

#ifndef SUDOKUDATA_HPP_
#define SUDOKUDATA_HPP_
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class SudokuData {
	private:
	vector<vector<pair<bool, int>>> masterData;
public:
	SudokuData(vector<vector<pair<bool, int>>> inData);
	virtual ~SudokuData();
	vector<vector<pair<bool, int>>> getResult();
};

#endif /* SUDOKUDATA_HPP_ */
