#pragma once
#include "testerFile.h"
#include <unordered_map>

using namespace std;

class childClassTest : public testerFile
{
public:
	childClassTest();
	~childClassTest();

	void insertIntoHT(string key, int val);
	int findValInTable(string srchKey);

private:
	wstring formattedText;
	string classConstruct;

	unordered_map<string, int> hashTable;
	unordered_map<string, int>::const_iterator itr;
};

