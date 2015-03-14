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

TransactionList::TransactionList(const TransactionList& otherTransaction)
{
	// DeepCopy


	Transaction* current;
	Transaction* newest;
	Transaction* otherCurrent;

	otherCurrent = otherTransaction.head;
	if(otherCurrent == NULL)
	{
		head = NULL;
	}
	else
	{
		newest = new Transaction;
		head = newest;
		*newest = *otherCurrent;

		otherCurrent = otherCurrent->GetNext();

		while(otherCurrent != NULL)
		{
			current = newest;
			newest = new Transaction;

			*newest = *otherCurrent;

			current->SetNext(newest);
			newest->SetPrev(current);
			newest->SetNext(NULL);

			otherCurrent = otherCurrent->GetNext();
		}
	}


	total = otherTransaction.total;
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

void TransactionList::CopyList(const TransactionList& copyList)
{
	// DeepCopy


	Transaction* current;
	Transaction* newest;
	Transaction* otherCurrent;

	otherCurrent = copyList.head;
	if(otherCurrent == NULL)
	{
		head = NULL;
	}
	else
	{
		newest = new Transaction;
		head = newest;
		*newest = *otherCurrent;

		otherCurrent = otherCurrent->GetNext();

		while(otherCurrent != NULL)
		{
			current = newest;
			newest = new Transaction;

			*newest = *otherCurrent;

			current->SetNext(newest);
			newest->SetPrev(current);
			newest->SetNext(NULL);

			otherCurrent = otherCurrent->GetNext();
		}
	}


	total = copyList.total;
}

Transaction* TransactionList::GetHead()
{
	return head;
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

void   TransactionList::Swap(Transaction* one, Transaction* two)
{
	//Only works if these two nodes are originally adjacent members of a linked list,
	// with one before two.

	//Switches places
	one->SetNext(two->GetNext());
	two->SetPrev(one->GetPrev());
	one->SetPrev(two);
	two->SetNext(one);

	//Makes sure the rest of the list knows about the switch
	if(two->GetPrev() != NULL)
	{
		two->GetPrev()->SetNext(two);
	}
	else
	{
		head = two;
	}

	if(one->GetNext() != NULL)
	{
		one->GetNext()->SetPrev(one);
	}
}

void TransactionList::SortByItem(Transaction* end)
{
	// Bubble sorts the list
	// Each iteration brings the largest memberID to the end of the list.
	// Recursion shrinks the size of the list with each iteration


	// Excludes compilations errors
	if(head == end || head->GetNext() == end) // lazy evaluation
	{
		return;
	}

	Transaction* current;
	current  = head;

		while(current->GetNext() != end)
		{
			if(current->GetItemName() > current->GetNext()->GetItemName())
			{
				Swap(current, current->GetNext());
			}
			else
			{
				// Only update on non-switches because the switch effectively moves
				// the pointer one position already
				current = current->GetNext();
			}
		}


		//Recursion does the same sort, but each following iteration ends one node earlier.
		//Excludes the sorted part of the list
		SortByItem(current);

}

void TransactionList::FixCapitalization()
{
	Transaction* current;
	string newName;

	current = head;

	while(current != NULL)
	{
		// If the first letter is not capitalized
		if(current->GetItemName()[0] != toupper(current->GetItemName()[0]))
		{
			newName = "";
			newName = newName + char(toupper(current->GetItemName()[0])) + current->GetItemName().substr(1);
			current->SetItemName(newName);

		}
		current = current->GetNext();
	}
}


Transaction* TransactionList::FindLast()
{
	//Finds the tail of a list

	Transaction* current;

	current = head;

	if(current != NULL)
	{
		while(current->GetNext() != NULL)
		{
			current = current->GetNext();
		}
	}
	return current;
}

TransactionList TransactionList::operator +(const TransactionList& otherList)
{
	TransactionList other;
	TransactionList sum;
	Transaction* current;
	Transaction* newest;
	Transaction* otherCurrent;


	sum.CopyList(*this);

	if(sum.head == NULL)
	{
		sum = other;
	}
	else if(otherList.head == NULL)
	{
		//just return sum
	}
	else
	{ //combines two non-empty lists
		current = sum.FindLast();

		otherCurrent = otherList.head;

		while(otherCurrent != NULL)
		{
			newest = new Transaction;
			*newest = *otherCurrent;

			newest->SetPrev(current);
			current->SetNext(newest);

			current = newest;

			otherCurrent = otherCurrent->GetNext();
		}

	}

	return sum;
}
