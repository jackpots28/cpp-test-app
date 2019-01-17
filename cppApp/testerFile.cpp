#include "pch.h"
#include "testerFile.h"
#include "childClassTest.h"
#include <algorithm>
#include <execution>
#include <vector>
#include <memory>
#include <iostream>
#include <string>

using namespace std;
using execution::par_unseq;
using std::unique_ptr;

size_t testSize = 2'000'000;

unique_ptr<childClassTest> objTest1(new childClassTest);

testerFile::testerFile() {	
	tmpVec.resize(testSize);
	for (auto& d : tmpVec) {
		d = (rand() % 100);
	}

	classConstruct = "--testerFile obj created--\n";
	formattedText.resize((classConstruct.length(), ' '));
	copy(classConstruct.begin(), classConstruct.end(), formattedText.begin());
	OutputDebugString(formattedText.c_str());
}


testerFile::~testerFile() {
	tmpVec.clear();

	classConstruct = "--testerFile obj Destroyed--\n";
	formattedText.resize((classConstruct.length(), ' '));
	copy(classConstruct.begin(), classConstruct.end(), formattedText.begin());
	OutputDebugString(formattedText.c_str());
}

void testerFile::setSrch(double tmpSrch) {
	srch = tmpSrch;
}

void testerFile::refVecSrchAndCount(double& returnPos, double& counterRef){
	counterRef = count(par_unseq, tmpVec.begin(), tmpVec.end(), srch);
	pos = distance(tmpVec.begin(), find(par_unseq, tmpVec.begin(), tmpVec.end(), srch));
	if (pos >= tmpVec.size()) {
		returnPos  = -1;
	}
	else
		returnPos = pos;
}

