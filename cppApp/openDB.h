#pragma once
#include <pch.h>

class openDB {
private:
	int exit = 0;
	std::string pathToDb = " ";

	sqlite3* db;

public:
	openDB();
	~openDB();
	std::string returnExit(std::string path);
};

