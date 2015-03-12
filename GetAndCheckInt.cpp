/**************************************************************************
* GetAndCheckInt
* Prompts the user to enter an integer, and checks if that integer is
* within the given range. If not, it loops until a valid input is given.
* - returns an integer
*************************************************************************/
#include "MainHeader.h"
#include <limits>
#include <ios>
#include <sstream>
#include <iomanip>
int GetAndCheckInt(int minValue, //CALC - max value for menu
int maxValue, //CALC - max value for menu
string prompt) //CALC - prompts user
{
int value; // IN - the float that the user enters
bool valid; // CALC - whether or not the entry is valid
ostringstream errorStream1; // OUT - used for output formatting
ostringstream errorStream2; // OUT - used for output formatting
do
{
//INITIALZATION
valid = true;
//OUTPUT - outputs prompt
cout << prompt;
if(!(cin >> value))
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
errorStream2 << "*** Please enter a NUMBER between "
<< minValue << " and " << maxValue << '.';
cout << left << setw(45) << errorStream2.str() << " ***\n"
<< right;
errorStream2.str("");
valid = false;
}
else if(value < minValue || value > maxValue)
{
errorStream1 << "*** The number " << value
<< " is an invalid entry. ";
cout << left << setw(45) << errorStream1.str() << " ***\n";
errorStream1.str("");
errorStream2 << "*** Please enter a number between "
<< minValue << " and " << maxValue << '.';
cout << left << setw(45) << errorStream2.str() << " ***\n";
errorStream2.str("");
valid = false;
cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
}while (!valid);
cin.ignore(numeric_limits<streamsize>::max(), '\n');
return value;
}
