#include "stdafx.h"

#include "LowMigrate.h"




int SplitMigrateGetColumnToSplitID(sql::Connection *con, string tableName, string columnToSplit){
	sql::ResultSet* res;
	sql::Statement *stmt = con->createStatement();
	res = stmt->executeQuery("SELECT * FROM " + tableName);
	ResultSetMetaData *res_meta;
	res_meta = res->getMetaData();
	int columnToSplitID;
	//find columnToSplit position
	for (int i = 0; i < res_meta->getColumnCount(); i++){
		string columnName = res_meta->getColumnName(i + 1);
		if (columnName.compare(columnToSplit) == 0){
			columnToSplitID = i + 1;
			//cout << columnToSplitID << endl;
		}
		//cout << columnName << endl;
	}
	return columnToSplitID;
}

string GetSplitMigrationCreateLeftTableQuery(sql::Connection *con, string tableName, string columnToSplit){
	sql::ResultSet* res;
	sql::Statement *stmt = con->createStatement();
	res = stmt->executeQuery("SELECT * FROM " + tableName);
	ResultSetMetaData *res_meta;
	res_meta = res->getMetaData();
	int columnToSplitID = SplitMigrateGetColumnToSplitID(con, tableName, columnToSplit);

	int lastColumnIndex = res_meta->getColumnCount();
	if (columnToSplitID == lastColumnIndex){
		lastColumnIndex -= 1;
	}
	string query = "CREATE TABLE " + tableName + "_part1" + " ( " + columnToSplit + "_id INT, ";
	for (int i = 0; i < res_meta->getColumnCount(); i++){
		if (columnToSplitID == (i + 1)){
			continue;
		}
		if ((i + 1) >= lastColumnIndex){
			if (res_meta->getColumnTypeName(i + 1).compare("VARCHAR") == 0){
				query += " " + res_meta->getColumnName(i + 1) + " ";
				query += " " + res_meta->getColumnTypeName(i + 1) + "(100)" + ") ";
			}
			else{
				query += " " + res_meta->getColumnName(i + 1) + " ";
				query += " " + res_meta->getColumnTypeName(i + 1) + ") ";
			}

		}
		else{
			if (res_meta->getColumnTypeName(i + 1).compare("VARCHAR") == 0){
				query += " " + res_meta->getColumnName(i + 1) + " ";
				query += " " + res_meta->getColumnTypeName(i + 1) + "(100)" + ", ";
			}
			else{
				query += " " + res_meta->getColumnName(i + 1) + " ";
				query += " " + res_meta->getColumnTypeName(i + 1) + ", ";
			}
		}

	}
	//cout << query << endl;
	return query;

}

string GetSplitMigrationCreateRightTableQuery(sql::Connection *con, string tableName, string columnToSplit){
	sql::ResultSet* res;
	sql::Statement *stmt = con->createStatement();
	res = stmt->executeQuery("SELECT * FROM " + tableName);
	ResultSetMetaData *res_meta;
	res_meta = res->getMetaData();
	string query = "CREATE TABLE " + tableName + "_part2" + " (id INT, " + columnToSplit;
	for (int i = 0; i < res_meta->getColumnCount(); i++){
		if (columnToSplit.compare(res_meta->getColumnName(i + 1)) == 0){
			if (res_meta->getColumnTypeName(i + 1).compare("VARCHAR") == 0){
				query += " " + res_meta->getColumnTypeName(i + 1) + "(100)" + " )";
			}
			else{
				query += " " + res_meta->getColumnTypeName(i + 1) + " )";
			}

		}
	}
	//cout << query << endl;
	return query;
}
int SplitMigrate(sql::Connection *con, string tableName, string columnToSplit){
	sql::ResultSet* res;
	sql::Statement *stmt = con->createStatement();
	DebugExecute(con,"DROP TABLE IF EXISTS " + tableName + "_part1");
	DebugExecute(con,"DROP TABLE IF EXISTS " + tableName + "_part2");

	string queryLeftTable = GetSplitMigrationCreateLeftTableQuery(con, tableName, columnToSplit);
	DebugExecute(con,queryLeftTable);

	string queryCreateRightTable = GetSplitMigrationCreateRightTableQuery(con, tableName, columnToSplit);
	DebugExecute(con,queryCreateRightTable);
	string query;

	res = stmt->executeQuery("SELECT * FROM " + tableName);
	ResultSetMetaData *res_meta;

	res_meta = res->getMetaData();
	int columnToSplitID = SplitMigrateGetColumnToSplitID(con, tableName, columnToSplit);

	int lastColumnIndex = res_meta->getColumnCount();
	if (columnToSplitID == lastColumnIndex){
		lastColumnIndex -= 1;
	}

	int rowNumberForID = 1;
	while (res->next()) {
		query = "INSERT INTO " + tableName + "_part1" + " ( " + columnToSplit + "_id , ";
		for (int i = 0; i < res_meta->getColumnCount(); i++){
			if (columnToSplitID == (i + 1)){
				continue;
			}
			if ((i + 1) >= lastColumnIndex){
				query += " " + res_meta->getColumnName(i + 1) + " ) ";
			}
			else{
				query += " " + res_meta->getColumnName(i + 1) + ", ";
			}
		}
		query += " VALUES( " + std::to_string(rowNumberForID) + " , ";
		for (int i = 0; i < res_meta->getColumnCount(); i++){
			if (columnToSplitID == (i + 1)){
				continue;
			}
			if ((i + 1) >= lastColumnIndex){
				query += " '" + res->getString(res_meta->getColumnName(i + 1)) + "' )";
			}else{
				query += " '" + res->getString(res_meta->getColumnName(i + 1)) + "', ";
			}
		}
		//cout << query << endl;
		DebugExecute(con,query);
		DebugExecute(con,"INSERT INTO " + tableName + "_part2" + "(id," + columnToSplit + " ) VALUES(" + std::to_string(rowNumberForID) + ", '" + res->getString(columnToSplit) + "')");
		rowNumberForID++;
	}
	return 0;
}





