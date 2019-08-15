
#include "pch.h"
#include "childClassTest.h"

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

void childClassTest::insertIntoHT(std::wstring val, int key) {
	hashTable.insert(std::make_pair(key, val));
	tmpTestVec.push_back(val);
}

std::wstring childClassTest::findValInTable(int srchKey) {
	itr = hashTable.find(srchKey);
	if (itr != hashTable.end()) {
		return itr->second;
	}
	else
	{
		return L"Nil";
	}
}

void childClassTest::editHashTable(int index, std::vector<std::wstring> outside) {
	hashTable[index] = outside.at(index);
}

void childClassTest::setOutsideToChildVec(std::vector<std::wstring>& outside) {
	outside = tmpTestVec;
}


void childClassTest::editWStringVec(int index, std::wstring newText) {
	tmpTestVec.at(index) = (newText + L"\r\n"); 
}

std::wstring childClassTest::getVecString(int index) {
	return std::wstring(tmpTestVec.at(index));
}

int childClassTest::returnWStringVecSize() {
	return tmpTestVec.size();
}


void childClassTest::clrFormsVect() {
	tmpTestVec.clear();
}

void childClassTest::clrTable() {
	hashTable.clear();
}