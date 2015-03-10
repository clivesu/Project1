#include "BasicMember.h"
#include <iostream>

using namespace std;

BasicMember::BasicMember():name(""), memberNum(0), expirationDate(1,1,1900), type(BASIC), totalSpent(0), next(NULL), prev(NULL)
{
//purchaseList should be initialized with its own constructor
}

BasicMember::~BasicMember()
{
	purchaseList.DeleteList();
}

BasicMember::BasicMember(const BasicMember& otherMember)
{
	purchaseList.CopyList(otherMember.purchaseList);

	name = otherMember.name;
	memberNum = otherMember.memberNum;
	expirationDate = otherMember.expirationDate;
	type = otherMember.type;
	totalSpent = otherMember.totalSpent;

	next = NULL;
	prev = NULL;


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

TransactionList BasicMember::GetPurchaseList()
{
	return purchaseList;
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

void BasicMember::OutputTransactionList()
{
	cout << "Purchases for " << name << endl;
	purchaseList.OutputList();
}

void BasicMember::AddTransaction(Transaction newTransaction)
{
	purchaseList.AddNode(newTransaction);

	totalSpent = totalSpent + newTransaction.GetPrice();
}


bool BasicMember::RightType()
{
	if(type == BASIC)
		//Basic Members
	{
		if(totalSpent < (PREFERRED_DUES - BASIC_DUES)/PREFERRED_REBATE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
		//Preferred Members
	{
		if(totalSpent > (PREFERRED_DUES - BASIC_DUES)/PREFERRED_REBATE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

dollars BasicMember::GetRebate()
{
	return 0;
}

void BasicMember::CopyMember(BasicMember otherMember)
{
	purchaseList.CopyList(otherMember.purchaseList);

	name = otherMember.GetName();
	memberNum = otherMember.GetMemberNum();
	expirationDate = otherMember.GetExpirationDate();
	type = otherMember.GetType();
	totalSpent = otherMember.GetTotalSpent();

	//Does not alter next and prev
}
