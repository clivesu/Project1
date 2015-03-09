#include "TransactionList.h"

TransactionList::TransactionList()
{
	head = NULL;
}

TransactionList::~TransactionList()
{
	DeleteList();
}

void TransactionList::AddNode(int newMonth, int newDay, int newYear,
							string newName, dollars newPrice,int newAmount)
{
	Transaction* newItem;
	newItem = new Transaction;
	newItem->SetItem(newMonth,newDay,newYear,newName,newPrice,newAmount);

	if(head == NULL)
	{
		head = newItem;
	}

	else
	{
		Transaction* current;
		current = head;
		while(current->GetNext() != NULL)
		{
			current = current->GetNext();
		}
		current->SetNext(newItem);
		newItem->SetPrev(current);
		newItem->SetNext(NULL);
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

