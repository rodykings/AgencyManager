#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Date.h"


using namespace std;
typedef unsigned int num;


string errorMessage();
bool dateValidation(string date);
Date inputDate(string message);
void inputString(string message, string &value);
void inputInt(string message, int& value);
void inputNum(string message, num& value);
void inputNum(string message, num& value, num size);
void inputPlaces(vector<string> &places);
bool yesOrNo(string message);
void selectOption(int& option, num numOptions);
bool validStartEnd(Date start, Date end);

