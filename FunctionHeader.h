#ifndef FUNCTIONHEADER_H_
#define FUNCTIONHEADER_H_

#include "MemberList.h"

void ReadMembersFile(ifstream &infile, MemberList &list);
void ReadItemFile(ifstream &infile,MemberList &list,TransactionList &daily);

#endif
