#include "pch.h"
#include "testerFile.h"
#include "childClassTest.h"
#include <algorithm>
#include <execution>
#include <vector>
#include <memory>
#include <iostream>
#include <string>

using std::execution::par_unseq;
using std::unique_ptr;

size_t testSize = 5'000'000;

unique_ptr<childClassTest> obj1(new childClassTest());

testerFile::testerFile() {
	tmpVec.resize(testSize);
	for (auto& d : tmpVec) {
		d = (rand() % 1000);
	}

	classConstruct = "--testerFile obj created--\n";
	formattedText.resize((classConstruct.length(), ' '));
	std::copy(classConstruct.begin(), classConstruct.end(), formattedText.begin());
	OutputDebugString(formattedText.c_str());
}

testerFile::~testerFile() {
	tmpVec.clear();

	classConstruct = "--testerFile obj Destroyed--\n";
	formattedText.resize((classConstruct.length(), ' '));
	std::copy(classConstruct.begin(), classConstruct.end(), formattedText.begin());
	OutputDebugString(formattedText.c_str());
}

void testerFile::setSrch(double tmpSrch) {
	srch = tmpSrch;
}

void testerFile::refVecSrchAndCount(double& returnPos, double& counterRef){
	counterRef = std::count(par_unseq, tmpVec.begin(), tmpVec.end(), srch);
	pos = std::distance(tmpVec.begin(), std::find(par_unseq, tmpVec.begin(), tmpVec.end(), srch));
	if (pos >= tmpVec.size()) {
		returnPos  = -1;
	}
	else
		returnPos = pos;
}

