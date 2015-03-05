#include "BasicMember.h"
#include <iostream>

using namespace std;

BasicMember::BasicMember():name(""), memberNum(0), expirationDate(1,1,1900), type(BASIC), totalSpent(0), next(NULL), prev(NULL)
{
//purchaseList should be initialized with its own constructor
}

BasicMember::~BasicMember()
{
//use Deletelist function from purchaseList
}

string BasicMember::GetName()
{
	return name;
}

int BasicMember::GetMemberNum()
{
	return memberNum;
}

Date BasicMember::GetExpirationDate()
{
	return expirationDate;
}

dollars BasicMember::GetTotalSpent()
{
	return totalSpent;
}

BasicMember* BasicMember::GetNext()
{
	return next;
}

BasicMember* BasicMember::GetPrev()
{
	return prev;
}

memberType BasicMember::GetType()
{
	return type;
}

void BasicMember::SetName(string newName)
{
	name = newName;
}

void BasicMember::SetMemberNum(int newNum)
{
	memberNum = newNum;
}

void BasicMember::SetExpirationDate(Date newDate)
{
	expirationDate = newDate;
}

void BasicMember::SetTotalSpent(dollars newTotal)
{
	totalSpent = newTotal;
}

void BasicMember::SetType(memberType newType)
{
	type = newType;
}

void BasicMember::SetNext(BasicMember* newNext)
{
	next = newNext;
}

void BasicMember::SetPrev(BasicMember* newPrev)
{
	next = newPrev;
}

void BasicMember::SetAll(string newName, int newNum, int newMonth, int newDay, int newYear, memberType newType, dollars newTotal)
{
	name = newName;
	memberNum = newNum;
	expirationDate = Date(newDay, newMonth, newYear);
	type = newType;
	totalSpent = newTotal;

}

void BasicMember::OutputMemberInfo()
{
	cout << "Name: " << name << endl;
	cout << "Member Number: " << memberNum << endl;
	cout << "Membership Expiration Date ";
	expirationDate.DisplayDate();
	cout << endl;
	cout << "Total Amount Spent: " << totalSpent << endl;

}
