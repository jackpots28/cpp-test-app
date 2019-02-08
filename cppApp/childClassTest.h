#pragma once

#include "testerFile.h"
#include <unordered_map>
#include <string>

// Document?

class childClassTest : public testerFile
{
public:
	childClassTest();
	~childClassTest();

	void insertIntoHT(std::wstring key, int val);
	std::wstring findValInTable(int key);

	void clrTable();

	void clrFormsVect();
	std::wstring getVecString(int index);
	void editWStringVec(int index, std::wstring newText);
	int returnWStringVecSize();
	
	void setOutsideToChildVec(std::vector<std::wstring>& outside);
	void editHashTable(int index, std::vector<std::wstring> outside);

private:
	std::wstring formattedText;
	std::string classConstruct;

	std::vector<std::wstring> tmpTestVec;

	std::unordered_map<int, std::wstring> hashTable;
	std::unordered_map<int, std::wstring>::const_iterator itr;
};

