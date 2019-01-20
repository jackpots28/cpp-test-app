#pragma once

#include "testerFile.h"
#include <unordered_map>
#include <string>
#include <optional>

using namespace std;

class childClassTest : public testerFile
{
public:
	childClassTest();
	~childClassTest();

	void insertIntoHT(wstring key, double val);
	double findValInTable(wstring srchKey);

private:
	wstring formattedText;
	string classConstruct;

	unordered_map<wstring, double> hashTable;
	unordered_map<wstring, double>::const_iterator itr;
};

