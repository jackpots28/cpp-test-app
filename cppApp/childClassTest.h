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

	void insertIntoHT(std::wstring key, double val);
	std::wstring findValInTable(double key);

	void clrTable();

	void clrFormsVect();
	std::wstring getVecString(int index);
	void editWStringVec(int index, std::wstring newText);
	int returnWStringVecSize();
	
	void setOutsideToChildVec(std::vector<std::wstring>& outside);

private:
	std::wstring formattedText;
	std::string classConstruct;

	std::vector<std::wstring> tmpTestVec;

	std::unordered_map<double, std::wstring> hashTable;
	std::unordered_map<double, std::wstring>::const_iterator itr;
};

