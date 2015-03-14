/****************************************************************
* Date
*---------------------------------------------------------------
* A class that represents a calendar date (day, month, year).
* Also checks Date validity, and contains methods for display and
* changing the date.
****************************************************************/
#ifndef DATE_H_
#define DATE_H_
#include "MainHeader.h"
using namespace std;
const int DAYS_IN_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
class Date
{
public:
Date();
Date(int newDay, int newMonth, int newYear);
~Date();
int GetDay() const;
int GetMonth() const;
int GetYear() const;
void DisplayDate() const;
void SetDate(int newDay, int newMonth, int newYear);
void SetDay(int newDay);
void SetMonth(int newMonth);
void SetYear(int newYear);
void IncrementDay();
int MonthDifference(Date laterDate) const;
bool ValiDate() const;
bool operator==(const Date&);
private:
int day;
int month;
int year;
};
#endif /* DATE_H_ */
