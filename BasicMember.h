#ifndef BASICMEMBER_H_
#define BASICMEMBER_H_
#include "MainHeader.h"
#include "Date.h"
#include "TransactionList.h"
#include <string>
#include <iostream>
#include <iomanip>

enum memberType
{
BASIC,
PREFERRED
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
	int GetMonthEx();
	Date GetExpirationDate();
	dollars GetTotalSpent();
	memberType GetType();
	BasicMember* GetNext();
	BasicMember* GetPrev();

	//Mutators
	void SetName(string newName);
	void SetMemberNum(int newNum);
	void SetExpirationDate(Date newDate);
	void SetTotalSpent(dollars newTotal);
	void SetType(memberType newType);
	void SetNext(BasicMember* newNext);
	void SetPrev(BasicMember* newPrev);
	virtual void SetAll(string newName, int newNum, int newMonth,
						int newDay, int newYear, memberType newType,
						dollars newTotal = 0);
	virtual void AddTransaction(int newMonth, int newDay,int newYear,
							string newName,dollars newPrice,int newAmount);
	virtual void OutputMemberInfo();
	void OutputTransactionList();
	virtual void AddTransaction(Transaction newTransaction);
	bool RightType();
	virtual dollars GetRebate();
	virtual void CopyMember(BasicMember otherMember);
	bool FindDate(Date searchDate);

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
