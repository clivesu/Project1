#ifndef TRANSACTIONLIST_H_
#define TRANSACTIONLIST_H_

#include "Transaction.h"
class TransactionList : public Transaction
{
public:
	TransactionList();
	~TransactionList();
	TransactionList(const TransactionList& otherTransaction);
	void   AddNode(int newMonth, int newDay, int newYear,
				 string newName, dollars newPrice,int newAmount);
	void   DeleteNode(Transaction* target);
	void   OutputList();
	void   DailyOutputList();
	void   DeleteList();
	void   CopyList(const TransactionList&);
	Transaction* GetHead();
	double GetTotal();
	bool   FindDate(Date searchDate);
	void   Swap(Transaction* one, Transaction* two);
	void   SortByItem(Transaction* end = NULL);
	void   FixCapitalization();
	Transaction* FindLast();


	TransactionList operator +(const TransactionList& otherList);
private:
	Transaction* head;
	double       total;
};

#endif /* TRANSACTIONLIST_H_ */
