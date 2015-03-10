/*
 * FunctionHeader.h
 *
 *  Created on: Mar 2, 2015
 *      Author: Clive
 */

#ifndef FUNCTIONHEADER_H_
#define FUNCTIONHEADER_H_

#include "MemberList.h"
#include "TransactionList.h"

void ReadMembersFile(ifstream &infile, MemberList &list);
void ReadItemFile(ifstream &infile, MemberList &list);

#endif /* FUNCTIONHEADER_H_ */
