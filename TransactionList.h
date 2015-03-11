#ifndef TRANSACTIONLIST_H_
#define TRANSACTIONLIST_H_

#include "Transaction.h"
class TransactionList : public Transaction
{
public:
	TransactionList();
	~TransactionList();
	void   AddNode(int newMonth, int newDay, int newYear,
				 string newName, dollars newPrice,int newAmount);
	void   DeleteNode(Transaction* target);
	void   OutputList();
	void   DailyOutputList();
	void   DeleteList();
	void   CopyList(TransactionList);
	double GetTotal();
	bool   FindDate(Date searchDate);

private:
	Transaction* head;
	double       total;
};

#endif /* TRANSACTIONLIST_H_ */
