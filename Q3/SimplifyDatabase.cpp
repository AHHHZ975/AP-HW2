#ifndef SIMPLIFYDATABASE_H
#define SIMPLIFYDATABASE_H

#include <fstream>
#include "SimplifyDatabase.h"
SimplifyDatabase::SimplifyDatabase(){

}

SimplifyDatabase::~SimplifyDatabase(){

}

void SimplifyDatabase::readDatabase(){	
	std::ifstream database;
	string row;
	database.open("db.txt");
	while(!database.eof()){
		database >> row;
		//fileElements.push_back(row);
	}
	database.close();
}

#endif