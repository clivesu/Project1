#include <fstream>
#include <iostream>
#include "MainHeader.h"
#include "Transaction.h"
#include "TransactionList.h"
#include "BasicMember.h"
#include "PreferredMember.h"
#include "Date.h"
#include "MemberList.h"
#include "FunctionHeader.h"
using namespace std;

int main()
{
	ifstream        infile; //PROCESS - Open input stream
	string          fileName; //PROCESS - Use of string for file name
	MemberList      list;
	TransactionList day1;
	TransactionList day2;
	TransactionList day3;
	TransactionList day4;
	TransactionList day5;
	int 		    choice;
	int		   		choiceMonth;
	int        		searchID;
	string		    month;
	string 			day;
	string 			year;
	int 			newDay;
	int 			newMonth;
	int 			newYear;
	Date date1 = Date(01,02,2015);
	Date date2 = Date(02,02,2015);
	Date date3 = Date(03,02,2015);
	Date date4 = Date(04,02,2015);
	Date date5 = Date(06,02,2015);
	BasicMember*   foundMember;

	fileName = "warehouse shoppers.txt";
	infile.open(fileName.c_str());
	ReadMembersFile(infile, list);

	fileName = "day1.txt";
	infile.open(fileName.c_str());
	ReadItemFile(infile,list,day1);

	fileName = "day2.txt";
	infile.open(fileName.c_str());
	ReadItemFile(infile,list,day2);

	fileName = "day3.txt";
	infile.open(fileName.c_str());
	ReadItemFile(infile,list,day3);

	fileName = "day4.txt";
	infile.open(fileName.c_str());
	ReadItemFile(infile,list,day4);

	fileName = "day5.txt";
	infile.open(fileName.c_str());
	ReadItemFile(infile,list,day5);

	cout << "INTRO MESSAGE\n\n";
	cout << "\nHello, what kind of user are you?\n";
	cout << "1. Customer at Bulk Club\n";
	cout << "2. Employee at Bulk Club\n";
	choice = GetAndCheckInt(0, 2, "Please Enter Your Selection: ");
	while(choice != 0)
	{
	switch(choice)
	{
	case 1: //customer
	{
	cout << "\nHello Customer, what would you like to do?\n";
	cout << "1. List My Purchases\n";
	cout << "2. Check whether I should change membership type\n";
	cout << "3. See Customer Info\n";
	choice = GetAndCheckInt(1, 3, "Please Enter Your Selection: ");
	switch(choice)
	{
	case 1: //List Purchases
	{
		cout << "Search by member number: ";
		cin  >> searchID;
		cout << endl;
		list.OutputItemList(searchID);
		cout << endl;
	}
	break;
	case 2:
	cout << "Search by member number: ";
	cin  >> searchID;
	cout << endl;
	foundMember = list.FindMember(searchID);
	foundMember->GetTotalSpent();
	if(foundMember->RightType())
	{
		cout << "You have correct membership type for your spending "
			 <<	"habits.\n";
	}

	else
	{
		cout << "You should change your membership type to " <<
				(foundMember->GetType() == BASIC ? "Preferred" : "Basic")
				<< '.';
	}

	break;
	case 3:
		cout << "Search by member number: ";
		cin  >> searchID;
		cout << endl;
		foundMember = list.FindMember(searchID);
		foundMember->OutputMemberInfo();
	break;
	default:
	break;
	}
	}
	break;
	case 2:
	{
	cout << "\nHello Employee, what would you like to do?\n";
	cout << "1. See Sales Data\n";
	cout << "2. See Customer Data\n";
	choice = GetAndCheckInt(1, 2, "Please Enter Your Selection: ");
	switch(choice)
	{
	case 1: //Sales Data Options
	{
	cout << "\nWhat type of customer data would you like to see?\n";
	cout << "1. Generate Daily Sales Report\n";
	cout << "2. Generate Total Sales Report\n";
	choice = GetAndCheckInt(1, 3, "Please Enter Your Selection: ");
	switch(choice)
	{
	case 1: //Daily
	{
		Date check;
		cout << "What day do you want to see a sale for? (MM/DD/YYYY) ";
		getline(cin, month, '/');
		newMonth = atoi(month.c_str());
		getline(cin, day, '/');
		newDay = atoi(day.c_str());
		getline(cin, year);
		newYear = atoi(year.c_str());
		check = Date(newDay,newMonth,newYear);

		if(check == date1)
		{
			cout << fixed << setprecision(2);
			cout << endl;
			day1.DailyOutputList();
			cout << endl;
			cout << "Total: $";
			cout << day1.GetTotal();
			list.DailyShopper(check);
		}
		else if(check == date2)
		{
			cout << fixed << setprecision(2);
			cout << endl;
			day2.DailyOutputList();
			cout << endl;
			cout << "Total: $";
			cout << day2.GetTotal();
			list.DailyShopper(check);
		}
		else if(check == date3)
		{
			cout << fixed << setprecision(2);
			cout << endl;
			day3.DailyOutputList();
			cout << endl;
			cout << "Total: $";
			cout << day3.GetTotal();
			list.DailyShopper(check);
		}
		else if(check == date4)
		{
			cout << fixed << setprecision(2);
			cout << endl;
			day4.DailyOutputList();
			cout << endl;
			cout << "Total: $";
			cout << day4.GetTotal();
			list.DailyShopper(check);
		}
		else if(check == date5)
		{
			cout << fixed << setprecision(2);
			cout << endl;
			day5.DailyOutputList();
			cout << endl;
			cout << "Total: $";
			cout << day5.GetTotal();
			list.DailyShopper(check);
		}
		else
		{
			cout << "No Such Date!!!" << endl;
		}
	}
	break;
	case 2: //Total
	break;
	default:
	break;
	}
	}
	break;
	case 2: //Customer Data Options
	{
	cout << "\nWhat type of customer options would you like to perform?\n";
	cout << "1. Add Customer\n";
	cout << "2. Delete Customer\n";
	cout << "3. See Member Rebates\n";
	cout << "4. List Customers By Expiration Month\n";
	choice = GetAndCheckInt(1, 4, "Please Enter Your Selection: ");
	switch(choice)
	{
	case 1: //Add Customer
	break;
	case 2: //Delete Customer
	break;
	case 3: //See Rebates
	{
		list.PrintRebates();
	}
	break;
	case 4: //List by expiration
	{
		cout << "Enter a month to find expiration "
				"(Ex: 1 for January): ";
		cin  >> choiceMonth;
		cout << endl;
		list.FindExpire(choiceMonth);
	}
	break;
	default:
	break;
	}
	}
	break;
	default:
	break;
	}
	}
	break;
	default:
	break;
	}
	cout << endl;
	cout << "\nHello, what kind of user are you?\n";
	cout << "1. Customer at Bulk Club\n";
	cout << "2. Employee at Bulk Club\n";
	choice = GetAndCheckInt(0, 2, "Please Enter Your Selection: ");
	}

return 0;
}
