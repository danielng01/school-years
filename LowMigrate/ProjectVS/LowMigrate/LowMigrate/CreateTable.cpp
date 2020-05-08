#include "stdafx.h"
#include "LowMigrate.h"
int CreateTable(sql::Connection *con, string * columsNames, int numberOfColumns){

	sql::Statement *stmt = con->createStatement();

	DebugExecute(con,"DROP TABLE IF EXISTS " + columsNames[0]);
	string query = "CREATE TABLE " + columsNames[0] + " ( id INT ,";
	for (int i = 0; i < numberOfColumns - 1; i += 2){

		if ((i + 2) >= (numberOfColumns - 1)){
			query += columsNames[i + 1] + " ";
			query += columsNames[i + 2] + ")";
		}
		else{
			query += columsNames[i + 1] + " ";
			query += columsNames[i + 2] + ", ";
		}
	}
	DebugExecute(con,query);
	return 0;
}