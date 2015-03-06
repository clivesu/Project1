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

BasicMember* MemberList::FindNode(int memberNum) const
{
	BasicMember* finder;
	finder = head;
	while(finder != NULL && finder->GetMemberNum() != memberNum)
	{
		finder = finder->GetNext();
	}

	return finder;
}

void MemberList::AddNode(string newName, int newNum, string newType,
		          int newMonth, int newDay, int newYear, dollars newTotal)
{

	BasicMember* newNode;

	if(newType == "Basic")
	{
	newNode = new BasicMember;
	newNode->SetAll(newName,newNum,newMonth,newDay,newYear,newTotal = 0);
	}

	if(newType == "Preferred")
	{
	newNode = new PreferredMember;
	newNode->SetAll(newName,newNum,newMonth,newDay,newYear,newTotal = 0);
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
				cout << "Renew price: $55.00" << endl;
			}
			if(typeid(*current) == typeid(PreferredMember))
			{
				cout << "Renew price: $95.00" << endl;
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

void MemberList::DeleteNode(BasicMember* target)
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
