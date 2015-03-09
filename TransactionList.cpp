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

	while(finder!= NULL && finder->GetItem().quantity != searchItemNum)
	{
		finder = finder->GetNext();
	}

	return finder;
}


void TransactionList::AddNode()
{

	Transaction* newNode;

	newNode = new Transaction;

	//FILE INPUT NEEDED

	newNode->SetNext(head);


	if(head->GetNext() != NULL)
	{
		head->GetNext()->SetPrev(newNode);
	}

	head = newNode;

}

void TransactionList::AddNode(Transaction NewTransaction)
{
	Transaction* newNode;

	newNode = new Transaction;

	*newNode = NewTransaction;

	newNode->SetNext(head);


	if(head->GetNext() != NULL)
	{
		head->GetNext()->SetPrev(newNode);
	}

	head = newNode;
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

void TransactionList::CopyList(TransactionList otherList)
{
	// A deep copy method, creates a copy of another TransactionList

	Transaction* current;		// Used to traverse the list, and build the list;
	Transaction* newNode;
	Transaction* otherCurrent;	// Used to traverse the otherList

	DeleteList();
	head = NULL;

	otherCurrent = otherList.head;

	if(otherCurrent != NULL)
	{
		newNode = new Transaction;
		current = newNode;
		*current = *otherCurrent;
		head = current;
		current->SetNext(NULL);
		otherCurrent = otherCurrent->GetNext();
		while(otherCurrent != NULL)
		{
			newNode = new Transaction;
			*newNode = *otherCurrent;
			current->SetNext(newNode);
			newNode->SetPrev(current);
			newNode->SetNext(NULL);

			current = current->GetNext();
			otherCurrent = otherCurrent->GetNext();
		}
	}

}

dollars TransactionList::TotalAmount()
{
	Transaction* finder;

	dollars total;
	total = 0;

	finder = head;

	while(finder!= NULL)
	{
		total = total + finder->GetItem().price;
		finder = finder->GetNext();
	}

	return total;
}
