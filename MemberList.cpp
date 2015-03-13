#include <iostream>
#include <string>
#include "MemberList.h"
#include "BasicMember.h"
#include "PreferredMember.h"
using namespace std;

MemberList::MemberList()
{
	head = NULL;
}

MemberList::~MemberList()
{
	DeleteList();
}

BasicMember* MemberList::FindMember(int memberNum) const
{
	BasicMember* finder;
	finder = head;
	while(finder != NULL && finder->GetMemberNum() != memberNum)
	{
		finder = finder->GetNext();
	}

	return finder;
}

void MemberList::AddMember(string newName, int newNum, string newType,
		          int newMonth, int newDay, int newYear, dollars newTotal)
{

	BasicMember* newNode;

	if(newType == "Basic")
	{
	newNode = new BasicMember;
	newNode->SetAll(newName,newNum,newMonth,newDay,newYear, BASIC,
					newTotal = 0);
	}

	if(newType == "Preferred")
	{
	newNode = new PreferredMember;
	newNode->SetAll(newName,newNum,newMonth,newDay,newYear, PREFERRED,
					newTotal = 0);
	}

	if(head == NULL)
	{
		head = newNode;
	}

	else
	{
		BasicMember* current;
		current = head;

		while(current->GetNext() != NULL)
		{
			current = current->GetNext();
		}

		current->SetNext(newNode);
		newNode->SetPrev(current);
		newNode->SetNext(NULL);
	}
}

void MemberList::DeleteMember(BasicMember* target)
{
	if(target->GetNext() != NULL)
	{
		target->GetNext()->SetPrev(target->GetPrev());
	}
	if(target->GetPrev() != NULL)
	{
		target->GetPrev()->SetNext(target->GetNext());
	}
	else
	{
		head = target->GetNext();
	}
	delete target;
}


void MemberList::OutputList()
{

	BasicMember* traverser;
	traverser = head;
	while(traverser != NULL)
	{
		traverser->OutputMemberInfo();
		cout << endl;
		traverser = traverser->GetNext();
	}
}

void MemberList::DeleteList()
{
	BasicMember* deleter;
	while(head!= NULL)
	{
		deleter = head->GetNext();
		delete head;
		head = deleter;
	}
}

void MemberList::AddItem(int newMonth,int newDay,int newYear,int newId,
						 string newName,dollars newPrice,int newAmount)
{
	BasicMember* current;
	current    = head;
	bool found = false;

	while(current != NULL and found == false)
	{
		if(current->GetMemberNum() == newId)
		{
		current->AddTransaction(newMonth,newDay,newYear,newName,
								newPrice,newAmount);
		found = true;
		}
		else
		{
		current = current->GetNext();
		}
	}
	if(found == false)
	{
		cout << "Invaid Member Number!!! " << endl;
	}
}

void MemberList::OutputItemList(int newId)
{
	BasicMember* current;
	current    = head;
	bool found = false;

	while(current != NULL and found == false)
	{
		if(current->GetMemberNum() == newId)
		{
		current->OutputTransactionList();
		found = true;
		}
		else
		{
		current = current->GetNext();
		}
	}

	if(found == false)
	{
		cout << "Invaid Member Number!!! " << endl;
	}

}

void MemberList::FindExpire(int month)
{

	BasicMember* current;
	current   = head;
	bool fact = false;

	while(current != NULL)
	{
		if(current->GetMonthEx() == month)
		{
			current->OutputMemberInfo();
			if(typeid(*current) == typeid(BasicMember))
			{
				cout << "Renew price: $" << BASIC_DUES << endl;
			}
			if(typeid(*current) == typeid(PreferredMember))
			{
				cout << "Renew price: $" << PREFERRED_DUES << endl;
			}
			cout << endl;
			fact = true;
		}
		current = current->GetNext();
	}

	if(fact == false)
	{
		cout << "No members expired in this month" << endl;
	}
}

void MemberList::PrintRebates()
{
	BasicMember* current;
	current   = head;

	while(current != NULL)
	{
		if(typeid(*current) == typeid(PreferredMember))
		{
			cout << endl;
			current->OutputMemberInfo();
		}
		current = current->GetNext();
	}
}


