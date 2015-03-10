#ifndef BASICMEMBER_H_
#define BASICMEMBER_H_
#include "MainHeader.h"
#include "TransactionList.h"
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
	BasicMember(const BasicMember& otherMember);

	//Accessors
	string GetName();
	int GetMemberNum();
	Date GetExpirationDate();
	dollars GetTotalSpent();
	memberType GetType();
	BasicMember* GetNext();
	BasicMember* GetPrev();
	TransactionList GetPurchaseList();

	//Mutators
	void SetName(string newName);
	void SetMemberNum(int newNum);
	void SetExpirationDate(Date newDate);
	void SetTotalSpent(dollars newTotal);
	void SetType(memberType newType);
	void SetNext(BasicMember* newNext);
	void SetPrev(BasicMember* newPrev);
	virtual void SetAll(string newName, int newNum, int newMonth, int newDay, int newYear, memberType newType, dollars newTotal = 0);
	virtual void SetAll(string newName, int newNum, int newMonth,
							 int newDay, int newYear, dollars newTotal);
	virtual void AddTransaction(int newMonth, int newDay,int newYear,
								string newName,dollars newPrice,int newAmount);
	virtual void OutputMemberInfo();
	void OutputTransactionList();
	virtual void AddTransaction(Transaction newTransaction);

	bool RightType();

	virtual dollars GetRebate();
	virtual void CopyMember(BasicMember otherMember);

private:
	string name;
	int memberNum;
	Date expirationDate;
	memberType type;
	dollars totalSpent;
	TransactionList purchaseList;
	BasicMember* next;
	BasicMember* prev;
};
#endif
