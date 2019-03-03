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
	this->route.clear();
	int minDistance = mapHeights.at(0).at(0);
	this->route.push_back(make_pair(0,0));
	int rightDistance{}, downDistance{};
	while(currentLocation.first != (this->mapDimension-1) && currentLocation.second != (this->mapDimension-1)){		
		if(canMoveRight(currentLocation)){
			rightDistance = abs(mapHeights.at(currentLocation.first).at(currentLocation.second+1)
			 - mapHeights.at(currentLocation.first).at(currentLocation.second));
		}
		if(canMoveDown(currentLocation)){
			downDistance = abs(mapHeights.at(currentLocation.first+1).at(currentLocation.second)
			 - mapHeights.at(currentLocation.first).at(currentLocation.second));
		}
		if(canMoveRight(currentLocation) && canMoveDown(currentLocation)){
			if(downDistance < rightDistance){
				minDistance = downDistance;
				this->moveDown(currentLocation);			
			}		
			else{				
				minDistance = rightDistance;
				this->moveRight(currentLocation);
			}	
		}
		else if(canMoveRight(currentLocation)){
			minDistance = rightDistance;
			this->moveRight(currentLocation);
		}
		else if(canMoveDown(currentLocation)){
			minDistance = downDistance;
			this->moveDown(currentLocation);
		}
		
		route.push_back(currentLocation);
	}	
	route.push_back(make_pair(this->mapDimension-1, this->mapDimension-1));
	
}
void Map::showRoute(){
	this->findRoute(this->mapHeights, this->currentLocation);
	for(size_t i {0}; i != this->route.size(); i++){
		cout << this->route.at(i).first << " " << this->route.at(i).second << endl;
	}
}
bool Map::canMoveDown(pair<int,int>& currentlocation){
	return currentLocation.first < (this->mapDimension - 1);
}	
bool Map::canMoveRight(pair<int,int>& location){
	return currentLocation.second < (this->mapDimension - 1);
}
void Map::moveDown(pair<int,int>& currentLocation){
	currentLocation.first += 1;
}
void Map::moveRight(pair<int,int>& currentlocation){
	currentLocation.second += 1;
}

Map::~Map(){

}


#endif