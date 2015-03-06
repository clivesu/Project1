#ifndef MEMBERLIST_H_
#define MEMBERLIST_H_

#include "BasicMember.h"
#include "PreferredMember.h"
class MemberList : public BasicMember
{
public:
	MemberList();
	~MemberList();
	BasicMember* FindNode(int memberNum) const;
	void AddNode(string newName, int newNum, string newType,
				 int newMonth, int newDay, int newYear, dollars newTotal);
	void DeleteNode(BasicMember* target);
	void AddItem(int newMonth,int newDay,int newYear,int newId,
				 string newName,dollars newPrice,int newAmount);
	void OutputItemList(int newId);
	void OutputList();
	void DeleteList();
	void FindExpire(int);
private:
	BasicMember* head;
};

#endif /* MEMBERLIST_H_ */
