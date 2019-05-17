#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef unsigned int num;

//trims trailling whitespaces from strings
string trimString(string str);
//string to upper
string stringToUpper(string str);

vector<num> vectorIntersect(vector<num> first, vector<num> second);
