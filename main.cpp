
#include "MainHeader.h"

#include "BasicMember.h"
#include "PreferredMember.h"
#include "Date.h"
#include "MemberList.h"

#include "FunctionHeader.h"

using namespace std;



int main()
{
	int choice;

	cout << "INTRO MESSAGE\n\n";

	cout << "\nHello, what kind of user are you?\n";
	cout << "1. Customer at Bulk Club\n";
	cout << "2. Employee at Bulk Club\n";

	choice = GetAndCheckInt(1, 2, "Please Enter Your Selection: ");

	switch(choice)
	{
	case 1: //customer
			{
				cout << "\nHello Customer, what would you like to do?\n";
				cout << "1. List My Purchases\n";
				cout << "2. Check whether I should change membership type\n";
				cout << "3. See Customer Info\n";
				choice = GetAndCheckInt(1, 3, "Please Enter Your Selection: ");
				switch(choice)
				{
				case 1: //List Purchases
					break;
				case 2: //Check Membership type
					break;
				case 3: //Output Customer Info
					break;
				default:
					break;
				}
			}
			break;
	case 2:
			{
				cout << "\nHello Employee, what would you like to do?\n";
				cout << "1. See Sales Data\n";
				cout << "2. See Customer Data\n";
				choice = GetAndCheckInt(1, 2, "Please Enter Your Selection: ");
				switch(choice)
				{
				case 1: //Sales Data Options
						{
							cout << "\nWhat type of customer data would you like to see?\n";
							cout << "1. Generate Daily Sales Report\n";
							cout << "2. Generate Total Sales Report\n";
							choice = GetAndCheckInt(1, 3, "Please Enter Your Selection: ");
							switch(choice)
							{
							case 1: //Daily
								break;
							case 2: //Total
								break;
							default:
								break;
							}
						}
					break;
				case 2: //Customer Data Options
				{
					cout << "\nWhat type of customer options would you like to perform?\n";
					cout << "1. Add Customer\n";
					cout << "2. Delete Customer\n";
					cout << "3. See Member Rebates\n";
					cout << "4. List Customers By Expiration Month\n";
					choice = GetAndCheckInt(1, 4, "Please Enter Your Selection: ");
					switch(choice)
					{
					case 1: //Add Customer
						break;
					case 2: //Delete Customer
						break;
					case 3: //See Rebates
						break;
					case 4: //List by expiration
						break;
					default:
						break;
					}
				}
					break;
				default:
					break;
				}
			}
			break;
	default:
		break;
	}

//	ifstream infile;            //PROCESS - Open input stream
//	string   fileName;          //PROCESS - Use  of string for file name
//	MemberList list;
//
//	fileName = "warehouse shoppers.txt";
//	infile.open(fileName.c_str());
//
//	ReadMembersFile(infile, list);
//	list.OutputList();
//	return 0;
}

