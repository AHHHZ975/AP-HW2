#ifndef MAP_H
#define MAP_H

#include "Map.h"

Map::Map(int n){
	vector<int> rowsOfMap;
	this->mapDimension = n;
	this->currentLocation = make_pair(0,0);
	///////////////////// Create the map ////////////////	
	mapHeights.clear();		
	for(int i {0}; i != this->mapDimension; i++){
		rowsOfMap.clear();
		for(int j {0}; j != this->mapDimension; j++){
			rowsOfMap.push_back(rand() % 100);
		}
		mapHeights.push_back(rowsOfMap);
	}
}

void Map::showMap(){
	for(int i {0}; i != this->mapDimension; i++){
		for(int j {0}; j != this->mapDimension; j++){
			cout << setfill(' ') << setw(3) << mapHeights.at(i).at(j);
		}
		cout << endl;		
	}	
}

void Map::findRoute(vector<vector<int>>& mapHeights, pair<int,int>& currentlocation){
	//if(canMoveRight())
}
void Map::showRoute(){
	
}
bool Map::canMoveRight(pair<int,int>& currentlocation){
	return currentLocation.first < this->mapDimension;
}	
bool Map::canMoveDown(pair<int,int>& location){
	return currentLocation.second < this->mapDimension;
}
void Map::moveRight(pair<int,int>& currentLocation){
	currentLocation.first += 1;
}
void Map::moveDown(pair<int,int>& currentlocation){
	currentLocation.second += 1;
}

Map::~Map(){

}


#endif