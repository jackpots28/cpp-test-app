#pragma once

#include <vector>

using namespace std;


class testerFile {
public:
	testerFile();
	~testerFile();

	void refVecSrchAndCount(double& returnPos, double& counterRef);

	void setSrch(double tmpSrch);
	
private:
	wstring formattedText;
	string classConstruct;
	ptrdiff_t pos;
	vector<double> tmpVec;
	double srch;
};
