
#include "pch.h"
#include "wordFreqUMap.h"
#include <sstream>
#include <unordered_map>

wordFreqUMap::wordFreqUMap() {

}


wordFreqUMap::~wordFreqUMap() {

}

void wordFreqUMap::prntFreq(const std::wstring& str) {
	std::wstringstream ss(str);
	while (ss >> word) {
		wordList[word]++;
	}

}
