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
	ifstream   infile; //PROCESS - Open input stream
	string     fileName; //PROCESS - Use of string for file name
	MemberList list;
	int		   choice;
	int		   choiceMonth;
	int        searchID;

	fileName = "warehouse shoppers.txt";
	infile.open(fileName.c_str());
	ReadMembersFile(infile, list);

	fileName = "day1.txt";
	infile.open(fileName.c_str());
	ReadItemFile(infile,list);

	fileName = "day2.txt";
	infile.open(fileName.c_str());
	ReadItemFile(infile,list);

	fileName = "day3.txt";
	infile.open(fileName.c_str());
	ReadItemFile(infile,list);

	fileName = "day4.txt";
	infile.open(fileName.c_str());
	ReadItemFile(infile,list);

	fileName = "day5.txt";
	infile.open(fileName.c_str());
	ReadItemFile(infile,list);

	cout << "Welcome to Bulk Club" << endl;
	cout << "--------------------" << endl;
	cout << "1. Output All Members"<< endl;
	cout << "2. Find Expiration"   << endl;
	cout << "3. Output Item bought"  << endl;
	cout << "4. Exit"			   << endl << endl;
	cout << "Enter Choice: ";
	cin  >> choice;

	while(choice != 4)
	{
		if(choice == 1)
		{
			cout << endl;
			list.OutputList();
		}

		if(choice == 2)
		{
			cout << "Enter a month to find expiration "
					"(Ex: 1 for January): ";
			cin  >> choiceMonth;
			cout << endl;
			list.FindExpire(choiceMonth);
		}

		if(choice == 3)
		{
			cout << "Search by member number: ";
			cin  >> searchID;
			cout << endl;
			list.OutputItemList(searchID);
			cout << endl;
		}

		cout << "Welcome to Bulk Club" << endl;
		cout << "--------------------" << endl;
		cout << "1. Output All Members"<< endl;
		cout << "2. Find Expiration"   << endl;
		cout << "3. Output Item list"  << endl;
		cout << "4. Exit"			   << endl << endl;
		cout << "Enter Choice: ";
		cin  >> choice;
	}

return 0;
}

