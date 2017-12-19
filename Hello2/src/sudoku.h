
#ifndef SUDOKU_H_
#define SUDOKU_H_
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

class Sudoku
{
private:
void pushStatus(string status, vector<vector<pair<bool, int>>>& res, string id);
public:
void solvesudoku();
};
#endif /* SUDOKU_H_ */
