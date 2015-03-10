#include "FunctionHeader.h"

void ReadMembersFile(ifstream &infile, MemberList &list)
{
	string id;
	int    num;
	int    numDay;
	int    numMonth;
	int    numYear;
	string name;
	string type;
	string month;
	string day;
	string year;

	if(infile.is_open())
	{
		while(!infile.eof())
		{
				getline(infile,name);
				getline(infile,id);
				num = atoi(id.c_str());
				getline(infile,type);

				getline(infile, month, '/');
				numMonth = atoi(month.c_str());
				getline(infile, day, '/');
				numDay = atoi(day.c_str());
				getline(infile, year);
				numYear = atoi(year.c_str());

				//list.AddNode(name,quantity,numMonth,numDay,numYear,0);
		}
		infile.close();
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
}
