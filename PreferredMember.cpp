#include "PreferredMember.h"

PreferredMember::PreferredMember() : BasicMember(), rebate(0)
{

}

PreferredMember::~PreferredMember()
{

}

PreferredMember::PreferredMember(const PreferredMember& otherMember)
{


}

void PreferredMember::OutputMemberInfo()
{
	BasicMember::OutputMemberInfo();
	cout << rebate << endl;
}

void PreferredMember::AddTransaction(Transaction newTransaction)
{
	BasicMember::AddTransaction(newTransaction);

	rebate = rebate + (newTransaction.GetPrice() * PREFERRED_REBATE);

}

void PreferredMember::SetAll(string newName, int newNum, int newMonth, int newDay, int newYear, memberType newType, dollars newTotal, dollars newRebate)
{
	BasicMember::SetAll(newName,newNum,newMonth,newDay,newYear, newType,newTotal);
	rebate = newRebate;
}

dollars PreferredMember::GetRebate()
{
	return rebate;
}

void PreferredMember::CopyMember(PreferredMember otherMember)
{
	BasicMember::CopyMember(otherMember);
	rebate = otherMember.GetRebate();

	//Does not alter next and prev
}
