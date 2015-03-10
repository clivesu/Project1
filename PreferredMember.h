#ifndef PREFERREDMEMBER_H_
#define PREFERREDMEMBER_H_
#include "BasicMember.h"
class PreferredMember : public BasicMember
{
public:
PreferredMember();
virtual ~PreferredMember();
PreferredMember(const PreferredMember& otherMember);

virtual void OutputMemberInfo();
virtual void AddTransaction(Transaction newTransaction);
virtual void SetAll(string newName, int newNum, int newMonth, int newDay, int newYear, memberType newType, dollars newTotal = 0, dollars newRebate = 0);

//Accessor
dollars GetRebate();


virtual void CopyMember(PreferredMember otherMember);

private:
dollars rebate;
};
#endif
