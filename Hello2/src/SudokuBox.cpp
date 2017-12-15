/*
 * SudokuBox.cpp
 *
 *  Created on: 14 dec. 2017
 *      Author: olssongr
 */

#include "SudokuBox.h"
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

SudokuBox::SudokuBox() {
	myBoxes.clear();


}

SudokuBox::~SudokuBox() {
	// TODO Auto-generated destructor stub
}

bool SudokuBox::validateAll(vector<vector<pair<bool, int>>> masterData) {
	myBoxes.clear();
	int j = 0;
	for(int i =0;i<9;i++){
		vector<int> v;
		myBoxes.push_back(v);
	}
		for_each(masterData.begin(), masterData.end(), [this, &j](vector<pair<bool, int>> row){

			for(int i = 0; i<3;i++){
				myBoxes[j/3*3].push_back(row[i].second);
			}
			for(int i = 3; i<6;i++){
				myBoxes[(j/3*3)+1].push_back(row[i].second);
			}
			for(int i = 6; i<9;i++){
				myBoxes[(j/3*3)+2].push_back(row[i].second);
			}
			j++;

		});


	bool validated = true;
	for_each(myBoxes.begin(), myBoxes.end(), [this, &validated](vector<int> box){
		validated &= validate(box);
	});

	return validated;
}

