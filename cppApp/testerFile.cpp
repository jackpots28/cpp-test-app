#include "pch.h"
#include "testerFile.h"
#include <algorithm>
#include <execution>
#include <vector>

using namespace std;
using execution::par_unseq;

size_t testSize = 2'000'000;

testerFile::testerFile() {
	tmpVec.resize(testSize);
	for (auto& d : tmpVec) {
		d = (rand() % 100);
	}
}


testerFile::~testerFile() {
	tmpVec.clear();
}

void testerFile::setSrch(double tmpSrch) {
	srch = tmpSrch;
}

void testerFile::refVecSrchAndCount(double& returnPos, double& counterRef){
	counterRef = count(par_unseq, tmpVec.begin(), tmpVec.end(), srch);
	pos = distance(tmpVec.begin(), find(par_unseq, tmpVec.begin(), tmpVec.end(), srch));
	if (pos >= tmpVec.size()) {
		returnPos - 1;
	}
	else
		returnPos = pos;
}

