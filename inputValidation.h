#pragma once
#include <string>
#include <iostream>
#include <vector>


using namespace std;
typedef unsigned int num;


string errorMessage();
void inputString(string message, string &value);
void inputInt(string message, int& value);
void inputInt(string message, num& value, num size);
void inputPlaces(vector<string> &places);
bool yesOrNo(string message);

