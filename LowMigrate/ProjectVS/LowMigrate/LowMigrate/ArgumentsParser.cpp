#include "stdafx.h"
#include "LowMigrate.h"

void ArgumentsParser(int argc, char* argv[]){




	bool isLoginDefault = true;
	bool loginSet = false;
	string hostname = "tcp://127.0.0.1:3306";
	string username = "root";
	string password = "root";
	string query = "SELECT 'Hello World!' AS _message";
	sql::Connection* con = GetConnection();
	con->setSchema("test");
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "-host")){
			hostname = argv[++i];
			isLoginDefault = false;
		}
		if (!strcmp(argv[i], "-user")){
			username = argv[++i];
			isLoginDefault = false;
		}
		if (!strcmp(argv[i], "-pass")){
			password = argv[++i];
			isLoginDefault = false;
		}
		if (!strcmp(argv[i], "-query")){
			query = std::string(argv[++i]);
		}
		if ((isLoginDefault == false) && (loginSet == false)){
			sql::Connection* con = GetConnection(hostname, username, password);
			con->setSchema("test");
			loginSet = true;
		}
		if (!strcmp(argv[i], "-CreateTable")){

			if (isLoginDefault){
				sql::Connection* con = GetConnection();
				con->setSchema("test");
				int numberOfColumns = 0;
				string * columsNames = new string[argc];
				for (int j = i + 1; j < argc; j++){
					columsNames[numberOfColumns] = argv[j];
					numberOfColumns++;
				}
				CreateTable(con, columsNames, numberOfColumns);
			}
			else{
				sql::Connection* con = GetConnection(hostname, username, password);
				con->setSchema("test");
				int numberOfColumns = 0;
				string * columsNames = new string[argc];
				for (int j = i + 1; j < argc; j++){
					columsNames[numberOfColumns] = argv[j];
					numberOfColumns++;
				}
				CreateTable(con, columsNames, numberOfColumns);
			}
			//return 0;
			//query = argv[++i];
		}
		if (!strcmp(argv[i], "-SplitMigrate")){

			if (isLoginDefault){
				sql::Connection* con = GetConnection();
				con->setSchema("test");
				//CreateTable(con,argv[i + 1], argv[i + 2], argv[i + 3]);
				//CreateTable(con, "daniel", "", "","","");
				SplitMigrate(con, argv[i + 1], argv[i + 2]);
			}
			else{
				sql::Connection* con = GetConnection(hostname, username, password);
				con->setSchema("test");
				SplitMigrate(con, argv[i + 1], argv[i + 2]);
			}
			//query = argv[++i];
		}
		if (!strcmp(argv[i], "-CombineMigrate")){

			if (isLoginDefault){
				sql::Connection* con = GetConnection();
				con->setSchema("test");
				//CreateTable(con,argv[i + 1], argv[i + 2], argv[i + 3]);
				//CreateTable(con, "daniel", "", "","","");
				CombineMigrate(con, argv[i + 1], argv[i + 2], argv[i + 3], argv[i + 4], argv[i + 5], argv[i + 6]);
			}
			else{
				sql::Connection* con = GetConnection(hostname, username, password);
				con->setSchema("test");
				CombineMigrate(con, argv[i + 1], argv[i + 2], argv[i + 3], argv[i + 4], argv[i + 5], argv[i + 6]);
			}
			//query = argv[++i];
		}
		if (!strcmp(argv[i], "-AddColumn")){

			if (isLoginDefault){
				sql::Connection* con = GetConnection();
				con->setSchema("test");
				AddColumn(con, argv[i + 1], argv[i + 2], argv[i + 3]);
			}
			else{
				sql::Connection* con = GetConnection(hostname, username, password);
				con->setSchema("test");
				AddColumn(con, argv[i + 1], argv[i + 2], argv[i + 3]);
			}
		}
		if (!strcmp(argv[i], "-OneToMany")){

			if (isLoginDefault){
				sql::Connection* con = GetConnection();
				con->setSchema("test");
				OneToMany(con, argv[i + 1], argv[i + 2]);
			}
			else{
				sql::Connection* con = GetConnection(hostname, username, password);
				con->setSchema("test");
				OneToMany(con, argv[i + 1], argv[i + 2]);
			}
		}
		if (!strcmp(argv[i], "-ManyToMany")){

			if (isLoginDefault){
				sql::Connection* con = GetConnection();
				con->setSchema("test");
				ManyToMany(con, argv[i + 1], argv[i + 2]);
			}
			else{
				sql::Connection* con = GetConnection(hostname, username, password);
				con->setSchema("test");
				ManyToMany(con, argv[i + 1], argv[i + 2]);
			}
		}
	}





}