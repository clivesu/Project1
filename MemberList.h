#ifndef MEMBERLIST_H_
#define MEMBERLIST_H_

#include "BasicMember.h"
#include "PreferredMember.h"
class MemberList : public BasicMember
{
public:
	MemberList();
	~MemberList();
	BasicMember* FindMember(int memberNum) const;
	BasicMember* FindMember(string memberName) const;
	void AddMember(string newName, int newNum, string newType,
				 int newMonth, int newDay, int newYear, dollars newTotal);
	void DeleteMember(BasicMember* target);
	void AddItem(int newMonth,int newDay,int newYear,int newId,
				 string newName,dollars newPrice,int newAmount);
	void OutputItemList(int newId);
	void OutputList();
	void DeleteList();
	void FindExpire(int);
	void PrintRebates();
	void CopyList(MemberList otherList);
	void DailyShopper(Date checkDate);

	void ManualAdd();
	void DeleteMember();
	void SortID(BasicMember* end = NULL);
	int  GetCount();
	void Swap(BasicMember* one, BasicMember* two);

	double MemberList::GrandTotal();

private:
	BasicMember* head;
};

#endif /* MEMBERLIST_H_ */
