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
	for(int i =0;i<9;i++){
			vector<int> v;
			myCols.push_back(v);
		}
		for_each(masterData.begin(), masterData.end(), [this](vector<pair<bool,int>> row){
			for(int i = 0; i<9;i++){
				myCols[i].push_back(row[i].second);
		}


		});

	bool validated = true;
	for_each(myCols.begin(), myCols.end(), [this, &validated](vector<int> col){
		validated &= validate(col);
	});

	return validated;
}
