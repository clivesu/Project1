#ifndef BASICMEMBER_H_
#define BASICMEMBER_H_
#include "MainHeader.h"
#include "Date.h"
#include <string>
#include <iostream>
#include <iomanip>

enum memberType
{
BASIC,
PREFFERED
};

class BasicMember
{
public:

	BasicMember();
	virtual ~BasicMember();
	//Accessors
	string GetName();
	int GetMemberNum();
	Date GetExpirationDate();
	dollars GetTotalSpent();
	BasicMember* GetNext();
	BasicMember* GetPrev();
	//Mutators
	void SetName(string newName);
	void SetMemberNum(int newNum);
	void SetExpirationDate(Date newDate);
	void SetTotalSpent(dollars newTotal);
	void SetNext(BasicMember* newNext);
	void SetPrev(BasicMember* newPrev);
	virtual void SetAll(string newName, int newNum, int newMonth, int newDay, int newYear, dollars newTotal = 0);
	virtual void OutputMemberInfo();
	//void OutputTransactionList();
	//virtual void AddTransaction(Transaction newTransaction);

private:
	string name;
	int memberNum;
	Date expirationDate;
	dollars totalSpent;
	//TransactionList purchaseList;
	BasicMember* next;
	BasicMember* prev;
};
#endif
