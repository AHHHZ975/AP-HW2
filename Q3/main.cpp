#include "SimplifyDatabase.h"

int main(){
	SimplifyDatabase simpleDB;
	simpleDB.readDatabase();
	simpleDB.showDBInformation();
	simpleDB.parseDatabaseInformation();
	simpleDB.makePacket();
	simpleDB.writeNewDatabase();
	return 0;
}