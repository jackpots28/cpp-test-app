#pragma once
#include <pch.h>

class openDB {
private:
	int exit = 0;
	std::string pathToDb = " ";
	char* messageError;

	sqlite3* db;

public:
	openDB();
	~openDB();

	void takeInQuery(std::string query);
	void classCallback(sqlite3* classDB, std::string classQuery);

	std::string returnExit(std::string path);
	void closeDB();
};

