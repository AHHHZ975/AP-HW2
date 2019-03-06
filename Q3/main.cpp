#include "SimplifyDatabase.h"

int main(){
	SimplifyDatabase simpleDB;
	simpleDB.readDatabase();
	simpleDB.showDBInformation();
	simpleDB.parseDatabaseInformation();
	return 0;
}