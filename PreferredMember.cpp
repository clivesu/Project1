#include "PreferredMember.h"

PreferredMember::PreferredMember() : BasicMember(), rebate(0)
{

}

PreferredMember::~PreferredMember()
{
// does nothing
}
void PreferredMember::OutputMemberInfo()
{
BasicMember::OutputMemberInfo();
cout << rebate << endl;
}
//void PreferredMember::AddTransaction(Transaction newTransaction)
//{
// need transaction type
// Overrides the BasicMember method, but includes rebate
//}

void PreferredMember::SetAll(string newName, int newNum, int newMonth, int newDay, int newYear, dollars newTotal, dollars newRebate)
{
BasicMember::SetAll(newName,newNum,newMonth,newDay,newYear,newTotal);
rebate = newRebate;
}
dollars PreferredMember::GetRebate()
{
return rebate;
}

