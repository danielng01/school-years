#include "stdafx.h"
#include "LowMigrate.h"

void AddColumn(sql::Connection *con, string tableName, string newColumnName){
	sql::Statement *stmt = con->createStatement();
	//ALTER TABLE `article` ADD `newcol` INT NOT NULL ;
	string query = "ALTER TABLE " + tableName + " ADD " + newColumnName;
	DebugExecute(con,query);
}
void AddColumn(sql::Connection *con, string tableName, string newColumnName, string columnType){
	sql::Statement *stmt = con->createStatement();
	//ALTER TABLE `article` ADD `newcol` INT NOT NULL ;
	string query = "ALTER TABLE " + tableName + " ADD " + newColumnName + " " + columnType;
	DebugExecute(con, query);
}