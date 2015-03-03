#include "Date.h"
#include <iostream>
using namespace std;

Date::Date()
{
day = 1;
month = 1;
year = 1901;
}
Date::Date(int newDay, int newMonth, int newYear)
{
SetDate(newDay, newMonth, newYear);
}
Date::~Date()
{
day = 0;
month = 0;
year = 0;
}
int Date::GetDay() const
{
return day;
}
int Date::GetMonth() const
{
return month;
}
int Date::GetYear() const
{
return year;
}
void Date::DisplayDate() const
{
cout << (month < 10? "0" : "") << month << '/';
cout << (day < 10? "0" : "") << day << '/';
cout << year;
}
void Date::SetDate(int newDay, int newMonth, int newYear)
{
SetMonth(newMonth);
SetDay(newDay);
SetYear(newYear);
}
void Date::SetDay(int newDay)
{
if(month == 0 && newDay <= 31)
{
day = newDay;
}
else if(newDay <= DAYS_IN_MONTH[month - 1])
{
day = newDay;
}
else if(month == 2 && year%4 == 0 && newDay == 29)
{
day = newDay;
}
else
{
cout << "\n*** Invalid Date value ***\n";
day = 0;
}
}
void Date::SetMonth(int newMonth)
{
if(newMonth <= 12)
{
month = newMonth;
}
else
{
cout << "\n*** Month must be between 1 and 12 ***\n";
month = 0;
}
}
void Date::SetYear(int newYear)
{
if(newYear > 1900 && newYear < 2100)
{
year = newYear;
}
else
{
//cout << "\n*** Year must be between 1901 and 2099 ***\n";
year = 0;
}
}
void Date::IncrementDay()
{
day++;
if (day > DAYS_IN_MONTH[month-1] && !(day == 29 && year%4 == 0))
{
day = 1;
month ++;
}
if (month == 13)
{
month = 1;
year++;
}
}
int Date::MonthDifference(Date currentDate) const
{
return 12 * (currentDate.GetYear() - year) + currentDate.GetMonth() - month;
}
bool Date::ValiDate() const
{
bool dayValid;
bool monthValid;
bool yearValid;
yearValid = (year > 1900 && year < 2100);
monthValid = (month >= 1 && month <= 12);
if(day <= DAYS_IN_MONTH[month - 1])
{
dayValid = true;
}
else if(month == 2 && year%4 == 0 && day == 29)
{
dayValid = true;
}
else
{
cout << "\n*** Invalid Date value ***\n";
dayValid = false;
}
return (yearValid && monthValid && dayValid);
}
