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
	ifstream infile; //PROCESS - Open input stream
	string fileName; //PROCESS - Use of string for file name
	MemberList list;
	TransactionList day1;
	TransactionList day2;
	TransactionList day3;
	TransactionList day4;
	TransactionList day5;
	int choice;
	int	choiceMonth;
	int searchID;
	string nameID;
	string month;
	string day;
	string year;
	int newDay;
	int newMonth;
	int newYear;
	Date date1 = Date(01,02,2015);
	Date date2 = Date(02,02,2015);
	Date date3 = Date(03,02,2015);
	Date date4 = Date(04,02,2015);
	Date date5 = Date(06,02,2015);
	BasicMember* foundMember;

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
	cout << "\nHello, what kind of user are you? (enter 0 to exit program)\n";
	cout << "1. Customer at Bulk Club\n";
	cout << "2. Employee at Bulk Club\n";
	choice = GetAndCheckInt(0, 2, "Please Enter Your Selection: ");
	while(choice != 0)
	{
		switch(choice)
		{
		case 1: //customer
		{
			cout << "\nHello Customer, enter user info?\n";
			cout << "1. Search by member number: \n";
			cout << "2. Search by name: \n";
			choice = GetAndCheckInt(0, 2, "Please Enter Your Selection: ");
			if(choice == 1)  //Search by number or name
			{
				cout << "Enter your membership number: ";
				cin  >> searchID;
				cout << endl;
				foundMember = list.FindMember(searchID);
				if(foundMember == NULL)
				{
					cout << "\nInvalid Member Number.\n";
					break;
				}
			}
			else
			{
				cout << "Enter your name: ";
				getline(cin,nameID);
				cout << endl;
				foundMember = list.FindMember(nameID);
				if(foundMember == NULL)
				{
					cout << "\nInvalid Member Name.\n";
					break;
				}

			}
				cout << "\nHello " << foundMember->GetName() << " what would you like to do?\n";
				cout << "1. List My Purchases\n";
				cout << "2. Check whether I should change membership type\n";
				cout << "3. See Customer Info\n";
				choice = GetAndCheckInt(1, 3, "Please Enter Your Selection: ");
				switch(choice)
				{
				case 1: //List Purchases
				{
					list.OutputItemList(searchID);
					cout << endl;
				}
				break;
				case 2:
					foundMember->GetTotalSpent();
					if(foundMember->RightType())
					{
						cout << "You have correct membership type for your spending "
								<< "habits.\n";
					}
					else
					{
						cout << "You should change your membership type to " <<
								(foundMember->GetType() == BASIC ? "Preferred" : "Basic")
								<< '.';
					}
					break;
				case 3:
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
// Add place for user to specify whether reports are for basic/preferred/both
			case 1: //Sales Data Options
			{
				cout << "\nWhat type of customer data would you like to see?\n";
				cout << "1. Generate Daily Sales Report\n";
				cout << "2. Output Total Sales Sorted by Member Number\n";
				cout << "3. Output All Sales Sorted by Item Name\n";
				cout << "4. Find Sales information for a Single Item\n";
				choice = GetAndCheckInt(1, 4, "Please Enter Your Selection: ");
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
				case 2: //All Sales Sorted by Member Number
				{
					list.SortID();
					cout << endl << "Sorted List by Member ID: "
					     << endl << endl;
					list.OutputList();
					cout << "Grand Total: $";
					cout << list.GrandTotal() * TAX_RATE;
				}
					break;
				case 3: //All Sales Sorted by Item Name
					break;
				case 4: //Sales information for Single Item
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
				case 1: list.ManualAdd();
				break;
				case 2: list.DeleteMember();
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
					cin >> choiceMonth;
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
		cout << "\nHello, what kind of user are you? (enter 0 to exit program)\n";
		cout << "1. Customer at Bulk Club\n";
		cout << "2. Employee at Bulk Club\n";
		choice = GetAndCheckInt(0, 2, "Please Enter Your Selection: ");
	}
return 0;
}
