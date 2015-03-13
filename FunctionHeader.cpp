#include "FunctionHeader.h"
#include <fstream>
#include <iostream>
using namespace std;

void ReadMembersFile(ifstream &infile, MemberList &list)
{
string id;
int num;
int numDay;
int numMonth;
int numYear;
string name;
string type;
string month;
string day;
string year;
	if(infile.is_open())
	{
		while(!infile.eof())
		{
			getline(infile,name);
			getline(infile,id);
			num = atoi(id.c_str());
			getline(infile,type);
			getline(infile, month, '/');
			numMonth = atoi(month.c_str());
			getline(infile, day, '/');
			numDay = atoi(day.c_str());
			getline(infile, year);
			numYear = atoi(year.c_str());
			list.AddMember(name,num,type,numMonth,numDay,numYear,0);
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	infile.close();
	infile.clear();
}

void ReadItemFile(ifstream &infile,MemberList &list,TransactionList &daily)
{
	string month;
		string day;
		string year;
		string id;
		string item;
		string amount;
		float  numPrice;
		int	   numMonth;
		int    numDay;
		int    numYear;
		int    numId;
		int    numAmount;

		if(infile.is_open())
		{
			while(!infile.eof())
			{
				getline(infile, month, '/');
				numMonth = atoi(month.c_str());
				getline(infile, day, '/');
				numDay = atoi(day.c_str());
				getline(infile, year);
				numYear = atoi(year.c_str());

				getline(infile, id);
				numId = atoi(id.c_str());

				getline(infile,item);

				infile >> numPrice;

				getline(infile, amount);
				numAmount = atoi(amount.c_str());

				list.AddItem(numMonth,numDay,numYear,numId,item,numPrice,
							 numAmount);
				daily.AddNode(numMonth,numDay,numYear,item,numPrice,
							numAmount);
			}
		}

		else
		{
			cout << "Unable to open file";
		}
		infile.close();
		infile.clear();
}
