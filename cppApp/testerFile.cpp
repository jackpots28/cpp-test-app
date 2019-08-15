#include "pch.h"
#include "testerFile.h"
#include "childClassTest.h"


using std::execution::par_unseq;
using std::unique_ptr;

size_t testSize = 5'000'000;

unique_ptr<childClassTest> obj1(new childClassTest());

testerFile::testerFile() {
	itrCount = 1000;

	tmpVec.resize(testSize);
	for (auto& d : tmpVec) {
		d = (rand() % 1000);
	}

	classConstruct = "--testerFile obj created--\n";
	formattedText.resize((classConstruct.length(), ' '));
	std::copy(classConstruct.begin(), classConstruct.end(), formattedText.begin());
	OutputDebugString(formattedText.c_str());
}

testerFile::testerFile(std::string& fileName) {
	fp = fopen(fileName.c_str(), "a");
}

void testerFile::writeToFile(std::string& msgToWrite) {
	if (!fp) {
		OutputDebugString(L"FILE WAS NOT OPENED\n");
	}
	else if (fp) {
		fputs(msgToWrite.c_str(), fp);
	}
}

testerFile::~testerFile() {
	tmpVec.clear();
	fclose(fp);

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

void testerFile::clearVec() {
	tmpVec.clear();
}

int testerFile::getVecSize() {
	return tmpVec.size();
}

void testerFile::fillVec() {
	itrCount = itrCount + 1000;
	if (tmpVec.empty() == true) {
		tmpVec.resize(testSize);
		for (auto& d : tmpVec) {
			d = (rand() % ((1000 + (rand() % 1000)) /4));
		}
	}
	else {
		tmpVec = tmpVec;
	}
	
}

