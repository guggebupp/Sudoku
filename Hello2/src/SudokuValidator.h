/*
 * SudokuValidator.h
 *
 *  Created on: 14 dec. 2017
 *      Author: olssongr
 */

#ifndef SUDOKUVALIDATOR_H_
#define SUDOKUVALIDATOR_H_
#include <vector>

class SudokuValidator {
private:
	void erase(std::vector<int>& myNumbers_in, int number_in);
public:
	SudokuValidator();
	virtual ~SudokuValidator();
	bool validate(std::vector<int> data);
};

#endif /* SUDOKUVALIDATOR_H_ */
