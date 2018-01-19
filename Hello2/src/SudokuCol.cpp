/*
 * SudokuCol.cpp
 *
 *  Created on: 14 dec. 2017
 *      Author: olssongr
 */

#include "SudokuCol.h"
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

SudokuCol::SudokuCol() {

}

SudokuCol::~SudokuCol() {
	// TODO Auto-generated destructor stub
}

bool SudokuCol::validateAll(vector<vector<pair<bool, int>>> masterData) {
	myCols.clear();
	for(int i =0;i<9;i++) {
		vector<int> v;
		myCols.push_back(v);
	}
	for_each(masterData.begin(), masterData.end(), [this](vector<pair<bool,int>> row) {
		for(int i = 0; i<9;i++) {
			myCols[i].push_back(row[i].second);
		}

	});

	bool validated = true;
	for_each(myCols.begin(), myCols.end(), [this, &validated](vector<int> col) {
		validated &= validate(col);
	});

	return validated;
}

vector<int> SudokuCol::findFixed(vector<vector<pair<bool, int>>> masterData, vector<int>avaliable, int colToCheck) {

	for_each(masterData.begin(), masterData.end(), [this, &avaliable, &colToCheck](vector<pair<bool,int>> row) {
		for(int i = 0; i<9;i++) {
			if(i==colToCheck) {
			std::vector<int>::iterator iter = avaliable.begin();
			std::vector<int>::iterator endIter = avaliable.end();
			for(; iter != endIter; ++iter)
			{
				if(*iter == row[i].second)
				{
					avaliable.erase(iter);
				}
			}
		}
		}
	});


return avaliable;
}
