
// LowMigrate.cpp : Defines the entry point for the console application.
//
//#include "Migrations.cpp"



/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>
/*
Include directly the different
headers from cppconn/ and mysql_driver.h + mysql_util.h
(and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;
using namespace sql;

int TestMySQLConnection();
sql::ResultSet* ExecuteQuery(sql::Connection *con, string query);
sql::Connection* GetConnection();
sql::Connection* GetConnection(string host, string username, string password);
int CreateTable(sql::Connection *con, string * columsNames, int numberOfColumns);
int SplitMigrate(sql::Connection *con, string tableName, string columnToSplit);
int CombineMigrate(sql::Connection *con, string tableName1, string tableName2, string combineColumn1, string combineColumn2, string combineColumn1Type, string combineColumn2Type);
void ArgumentsParser(int argc, char* argv[]);
void DebugExecute(sql::Connection *con, string query);
int SplitMigrateGetColumnToSplitID(sql::Connection *con, string tableName, string columnToSplit);

string GetSplitMigrationCreateLeftTableQuery(sql::Connection *con, string tableName, string columnToSplit);
string GetSplitMigrationCreateRightTableQuery(sql::Connection *con, string tableName, string columnToSplit);
void AddColumn(sql::Connection *con, string tableName, string newColumnName, string columnType);
void AddColumn(sql::Connection *con, string tableName, string newColumnName);

void OneToMany(sql::Connection *con, string tableName1, string tableName2);
void ManyToMany(sql::Connection *con, string tableName1, string tableName2);