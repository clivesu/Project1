

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include "Item.cpp"
#include "Date.h"

class Transaction
{
public:
	Transaction();
	Transaction(string newName, int newNum,
		    dollars newPrice, int newMember);
	~Transaction();

	Item GetItem();
	void SetItem(string newName, int newItemNum, float newPrice);	//Sets the name, number, and price of an item
	void PrintItem();		//Outputs the name, number and price of an item
	int GetMemberNum();			//Returns the members number
	void SetMemberNum(int newMemberNum);	//Sets the members number
	void PrintMemberNum();			//Outputs the members number

	Transaction* GetNext();
	void SetNext(Transaction *newNext);
	Transaction* GetPrev();
	void SetPrev(Transaction *newPrev);

private:
	int memberNum;
	Item theItem;
	Date theDate;
	Transaction *next;
	Transaction *prev;
};
#endif


