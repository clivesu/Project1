#include "PreferredMember.h"

PreferredMember::PreferredMember() : BasicMember(), rebate(0)
{
	rebate = 0;
}

PreferredMember::~PreferredMember()
{
// does nothing
}

void PreferredMember::OutputMemberInfo()
{
	BasicMember::OutputMemberInfo();
	GetRebate();
	cout << "Rebate Amount: $" << rebate << endl;

}

void PreferredMember::AddTransaction(Transaction newTransaction)
{
 //need transaction type
// Overrides the BasicMember method, but includes rebate
}

void PreferredMember::SetAll(string newName, int newNum, int newMonth,
		     int newDay, int newYear, memberType newType, dollars newTotal, dollars newRebate)
{
	BasicMember::SetAll(newName,newNum,newMonth,newDay,newYear, newType, newTotal);
	rebate = newRebate;
}

dollars PreferredMember::GetRebate()
{
	rebate = GetTotalSpent() * PREFERRED_REBATE;
	return rebate;
}

void PreferredMember::CopyMember(PreferredMember otherMember)
{
	rebate = otherMember.rebate;
	BasicMember::CopyMember(otherMember);
}

