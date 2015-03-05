#include "TransactionList.h"

TransactionList::TransactionList()
{
	head = NULL;
}

TransactionList::~TransactionList()
{
	DeleteList();
}

Transaction* TransactionList::FindMemberNode(int searchMemberNum) const
{

	Transaction* finder;

	finder = head;

	while(finder!= NULL && finder->GetMemberNum() != searchMemberNum)
	{
		finder = finder->GetNext();
	}

	return finder;
}

Transaction* TransactionList::FindItemNode(string searchName) const
{
	Transaction* finder;

	finder = head;

	while(finder!= NULL && finder->GetItem().name != searchName)
	{
		finder = finder->GetNext();
	}

	return finder;
}

Transaction* TransactionList::FindItemNode(int searchItemNum) const
{
	Transaction* finder;

	finder = head;

	while(finder!= NULL && finder->GetItem().num != searchItemNum)
	{
		finder = finder->GetNext();
	}

	return finder;
}


void TransactionList::AddNode()
{
	// MUST BE FIXED

	Transaction* newNode;

	newNode = new Transaction;

	//FILE INPUT NEEDED

	head = newNode;
	newNode = NULL;

	if(head->GetNext() != NULL)
	{
		head->GetNext()->SetPrev(head);
	}


}

void TransactionList::DeleteNode(Transaction* target)
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

void TransactionList::OutputList()
{
	Transaction* traverser;

	traverser = head;

	while(traverser != NULL)
	{
		traverser->PrintItem();
		traverser->PrintMemberNum();
		traverser = traverser->GetNext();
	}
}

void TransactionList::DeleteList()
{
	Transaction* deleter;


	while(head!= NULL)
	{
		deleter = head->GetNext();
		delete head;
		head = deleter;
	}

}
