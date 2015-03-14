#include "TransactionList.h"
#include <iomanip>

TransactionList::TransactionList()
{
	head  = NULL;
	total = 0;
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
	total = total + (newPrice * newAmount);

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

void TransactionList::DailyOutputList()
{
	Transaction* traverser;
	traverser = head;
	traverser->PrintDate();

	cout << left;
	cout << setw(30) <<"Item"     << setw(10) << "Price"
		 << setw(10) << "Quanity" << endl;

	while(traverser != NULL)
	{
		cout << setw(30);
		traverser->PrintItemName();
		cout << setw(10);

		traverser->PrintPrice();
		cout << setw(10);
		traverser->PrintQuanity();
		traverser = traverser->GetNext();
		cout << endl;
	}
	cout << right;
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

void TransactionList::CopyList(TransactionList copyList)
{
	head  = copyList.head;
	total = copyList.total;
}

double TransactionList::GetTotal()
{
	return total;
}

bool TransactionList::FindDate(Date searchDate)
{
	Transaction* traverser;
	traverser = head;
	bool found = false;
	Date temp;

	while(traverser != NULL && found == false)
	{

		temp = traverser->GetDate();

		if(temp == searchDate)
		{
			found = true;
		}
		traverser = traverser->GetNext();
	}

	return found;
}
