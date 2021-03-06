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

string Transaction::GetItemName()
{
	return itemName;
}

void Transaction::SetItemName(string newName)
{
	itemName = newName;
}

void Transaction::PrintItemName()
{
	cout << itemName;
}

void Transaction::PrintPrice()
{
	cout << price;
}

void Transaction::PrintQuanity()
{
	cout << quanity;
}

void Transaction::PrintDate()
{
	boughtDate.DisplayDate();
	cout << endl;
}

Date Transaction::GetDate()
{
	return boughtDate;
}
