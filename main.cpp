
#include "MainHeader.h"

#include "BasicMember.h"
#include "PreferredMember.h"
#include "Date.h"
#include "MemberList.h"

#include "FunctionHeader.h"

using namespace std;



int main()
{
	ifstream infile;            //PROCESS - Open input stream
	string   fileName;          //PROCESS - Use  of string for file name
	MemberList list;

	fileName = "warehouse shoppers.txt";
	infile.open(fileName.c_str());

	ReadMembersFile(infile, list);
	list.OutputList();
	return 0;
}

