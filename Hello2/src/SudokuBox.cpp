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
	for(int i =0;i<9;i++) {
		vector<int> v;
		myBoxes.push_back(v);
	}
	for_each(masterData.begin(), masterData.end(), [this, &j](vector<pair<bool, int>> row) {

		for(int i = 0; i<3;i++) {
			myBoxes[j/3*3].push_back(row[i].second);
		}
		for(int i = 3; i<6;i++) {
			myBoxes[(j/3*3)+1].push_back(row[i].second);
		}
		for(int i = 6; i<9;i++) {
			myBoxes[(j/3*3)+2].push_back(row[i].second);
		}
		j++;

	});

	bool validated = true;
	for_each(myBoxes.begin(), myBoxes.end(), [this, &validated](vector<int> box) {
		validated &= validate(box);
	});

	return validated;
}

vector<int> SudokuBox::findFixed(vector<vector<pair<bool, int>>> masterData, vector<int>avaliable, int boxToCheck) {
	int j = 0;

	for_each(masterData.begin(), masterData.end(), [this, &j, &avaliable, &boxToCheck](vector<pair<bool, int>> row) {

		for(int i = 0; i<3;i++) {
			if(j/3*3 == boxToCheck) {
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
		for(int i = 3; i<6;i++) {
			if((j/3*3+1) == boxToCheck) {
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
		for(int i = 6; i<9;i++) {
			if((j/3*3+2) == boxToCheck) {
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
		j++;

	});

	return avaliable;
}

bool SudokuBox::valuePossible(vector<vector<pair<bool, int>>> masterData, int value, int boxToCheck, int rowToCheck, int colToCheck){

	if(masterData[rowToCheck][colToCheck].first){
		return false;
	}
	int j=0;
	bool possible = true;
	for_each(masterData.begin(), masterData.end(), [this, &possible, &j, &value, &boxToCheck, &rowToCheck, &colToCheck](vector<pair<bool, int>> row) {

			for(int i = 0; i<3;i++) {
				if(j/3*3 == boxToCheck){
					if(row[i].second == value){
						possible = false;
						return false;
					}
				}

			}
			for(int i = 3; i<6;i++) {
				if(j/3*3+1 == boxToCheck){
									if(row[i].second == value){
										possible = false;
										return false;
									}
								}
			}
			for(int i = 6; i<9;i++) {
				if(j/3*3+2 == boxToCheck){
									if(row[i].second == value){
										possible = false;
										return false;
									}
								}
			}
			j++;

		});

	for_each(masterData[rowToCheck].begin(), masterData[rowToCheck].end(), [&value , &possible](pair<bool, int> row){
			if(row.second == value){
				possible = false;
							return false;
						}

	});

	for_each(masterData.begin(), masterData.end(), [this, &possible, &value,&colToCheck](vector<pair<bool, int>> row) {
		for(int i=0;i<9;i++){
			if(i==colToCheck){
				if(row[i].second == value){
					possible = false;
											return false;
										}
			}
		}
	});



	return possible;
}
