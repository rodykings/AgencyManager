#pragma once
#include <string>
#include <iostream>

#include "Date.h"

using namespace std;
typedef unsigned int num;


string errorMessage();
void inputString(string message, string &value);
void inputInt(string message, num& value);
void inputInt(string message, num& value, num size);
void inputDate(string message, string& value);
void inputPlaces(string message, string& value);
void yesOrNo();

