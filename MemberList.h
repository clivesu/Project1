#include "BasicMember.h"
#include "PreferredMember.h"
class MemberList : public BasicMember
{
public:
MemberList();
~MemberList();
BasicMember* FindNode(int memberNum) const;
void AddNode(string newName, int newNum, int newMonth, int newDay, int newYear, dollars newTotal);
void DeleteNode(BasicMember* target);
void OutputList();
void DeleteList();
private:
BasicMember* head;
};
