#include "pch.h"
#include "openDB.h"

openDB::openDB() { 
	OutputDebugString(L"--OBJECT OF OPENDB CREATED--\n");
}

openDB::~openDB() {
	sqlite3_close(db);
	OutputDebugString(L"--OBJECT OF OPENDB DESTROYED--\n");
}

std::string openDB::returnExit(std::string path) {
	pathToDb = path;
	exit = sqlite3_open(path.c_str(), &db);
	if (exit) {
		OutputDebugString(L"--COULD NOT OPEN DATABASE FILE PATH--\n");
		return "COULD NOT OPEN.";
	}
	else {
		OutputDebugString(L"--DATABASE FILE PATH OPENED--\n");
		return "PATH OPENED.";
	}
}

void openDB::closeDB() {
	sqlite3_close(db);
	OutputDebugString(L"--DATABASE FILEPATH CLOSED--\n");
}

void openDB::takeInQuery(std::string query) {
	exit = sqlite3_exec(db, query.c_str(), NULL, 0, &messageError); 
	if (exit != SQLITE_OK) {
		OutputDebugString(L"--ERROR ON QUERY CALL--\n");
		// std::cout << "ERROR INSERT" << std::endl;
		sqlite3_free(messageError);
	}
	else {
		OutputDebugString(L"--RECORDS MODIFIED SUCCESSFULLY--\n");
		// std::cout << "RECORDS MODIFIED SUCCESSFULLY" << std::endl << std::endl;
	}
	openDB::classCallback(db, query.c_str());
}

void openDB::classCallback(sqlite3* classDB, std::string classQuery) {
	// where "callback" is used to print the state of the table
	sqlite3_exec(classDB, classQuery.c_str(), callback, NULL, NULL);
}