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

void SimplifyDatabase::showDatabaseInformation(){
	cout << "////////////// The input  database is: ////////////////" << endl;
	for(size_t i{}; i != this->databaseInformation.size(); i++){
		cout << this->databaseInformation.at(i) << endl;
	}	
}

void SimplifyDatabase::showNewDatabaseInformation(){
	cout << "////////////// The ouput  database is: ////////////////" << endl;
	for(size_t i{}; i != this->databaseNewInformation.size(); i++){
		cout << this->databaseNewInformation.at(i);
	}	
}

void SimplifyDatabase::parseDatabaseInformation(){		
	vector<pair<int,int>> differentProducts;
	vector<pair<int,int>> differentCustomers;
	vector<int> sameDaysIndex;
	int index{};	
	int counter {};
	sameDaysIndex.clear();
	differentProducts.clear();
	differentCustomers.clear();
	this->differentDays.clear();
	this->days.clear();
	this->productCount.clear();
	this->customerCount.clear();
	//////////////// Get the date && products_id && cutomers_id from database ///////////
	for(size_t i{0}; i != this->databaseInformation.size(); i++){		
		this->days.push_back(this->databaseInformation.at(i).substr(1,9));
		this->customersID.push_back(std::stoi(this->databaseInformation.at(i).substr(18,3)));
		this->productsID.push_back(std::stoi(this->databaseInformation.at(i).substr(22,4)));
	}
	///////////////////// Different dates in database ///////////
	for(size_t i{}; i != this->days.size(); i++){
		for(size_t j{i+1}; j != this->days.size(); j++){
			if(!this->isInTheList(this->differentDays, this->days.at(j), index)){
				this->differentDays.push_back(this->days.at(j));										
			}
		}		
	}
	///////////////// Detect && categorize the same dates ////////
	for(size_t i{}; i != this->days.size(); i++){
		if(this->isInTheList(this->differentDays, this->days.at(i), index)){
			sameDaysIndex.push_back(index);			
		}
	}	
	/////////////// Different products && cutomers in same days /////////////
	for(size_t i{}; i != this->customersID.size(); i++){
		for(size_t j{}; j != sameDaysIndex.size(); j++){
			if(sameDaysIndex.at(j) == int(i)){
				if(!this->isInTheList(differentProducts, std::make_pair(this->productsID.at(j),i), index)){
					differentProducts.push_back(std::make_pair(this->productsID.at(j), i));
				}
				if(!this->isInTheList(differentCustomers, std::make_pair(this->customersID.at(j),i), index)){
					differentCustomers.push_back(std::make_pair(this->customersID.at(j), i));
				}
			}
		}		
	}
	///////////////////////////////////		
	for(size_t i{}; i != differentDays.size(); i++){
		counter = 0;
		for(size_t j{}; j != differentCustomers.size(); j++){
			if(differentCustomers.at(j).second == int(i)){
				counter++;
			}
		}
		this->customerCount.push_back(counter);
	}	
	for(size_t i{}; i != this->differentDays.size(); i++){
		counter = 0;
		for(size_t j{}; j != differentProducts.size(); j++){
			if(differentProducts.at(j).second == int(i)){
				counter++;
			}
		}
		this->productCount.push_back(counter);
	}	
	///////////////////////////
	
}

void SimplifyDatabase::makePacket(){
	this->databaseNewInformation.clear();	 
	 for(size_t i{}; i != this->differentDays.size(); i++){
	 	this->databaseNewInformation.push_back("[" + this->differentDays.at(i) + "] "  + std::to_string(this->customerCount.at(i)) + " " + std::to_string(this->productCount.at(i)));
		this->databaseNewInformation.push_back("\n");
	 }	 	 
}

void SimplifyDatabase::writeNewDatabase(){
	std::ofstream dbNew;
	dbNew.open("dbnew.txt");	
	for(size_t i{}; i != this->databaseNewInformation.size(); i++){
 		 dbNew << this->databaseNewInformation.at(i);
 	}	    	   
    dbNew.close();  	
}
bool SimplifyDatabase::isInTheList(vector<string>& aList, string& element, int& index){
	for(size_t i{}; i != aList.size(); i++){
		if(aList.at(i) == element){
			index = i;
			return true;
		}
	}
	return false;
}
bool SimplifyDatabase::isInTheList(vector<pair<int,int>>& aList, pair<int,int> element, int& index){
	for(size_t i{}; i != aList.size(); i++){
		if(aList.at(i).second == element.second){
			if(aList.at(i).first == element.first){
				index = i;
				return true;
			}			
		}
	}
	return false;
}

#endif