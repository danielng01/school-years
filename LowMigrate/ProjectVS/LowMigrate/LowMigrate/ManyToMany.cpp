#include "stdafx.h"
#include "LowMigrate.h"

void ManyToMany(sql::Connection *con, string tableName1, string tableName2){
	sql::Statement *stmt = con->createStatement();
	DebugExecute(con, "DROP TABLE IF EXISTS " + tableName1 + "_" + tableName2);
	string query = "CREATE TABLE " + tableName1 + "_" + tableName2 + " ( " + tableName1 + "_id" + " INT ," + tableName2 + "_id" + " INT )";
	DebugExecute(con, query);
}