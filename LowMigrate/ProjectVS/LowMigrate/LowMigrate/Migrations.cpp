#include "stdafx.h"

#include "LowMigrate.h"






//---------------------------------------------------------------------------------------------
int CombineMigrate(sql::Connection *con, string tableName1, string tableName2, string combineColumn1, string combineColumn2, string combineColumn1Type, string combineColumn2Type){
	sql::ResultSet* res;
	sql::ResultSet* res2;
	sql::Statement *stmt = con->createStatement();
	stmt->execute("DROP TABLE IF EXISTS combineTable");

	res = stmt->executeQuery("SELECT * FROM " + tableName1);
	ResultSetMetaData *res_meta;
	res_meta = res->getMetaData();


	string query = "CREATE TABLE combineTable (";
	for (int i = 0; i < res_meta->getColumnCount(); i++){
		if (combineColumn1.compare(res_meta->getColumnName(i + 1)) == 0){
			if ((i + 1) >= res_meta->getColumnCount()){
				query += " " + combineColumn2 + " ";
				query += " " + combineColumn2Type + ") ";
			}
			else{
				query += " " + combineColumn2 + " ";
				query += " " + combineColumn2Type + ", ";
			}
			continue;
		}
		if ((i + 1) >= res_meta->getColumnCount()){
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
	cout << query << endl;
	stmt->execute(query);

	res = stmt->executeQuery("SELECT * FROM " + tableName1);
	res_meta = res->getMetaData();
	res2 = stmt->executeQuery("SELECT * FROM " + tableName2);
	int rowNumberForID = 1;
	while (res->next() && res2->next()) {
		//cout << "\tINSERTING: ";
		/* Access column data by alias or column name */


		query = "INSERT INTO combineTable ( ";


		for (int i = 0; i < res_meta->getColumnCount(); i++){
			if (combineColumn1.compare(res_meta->getColumnName(i + 1)) == 0){
				if ((i + 1) >= res_meta->getColumnCount()){
					query += " " + combineColumn2 + ") ";
					//query += " " + combineColumn2Type + ") ";
				}
				else{
					query += " " + combineColumn2 + ", ";
					//query += " " + combineColumn2Type + ", ";
				}
				continue;
			}
			if ((i + 1) >= res_meta->getColumnCount()){
				query += " " + res_meta->getColumnName(i + 1) + " ) ";
			}
			else{
				query += " " + res_meta->getColumnName(i + 1) + ", ";
			}


		}

		query += " VALUES( ";


		for (int i = 0; i < res_meta->getColumnCount(); i++){
			if ((combineColumn1).compare(res_meta->getColumnName(i + 1)) == 0){
				//query += " '" + std::to_string(rowNumberForID) + "', ";
				if ((i + 1) >= res_meta->getColumnCount()){

					query += " '" + res2->getString(combineColumn2) + "' )";

				}
				else{
					query += " '" + res2->getString(combineColumn2) + "', ";
				}
				continue;
			}
			if ((i + 1) >= res_meta->getColumnCount()){

				query += " '" + res->getString(res_meta->getColumnName(i + 1)) + "' )";

			}
			else{
				query += " '" + res->getString(res_meta->getColumnName(i + 1)) + "', ";

			}


		}
		cout << query << endl;
		stmt->execute(query);
	}
	return 0;
} 