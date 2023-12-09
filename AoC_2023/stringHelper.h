#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <regex> 

using namespace std;

#ifndef stringHelper
#define stringHelper

string getNumbers(string inputStr);

vector<string> splitString(string input, string delimeter);


#endif // stringHelper
