/*
ID ARE LEI
ID ARE BANI
ID ARE LEI SI BANI

ID, ID AU LEI
ID, ID AU BANI
ID, ID AU LEI SI BANI

typeof ID = ID
typeof LEI = INT
typeof BANI = INT
ARE - KEYWORD(folosit ca si operator intre ID si BANI sau LEI
SI - KEYWORD(folosit ca si operator intre cei doi operanzi BANI, LEI)
*/

#include "lib.h"
const std::string keywordARE = "ARE";
const std::string keywordAU = "AU";
const std::string keywordSI = "SI";

bool checkSyntaxSingle(std::string singleInput);
bool checkSyntaxPlural(std::string pluralInput);

bool checkSyntax(std::string input)
{
	bool result = false;

	//in cazul in care avem ambele keyworduri de plural si singular, vom opri executia
	if ((input.find(keywordARE) != std::string::npos) && (input.find(keywordAU) != std::string::npos))
		return false;
		
    //vom parsa string-ul si vom verifica daca acesta contine keywordurile declarate ca si const
	if (input.find(keywordARE) != std::string::npos)
	 result = checkSyntaxSingle(input);


	if (input.find(keywordAU) != std::string::npos)
	{
		if (input.find(",") != std::string::npos)
		{
			result = checkSyntaxPlural(input);
		}
	}

	return result;

}


/*
 *    id keyword int si int
 * 1. Verificam cuvantul de dinainte de "ARE"
 * 2. Verificam cuvantul dupa "ARE".
 * 3. Verificam daca input-ul contine "SI"
 */
bool checkSyntaxSingle(std::string singleInput)
{
	std::string beforeARE{};
	std::string afterARE{};
	std::string beforeSI{};
	std::string afterSI{};
	bool inputContainsSI = false;
	
	beforeARE = singleInput.substr(0, singleInput.find(keywordARE));
	afterARE = singleInput.substr(singleInput.find(keywordARE)+3, singleInput.length() - (singleInput.find(keywordARE) + 3));

	if (beforeARE == "" || afterARE == "")
		return false;

	if (afterARE.find(keywordSI) != std::string::npos)
	{
		beforeSI = afterARE.substr(0, afterARE.find(keywordSI));
		afterSI = afterARE.substr(afterARE.find(keywordSI) + 3, afterARE.length() - (afterARE.find(keywordSI) + 3));

		if (beforeSI.find("LEI") != std::string::npos && afterSI.find("BANI") != std::string::npos)
			return true;
		else
			return false;
	}

	if (afterARE.find("LEI") != std::string::npos || afterARE.find("BANI") != std::string::npos)
	{
		return true;
	}


	return false;
}

bool checkSyntaxPlural(std::string pluralInput)
{
	std::string beforeAU{};
	std::string afterAU{}; 
	std::string beforeSI{};
	std::string afterSI{};
	bool inputContainsSI = false;

	beforeAU = pluralInput.substr(0, pluralInput.find(keywordAU));
	afterAU = pluralInput.substr(pluralInput.find(keywordAU) + 3, pluralInput.length() - (pluralInput.find(keywordAU) + 3));


	if (beforeAU == "" || afterAU == "")
		return false;

	if (afterAU.find(keywordSI) != std::string::npos)
	{
		beforeSI = afterAU.substr(0, afterAU.find(keywordSI));
		afterSI = afterAU.substr(afterAU.find(keywordSI) + 3, afterAU.length() - (afterAU.find(keywordSI) + 3));

		if (beforeSI.find("LEI") != std::string::npos && afterSI.find("BANI") != std::string::npos)
			return true;
		else
			return false;
	}

	if (afterAU.find("LEI") != std::string::npos || afterAU.find("BANI") != std::string::npos)
	{
		return true;
	}


	return false;
}
