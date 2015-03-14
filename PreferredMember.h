#ifndef PREFERREDMEMBER_H_
#define PREFERREDMEMBER_H_
#include "BasicMember.h"
class PreferredMember : public BasicMember
{
public:
	PreferredMember();
	virtual ~PreferredMember();
	virtual void OutputMemberInfo();
	virtual void AddTransaction(Transaction newTransaction);
	virtual void SetAll(string newName, int newNum, int newMonth,
						int newDay, int newYear, memberType newType, dollars newTotal = 0,
						dollars newRebate = 0);
	virtual void CopyMember(PreferredMember otherMember);
	//Accessor
	dollars GetRebate();
private:
	dollars rebate;
};
#endif
