#include "pch.h"
#include "openDB.h"

openDB::openDB() { 
	OutputDebugString(L"--OBJECT OF OPENDB CREATED--");
}

openDB::~openDB() {
	sqlite3_close(db);
}

std::string openDB::returnExit(std::string path) {
	pathToDb = path;
	exit = sqlite3_open(path.c_str(), &db);
	if (exit) {
		return "COULD NOT OPEN DATABASE FILE PATH.";
	}
	else {
		return "DATABASE FILE PATH OPENED.";
	}
}