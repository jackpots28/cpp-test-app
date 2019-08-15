#pragma once

#include <vector>

class testerFile {
public:
	testerFile();
	~testerFile();

	testerFile(std::string& fileName);
	void writeToFile(std::string& msgToWrite);

	void refVecSrchAndCount(double& returnPos, double& counterRef);

	void clearVec();
	void fillVec();

	void setSrch(double tmpSrch);
	int getVecSize();
	
private:
	std::wstring formattedText;
	std::string classConstruct;

	FILE* fp;

	ptrdiff_t pos;

	std::vector<double> tmpVec;

	double srch;

	int itrCount;
};

