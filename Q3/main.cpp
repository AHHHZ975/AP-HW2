#include "SimplifyDatabase.h"

int main(){
	SimplifyDatabase simpleDB;
	simpleDB.readDatabase();
	simpleDB.showDatabaseInformation();
	simpleDB.parseDatabaseInformation();
	simpleDB.makePacket();
	simpleDB.writeNewDatabase();
	simpleDB.showNewDatabaseInformation();
	return 0;
}