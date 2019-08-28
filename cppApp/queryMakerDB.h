#pragma once
#include <pch.h>

class queryMakerDB
{
	//-- data for tables
	float classSal = 100.00;
	std::string classFname = "FNAME ";
	std::string classLname = "LNAME ";

	//-- return strings for different ques
	//std::string tmpFunStr = " ";
	std::string updateQue = " ";
	std::string deleteQue = " ";

public:
	queryMakerDB();
	~queryMakerDB();

	void getInfo();
	void classCallback(sqlite3*, std::string);

	//-- insert query working in cppApp.sln
	std::string txtBoxCreateInsrt(int id, int age);

	//-- update query working
	std::string createUpdateNameQ(int id);

	//-- delete query working in cppApp.sln
	std::string deleteQuery(int deleteId);

};

/*
--Need to make a method that takes a vector and inserts them into 
--a table
--
--Also need to make an update query method for doing the samething,
--but with vectors of data
*/

