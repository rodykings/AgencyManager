#pragma once
#include <string>
#include <iostream>
#include <vector>


using namespace std;
typedef unsigned int num;


string errorMessage();
void inputString(string message, string &value);
void inputInt(string message, num& value);
void inputInt(string message, num& value, num size);
void inputDate(string message, string& value);
void inputPlaces(vector<string> &places);
void yesOrNo();

