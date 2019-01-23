#pragma once

#include "testerFile.h"
#include <unordered_map>
#include <string>
#include <optional>

class childClassTest : public testerFile
{
public:
	childClassTest();
	~childClassTest();

	void insertIntoHT(std::wstring key, double val);
	double findValInTable(std::wstring srchKey);

	void optSearch(std::optional<std::wstring>& optKey, std::optional<double>& optVal);
	void clrTable();

private:
	std::wstring formattedText;
	std::string classConstruct;

	std::unordered_map<std::wstring, double> hashTable;
	std::unordered_map<std::wstring, double>::const_iterator itr;
};

