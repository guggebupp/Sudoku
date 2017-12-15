/*
 * SudokuValidator.cpp
 *
 *  Created on: 14 dec. 2017
 *      Author: olssongr
 */

#include "SudokuValidator.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

SudokuValidator::SudokuValidator() {
	// TODO Auto-generated constructor stub

}

SudokuValidator::~SudokuValidator() {
	// TODO Auto-generated destructor stub
}

bool SudokuValidator::validate(std::vector<int> data){
	std::sort(data.begin(), data.end());
	SudokuValidator::erase(data, 0);
	unsigned int size = data.size();

	auto last = std::unique(data.begin(), data.end());
	data.erase(last, data.end());
	bool valid =  size == data.size();

	return valid;

}

void SudokuValidator::erase(std::vector<int>& myNumbers_in, int number_in)
{
			bool stop = false;
			while(!stop){
			std::vector<int>::iterator position = std::find(myNumbers_in.begin(), myNumbers_in.end(), number_in);
			if (position != myNumbers_in.end()) // == myVector.end() means the element was not found
				myNumbers_in.erase(position);
			else
				stop = true;
			}
//    std::vector<int>::iterator iter = myNumbers_in.begin();
//    std::vector<int>::iterator endIter = myNumbers_in.end();
//    for(; iter != endIter; ++iter)
//    {
//        if(*iter == number_in)
//        {
//            myNumbers_in.erase(iter);
//        }
//    }
}
