#ifndef SIMPLIFYDATABASE_H
#define SIMPLIFYDATABASE_H

#include "SimplifyDatabase.h"


SimplifyDatabase::SimplifyDatabase(){

}

SimplifyDatabase::~SimplifyDatabase(){

}

void SimplifyDatabase::readDatabase(){	
	this->databaseInformation.clear();
	std::ifstream database;
	string row = "";	
	database.open("db.txt");
	while(getline(database, row)){						
		this->databaseInformation.push_back(row);		
		row.clear();
	}	
	database.close();
}

void SimplifyDatabase::showDBInformation(){
	for(size_t i{}; i != this->databaseInformation.size(); i++){
		cout << this->databaseInformation.at(i) << endl;
	}	
}

void SimplifyDatabase::parseDatabaseInformation(){
	vector<string> seenDays;
	int productCount {};
	int customerCount {};
	seenDays.clear();	
	this->differentDays.clear();
	this->days.clear();
	for(size_t i{0}; i != this->databaseInformation.size(); i++){		
		this->days.push_back(this->databaseInformation.at(i).substr(1,9));
	}

	for(size_t i{}; i != this->days.size(); i++){
		productCount = 0;
		customerCount = 0;
		if(!isInTheList(seenDays, this->days.at(i))){
			seenDays.push_back(this->days.at(i));			
			for(size_t j{i+1}; j != this->days.size(); j++){
				if(this->days.at(i) == this->days.at(j)){
										
				}
			}		
		}		
	}

}
bool SimplifyDatabase::isInTheList(vector<string>& aList, string& element){
	for(size_t i{}; i != aList.size(); i++){
		if(aList.at(i) == element){
			return true;
		}
	}
	return false;
}
#endif