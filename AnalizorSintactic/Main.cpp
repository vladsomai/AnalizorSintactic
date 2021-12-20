#include "lib.h"



extern bool checkSyntax(std::string input);

int main()
{
	bool res = checkSyntax("ION ARE LEI SI BANI");

	if (res)
	{
		cout << "Syntax OK for singular" << endl;
	}
	else
	{
		cout << "Syntax NOK for singular" << endl;
	}

	res = checkSyntax("ION,MARIA AU LEI SI BANI");

	if (res)
	{
		cout << "Syntax OK for plural" << endl;
	}
	else
	{
		cout << "Syntax NOK for plural" << endl;
	}
}