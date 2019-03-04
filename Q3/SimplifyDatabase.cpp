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
	while(std::getline(database, row)){		
		//database >> row;		
		this->databaseInformation.push_back(row);
	}
	database.close();
}

void SimplifyDatabase::showDBInformation(){
	for(size_t i{}; i != this->databaseInformation.size(); i++){
		cout << this->databaseInformation.at(i) << endl;
	}
}
#endif