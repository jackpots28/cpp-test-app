#include <pch.h>
#include "queryMakerDB.h"

queryMakerDB::queryMakerDB() { OutputDebugString(L"--QUERYMAKER OBJECT CREATED--\n"); }
queryMakerDB::~queryMakerDB() { OutputDebugString(L"--QUERYMAKER OBJECT DESTROYED--\n"); }

void queryMakerDB::getInfo() {
	
}

void queryMakerDB::classCallback(sqlite3* classDB, std::string classQuery) {
	// where "callback" is used to print the state of the table
	OutputDebugString(L"--classCallback CALLED--\n");
	sqlite3_exec(classDB, classQuery.c_str(), callback, NULL, NULL);
}


// updated for textBox input -- not working currently
std::string queryMakerDB::txtBoxCreateInsrt(int id, int age) {
	std::string tmpFunStr = ("('"+ std::to_string(id) +"', '" + classFname + "', \
		'" + classLname + "', '"+ std::to_string(age) +"', '" + std::to_string(classSal) + "');");
	 return ("INSERT INTO CPP_TEST_TABLE VALUES") + tmpFunStr;
}

//-- update query working
std::string queryMakerDB::createUpdateNameQ(int id) {
	
	updateQue = ("UPDATE CPP_TEST_TABLE SET NAME = '" + classFname + "' WHERE ID = '" + std::to_string(id) + "';");
	return updateQue;
}

//-- delete query working correctly in cppApp.sln
std::string queryMakerDB::deleteQuery(int deleteId) {

	deleteQue = "DELETE FROM CPP_TEST_TABLE WHERE ID = '" + std::to_string(deleteId) + "';";
	return deleteQue;
}


