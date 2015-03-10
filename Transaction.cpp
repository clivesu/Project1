#include "Transaction.h"

#include "Transaction.h"

Transaction::Transaction()
{
	boughtDate = Date(1,1,1900);
	itemName   = "none";
	price      = 0;
	quanity    = 0;
	next 	   = NULL;
	prev 	   = NULL;
}

Transaction::~Transaction() //Deconstructor
{

}

void Transaction::SetItem(int newMonth, int newDay, int newYear,
						  string newName, dollars newPrice,int newAmount)
{

		boughtDate = Date(newDay, newMonth, newYear);
		itemName   = newName;
		price      = newPrice;
		quanity    = newAmount;
}

void Transaction::PrintItem()
{
	cout << "Date Bought: ";
	boughtDate.DisplayDate();
	cout << endl;
	cout << "Item:        " << itemName << endl;
	cout << "Price:       " << price    << endl;
	cout << "Quanity:     " << quanity  << endl << endl;
}

string Transaction::GetName()
{
	return itemName;
}

dollars Transaction::GetPrice()
{
	return price;
}

Transaction* Transaction::GetNext()
{
	return next;
}

void Transaction::SetNext(Transaction *newNext)
{
	next = newNext;
}

Transaction* Transaction::GetPrev()
{
	return prev;
}

void Transaction::SetPrev(Transaction *newPrev)
{
	prev = newPrev;
}



