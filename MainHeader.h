#ifndef MAINHEADER_H_
#define MAINHEADER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>


using namespace std;

typedef float dollars;

const dollars BASIC_DUES = 55;
const dollars PREFERRED_DUES = 95;
const float PREFERRED_REBATE = 0.06;
const float TAX_RATE = 1.08;

int GetAndCheckInt(int minValue, 	//CALC - max value for menu
				   int maxValue, 	//CALC - max value for menu
				   string prompt);  //CALC - prompts user

#endif
