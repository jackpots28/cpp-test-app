
#include "pch.h"
#include "childClassTest.h"
#include <algorithm>
#include <string>
#include <unordered_map>

// Document?

childClassTest::childClassTest() {
	classConstruct = "--child obj created--\n";
	formattedText.resize((classConstruct.length(), ' '));
	std::copy(classConstruct.begin(), classConstruct.end(), formattedText.begin());
	OutputDebugString(formattedText.c_str());
}

childClassTest::~childClassTest() {
	classConstruct = "--child obj Destroyed--\n";
	formattedText.resize((classConstruct.length(), ' '));
	std::copy(classConstruct.begin(), classConstruct.end(), formattedText.begin());
	OutputDebugString(formattedText.c_str());
}

void childClassTest::insertIntoHT(std::wstring val, double key) {
	hashTable.insert(std::make_pair(key, val));
	tmpTestVec.push_back(val);
}

std::wstring childClassTest::findValInTable(double srchKey) {
	itr = hashTable.find(srchKey);
	if (itr != hashTable.end()) {
		return itr->second;
	}
	else
	{
		return L"Nil";
	}
}

void childClassTest::addToWString(std::wstring tmp) {
	formsHoldingString += tmp;
}

/************************************************************************************/
/************************************************************************************/

std::wstring childClassTest::getVecString(int index) {
	return tmpTestVec.at(index);
}

void childClassTest::clrFormsVect() {
	tmpTestVec.clear();
}

void childClassTest::clrTable() {
	hashTable.clear();
}