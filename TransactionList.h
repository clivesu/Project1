

#ifndef TRANSACTION_LIST_H_
#define TRANSACTION_LIST_H_

#include "Transaction.h"



class TransactionList
{
	TransactionList();
	~TransactionList();

	Transaction* FindMemberNode(int searchMemberNum) const; //Searched for and returns a node based on member num
	Transaction* FindItemNode(string searchName) const;	//Searched for and returns a node based on item name
	Transaction* FindItemNode(int searchItemNum) const;	//Searched for and returns a node based on item num

	void AddNode();				//Creates a new Transaction node
	void DeleteNode(Transaction* target);	//Deletes a chosen Transaction node

	void OutputList();	//Outputs the entire Transaction list
	void DeleteList();	//Clears the entire Transaction list

private:
	Transaction* head;	//The head of the list
};

#endif


