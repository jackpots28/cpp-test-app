#include "pch.h"
#include "childClassTest.h"
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

childClassTest::childClassTest() {
	classConstruct = "--child obj created--\n";
	formattedText.resize((classConstruct.length(), ' '));
	copy(classConstruct.begin(), classConstruct.end(), formattedText.begin());
	OutputDebugString(formattedText.c_str());
}


childClassTest::~childClassTest() {
	classConstruct = "--child obj Destroyed--\n";
	formattedText.resize((classConstruct.length(), ' '));
	copy(classConstruct.begin(), classConstruct.end(), formattedText.begin());
	OutputDebugString(formattedText.c_str());
}

void childClassTest::insertIntoHT(string key, int val) {
	hashTable.insert(make_pair(key, val));
}

int childClassTest::findValInTable(string srchKey) {
	itr = hashTable.find(srchKey);
	if (itr == hashTable.end()) {
		return -1;
	}
	else {
		return itr->second;
	}
}