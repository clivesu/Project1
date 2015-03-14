#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <iostream>
#include "Date.h"
using namespace std;

class Transaction
{
public:
	Transaction();
	virtual ~Transaction();
	virtual void SetItem(int newMonth, int newDay, int newYear, string newName,
				 dollars newPrice,int newAmount);
	virtual void PrintItem(); //Outputs the name, number and price of an item
	Transaction* GetNext();
	void SetNext(Transaction* newNext);
	Transaction* GetPrev();
	Date GetDate();
	void SetPrev(Transaction* newPrev);

	string GetItemName();
	void SetItemName(string newName);

	void PrintItemName();
	void PrintPrice();
	void PrintQuanity();
	void PrintDate();

private:
	Date    boughtDate;
	string  itemName;
	dollars price;
	int		quanity;
	Transaction *next;
	Transaction *prev;
};

#endif /* TRANSACTION_H_ */
