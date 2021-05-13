#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "parser.h"

using namespace std;

Parser::Parser() {}

vector<vector<int> > Parser::load_matrix(const char* filename)
{
	vector<vector<int> > out;
	ifstream ifs(filename, ios::in);
	string line;
	
	if(!ifs.is_open()) {
		return out;
	}
	while(getline(ifs, line)) {
		int val;
		vector<int> row;
		stringstream ss;
		ss << line;
		while(ss >> val) {
			row.push_back(val);
		}
		out.push_back(row);
	}

	return out;
} 
