#pragma once

#include <sstream>
#include <unordered_map>

using namespace std;

class wordFreqUMap
{
public:
	wordFreqUMap();
	~wordFreqUMap();

	void prntFreq(const wstring &str);

private:
	unordered_map<wstring, int> wordList;
	unordered_map<wstring, int>::iterator itr;
	wstring word;
};

/*
// Prints frequencies of individual words in str
void printFrequencies(const string &str)
{
	// declaring map of <string, int> type, each word
	// is mapped to its frequency
	unordered_map<string, int> wordFreq;

	// breaking input into word using string stream
	stringstream ss(str);  // Used for breaking words
	string word; // To store individual words
	while (ss >> word)
		wordFreq[word]++;

	// now iterating over word, freq pair and printing
	// them in <, > format
	unordered_map<string, int>:: iterator p;
	for (p = wordFreq.begin(); p != wordFreq.end(); p++)
		cout << "(" << p->first << ", " << p->second << ")\n";
}
*/
