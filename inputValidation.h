#pragma once
#include <string>
#include <iostream>

using namespace std;
typedef unsigned int num;


string errorMessage();
void inputString(string message, string &value);
void inputInt(string message, num& value);
void inputInt(string message, num& value, num size);
void inputDate(string message, string& value);

