#pragma once
#include <pch.h>

// used for printing out table contents after actions have been made on the table
static int callback(void* data, int argc, char** argv, char** azColName) {
	int i;
	fprintf(stderr, "%s: ", (const char*)data);

	for (i = 0; i < argc; i++) {
		// std::cout << azColName[i] << argv[i] ? argv[i] : "NULL";
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	std::cout << std::endl;
	return 0;
}