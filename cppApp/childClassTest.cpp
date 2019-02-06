
#include "pch.h"
#include "childClassTest.h"
#include <algorithm>
#include <string>
#include <unordered_map>
#include <optional>



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

void childClassTest::insertIntoHT(std::wstring key, double val) {
	hashTable.insert(std::make_pair(key, val));
	tmpTestVec.push_back(key);
}

double childClassTest::findValInTable(std::wstring srchKey) {
	itr = hashTable.find(srchKey);
	if (itr == hashTable.end()) {
		return -1;
	}
	else {
		return itr->second;
	}
}


void childClassTest::optSearch(std::optional<std::wstring>& optKey, std::optional<double>& optVal) {
	
}

std::wstring childClassTest::getVecString(int index) {
	return tmpTestVec.at(index);
}

void childClassTest::clrFormsVect() {
	tmpTestVec.clear();
}

void childClassTest::clrTable() {
	hashTable.clear();
}