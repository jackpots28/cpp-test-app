#pragma once

#include <vector>

class testerFile {
public:
	testerFile();
	~testerFile();

	void refVecSrchAndCount(double& returnPos, double& counterRef);

	void clearVec();
	void fillVec();

	void setSrch(double tmpSrch);
	int getVecSize();
	
private:
	std::wstring formattedText;
	std::string classConstruct;

	ptrdiff_t pos;

	std::vector<double> tmpVec;

	double srch;

	int itrCount;
};

