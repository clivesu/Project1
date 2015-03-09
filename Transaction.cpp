#include "Transaction.h"

Transaction::Transaction()	//Basic initiallization of values in transaction class
{
	theItem.name = ' ';
	theItem.quantity = 0;
	theItem.price = 0.0;
	memberNum = 0;

	next = NULL;
	prev = NULL;
}

Transaction::Transaction(string newName,int newQuantity,
			   dollars newPrice,int newMember) //Specified inititallization of values in transaction class
{
	theItem.name = newName;
	theItem.quantity = newQuantity;
	theItem.price = newPrice;
	memberNum = newMember;

	next = NULL;
	prev = NULL;

}

Transaction::~Transaction() //Destructor
{

}

Item Transaction::GetItem()
{
	return theItem;
}

void Transaction::SetItem(string newName,
			  int newQuantity,
			  float newPrice)
{
	theItem.name = newName;
	theItem.quantity = newQuantity;
	theItem.price = newPrice;
}

void Transaction::PrintItem()
{
	cout << theItem.name << ' ' << theItem.quantity << ' ' << theItem.price; //Subject to change based on formatting
}

int Transaction::GetMemberNum()
{
	return memberNum;
}

void Transaction::SetMemberNum(int newMemberNum)
{
	memberNum = newMemberNum;
}

void Transaction::PrintMemberNum()
{
	cout << memberNum;
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
