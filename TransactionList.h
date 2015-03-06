#ifndef TRANSACTIONLIST_H_
#define TRANSACTIONLIST_H_

#include "Transaction.h"
class TransactionList : public Transaction
{
public:
	TransactionList();
	~TransactionList();
	void AddNode(int newMonth, int newDay, int newYear,
				 string newName, dollars newPrice,int newAmount);
	void DeleteNode(Transaction* target);
	void OutputList();
	void DeleteList();
private:
	Transaction* head;
};

#endif /* TRANSACTIONLIST_H_ */




