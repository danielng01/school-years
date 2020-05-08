#include "stdafx.h"
#include "LowMigrate.h"
#include <windows.h>

void DebugExecute(sql::Connection *con,string query){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	sql::Statement *stmt = con->createStatement();
	cout << "----------------------------------" << endl;
	
	cout << "Executing query: " << endl;
	SetConsoleTextAttribute(hConsole, (15));
	cout << query << endl;

	stmt->execute(query);
	SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	cout << "Query execution succesfull" << endl;
	SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED));
}