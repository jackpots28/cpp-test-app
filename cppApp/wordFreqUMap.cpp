
#include "pch.h"
#include "wordFreqUMap.h"
#include <sstream>
#include <unordered_map>

using namespace std;

wordFreqUMap::wordFreqUMap() {

}


wordFreqUMap::~wordFreqUMap() {

}

void wordFreqUMap::prntFreq(const wstring& str) {
	wstringstream ss(str);
	while (ss >> word) {
		wordList[word]++;
	}

}
