#include <iostream>
#include "MemberList.h"
#include "BasicMember.h"
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

void MemberList::AddNode(string newName, int newNum, int newMonth, int newDay, int newYear, memberType newType, dollars newTotal)
{

	BasicMember* newNode;
	newNode = new BasicMember;
	//the new node should be initialized from input here
	newNode->SetAll(newName,newNum,newMonth,newDay,newYear,newType, newTotal = 0);

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
	}
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
