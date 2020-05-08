#include "stdafx.h"
#include "LowMigrate.h"

void OneToMany(sql::Connection *con, string tableName1, string tableName2){
	sql::Statement *stmt = con->createStatement();
	string query = "ALTER TABLE " + tableName2 + " ADD " + tableName1+"_id INT";
	DebugExecute(con,query);
}