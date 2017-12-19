/*
 * SudokuList.h
 *
 *  Created on: 19 dec. 2017
 *      Author: olssongr
 */

#ifndef SUDOKULIST_H_
#define SUDOKULIST_H_
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

class SudokuList {
private:
	void Split(const char* splitvalue, const std::string& subject, std::vector<std::string>& container);
public:
	SudokuList();
	virtual ~SudokuList();
	vector<pair<string, string>> translate(string jsonData);
};

#endif /* SUDOKULIST_H_ */
