

#ifndef TRANSACTION_LIST_H_
#define TRANSACTION_LIST_H_

#include "Transaction.h"



class TransactionList
{
public:
	TransactionList();
	~TransactionList();

	Transaction* FindItemNode(string searchName) const;	//Searched for and returns a node based on item name

	void AddNode();
	void AddNode(Transaction newTransaction);
	void AddNode(int newMonth, int newDay, int newYear,
								string newName, dollars newPrice, int newAmount);

	void DeleteNode(Transaction* target);	//Deletes a chosen Transaction node

	void OutputList();	//Outputs the entire Transaction list
	void DeleteList();	//Clears the entire Transaction list

	void CopyList(TransactionList otherList);

	dollars TotalAmount();

private:
	Transaction* head;	//The head of the list
};

#endif


