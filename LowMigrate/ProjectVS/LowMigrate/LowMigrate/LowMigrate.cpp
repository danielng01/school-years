#include "stdafx.h"
#include "LowMigrate.h"
int main(int argc, char* argv[])
{
	//for (int i = 0; i < argc; i++){
	//	cout << "argv[" << i << "] = " << argv[i] << endl;
	//}
	ArgumentsParser(argc, argv);
}
int TestMySQLConnection(){
	cout << endl;
	cout << "Running 'SELECT 'Hello World!' »AS _message'..." << endl;

	try {
		sql::Connection* con = GetConnection();
		sql::ResultSet* res = ExecuteQuery(con, "SELECT 'Hello World!' AS _message");
		if (res != NULL){
			while (res->next()) {
				cout << "\t... MySQL replies: ";
				/* Access column data by alias or column name */
				cout << res->getString("_message") << endl;
				cout << "\t... MySQL says it again: ";
				/* Access column fata by numeric offset, 1 is the first column */
				cout << res->getString(1) << endl;
			}
		}

		delete res;
		delete con;

	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	cout << endl;

	return EXIT_SUCCESS;
}
sql::ResultSet* ExecuteQuery(sql::Connection *con, string query){
		sql::ResultSet *res = NULL;
		sql::Statement *stmt = con->createStatement();
		res = stmt->executeQuery(query);
		return res;
}

sql::Connection* GetConnection(){
	sql::Driver *driver;
	sql::Connection *con;
	/* Create a connection */
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "root");

	return con;
}
sql::Connection* GetConnection(string host, string username, string password){
	sql::Driver *driver;
	sql::Connection *con;
	/* Create a connection */
	driver = get_driver_instance();
	con = driver->connect(host, username, password);

	return con;
}

