/*
 * SudokuList.cpp
 *
 *  Created on: 19 dec. 2017
 *      Author: olssongr
 */

#include "SudokuList.h"

SudokuList::SudokuList() {
	// TODO Auto-generated constructor stub

}

SudokuList::~SudokuList() {
	// TODO Auto-generated destructor stub
}

vector<pair<string, string>> SudokuList::translate(string jsonData){
	vector<pair<string, string>> data;
	//Remove []
	char chars[] = "][";
	for (unsigned int i = 0; i < strlen(chars); ++i)
	   {
	      // you need include <algorithm> to use general algorithms like std::remove()
		jsonData.erase (std::remove(jsonData.begin(), jsonData.end(), chars[i]), jsonData.end());
	   }


	//Split into substrings
	vector<string> splittedJson;
	Split("}", jsonData, splittedJson);
	for_each(splittedJson.begin(), splittedJson.end(), [this, &data](string split){


			      // you need include <algorithm> to use general algorithms like std::remove()
				split.erase (std::remove(split.begin(), split.end(), '{'), split.end());
				split.erase (std::remove(split.begin(), split.begin()+1, ','), split.begin()+1);
				vector<string> subsplit;
				Split(",",split, subsplit);
				pair<string, string> value;
				for_each(subsplit.begin(), subsplit.end(), [this, &data, &value](string splitted){
					vector<string> valuesSplit;
					Split(":",splitted, valuesSplit);
					cout << valuesSplit[0] << "," << valuesSplit[1] << endl;
					if(valuesSplit[0] == "\"id\""){
						value.first = valuesSplit[1];
					}else if(valuesSplit[0] == "\"status\""){
						valuesSplit[1].erase (std::remove(valuesSplit[1].begin(), valuesSplit[1].end(), '\"'), valuesSplit[1].end());
						value.second = valuesSplit[1];
					}

				});
				data.push_back(value);
			});

	return data;
}

void SudokuList::Split(const char* splitvalue, const std::string& subject, std::vector<std::string>& container)
{
  container.clear();
  size_t len = subject.length() + 1;
  char* s = new char[ len ];
  memset(s, 0, len*sizeof(char));
  memcpy(s, subject.c_str(), (len - 1)*sizeof(char));
  for (char *p = strtok(s, splitvalue); p != NULL; p = strtok(NULL, splitvalue))
  {
    container.push_back( p );
  }
  delete[] s;
}
