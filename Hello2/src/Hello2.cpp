//============================================================================
// Name        : Hello2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "restless.hpp"
#include "sudoku.h"
#include <stdlib.h>

using namespace std;

// for a more readable name
using Http = asoni::Handle;



int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	auto res1 = Http().get("http://openshifttest-goran.193b.starter-ca-central-1.openshiftapps.com/rest/members/ping")
	            .exec();
	cout << res1.body << endl;
	res1 = Http().get("http://openshifttest-goran.193b.starter-ca-central-1.openshiftapps.com/rest/members/")
		            .exec();
		cout << res1.body << endl;

		Sudoku sudoku = Sudoku();
		sudoku.solvesudoku();




	return 0;
}
