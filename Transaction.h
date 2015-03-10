

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include "Item.cpp"
#include "Date.h"


class Transaction
{
public:
	Transaction();
	virtual ~Transaction();
	virtual void SetItem(int newMonth, int newDay, int newYear, string newName,
				 dollars newPrice,int newAmount);
	virtual void PrintItem(); //Outputs the name, number and price of an item

	string GetName();
	dollars GetPrice();

	Transaction* GetNext();
	void SetNext(Transaction* newNext);
	Transaction* GetPrev();
	void SetPrev(Transaction* newPrev);



private:
	Date    boughtDate;
	string  itemName;
	dollars price;
	int		quanity;
	Transaction *next;
	Transaction *prev;
};




#endif