void MemberList::DailyShopper(Date checkDate)
{
	int basicCount     = 0;
	int preferredCount = 0;
	BasicMember* current;
	current = head;
	cout << endl << endl << "Members who shopped on ";
	checkDate.DisplayDate();
	cout << endl;

	while(current != NULL)
	{
		if(current->FindDate(checkDate) == true)
		{
			cout << current->GetName() << endl;

			if(typeid(*current) == typeid(PreferredMember))
			{
				preferredCount++;
			}
			if(typeid(*current) == typeid(BasicMember))
			{
				basicCount++;
			}
		}
		current = current->GetNext();
	}
	cout << endl;
	cout << "Basic Member count:     " << basicCount << endl;
	cout << "Preferred Member count: " << preferredCount << endl;
}

void MemberList::ManualAdd()
{
	string type;
	string name;
	int memberNumber;
	Date expiration;
	BasicMember* finder;
	int month;
	int day;
	int year;
	string monthString;
	string dayString;
	string yearString;
	cout << "\nWhat type of member would you like to add?\n";
	cout << "1. Basic\n";
	cout << "2. Preferred\n";
	type = (GetAndCheckInt(1, 2, "Please Enter Your Selection: ") == 1 ? "Basic" : "Preferred");
	cout << "\nWhat is the name of the new member?\n";
	getline(cin, name);
	do
	{
		memberNumber = GetAndCheckInt(100000, 999999, "What is the membership number of the new member?\n");
		if(FindMember(memberNumber) != NULL)
		{
			cout << "Member Number is taken. Please Try again.";
			memberNumber = 0;
		}
	}while(memberNumber == 0);

	do
	{
		cout << "What is the expiration date of the new membership?(MM/DD/YYY)? ";
		getline(cin, monthString, '/');
		month = atoi(monthString.c_str());
		getline(cin, dayString, '/');
		day = atoi(dayString.c_str());
		getline(cin, yearString);
		year = atoi(yearString.c_str());
		expiration = Date(day, month, year);

		if(!expiration.ValiDate())
		{
			cout << "The date is invalid. Please enter a valid date.";
		}
	}while(!expiration.ValiDate());

	AddMember(name, memberNumber, type, month, day, year, 0);
	cout << "New Member Added\n";
	finder = head;

	while(finder->GetNext() != NULL)
	{
		finder = finder->GetNext();
	}
	finder->OutputMemberInfo();
}

void MemberList::DeleteMember()
{
	int memberNumber;
	BasicMember* target;
	do
	{
		target = NULL;
		cout << "Please enter the member number of the member you wish to delete.\n";
		cout << "(Enter 0 to exit)\n";
		//Should have error checking here
		cin >> memberNumber;
		target = FindMember(memberNumber);
	}while(memberNumber != 0 && target == NULL);

	if(target != NULL)
	{
		DeleteMember(target);
		cout << "Member has been deleted.\n";
	}
}

BasicMember* MemberList::FindMember(string memberName) const
{
	BasicMember* finder;
	finder = head;
	while(finder != NULL && finder->GetName() != memberName)
	{
		finder = finder->GetNext();
	}

	return finder;
}

int MemberList::GetCount()
{
	BasicMember* finder;
	int count = 0;
	finder = head;
	while(finder != NULL)
	{
		finder = finder->GetNext();
		count++;
	}
	return count;
}

void MemberList::SortID()
{
	int count;
	BasicMember* temp;
	temp  = head;
	count = GetCount();
	cout << count << endl;

		for(int i = 1; i < count; i++)
		{
			if(temp->GetMemberNum() > temp->GetNext()->GetMemberNum())
			{
				cout << "here" << endl;
				Swap(temp,temp->GetNext());
			}
			temp = temp->GetNext();
		}



}

void MemberList::Swap(BasicMember* one, BasicMember* two)
{
	one->OutputMemberInfo();
	two->OutputMemberInfo();
	cout << endl;
	BasicMember temp;
	if(one == head);
	{
		two = head;
	}
	temp.SetNext(one->GetNext());
	temp.SetPrev(one->GetPrev());

	one->SetNext(two->GetNext());
	one->SetPrev(two->GetPrev());
	two->SetNext(temp.GetNext());
	two->SetPrev(temp.GetPrev());
}
