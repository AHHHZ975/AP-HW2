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
	this->sumOfHeights = 0;
	int minDistance = mapHeights.at(0).at(0);
	this->route.push_back(make_pair(0,0));
	int rightDistance{}, downDistance{};
	while(currentLocation.first != (this->mapDimension-1) || currentLocation.second != (this->mapDimension-1)){		
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
		this->sumOfHeights += minDistance;
		route.push_back(currentLocation);
	}
	
}
void Map::showRoute(){
	this->findRoute(this->mapHeights, this->currentLocation);
	vector<vector<char>> route;	
	vector<char> rowsOfRoute;
	///////////////////// Make graphical map ////////////////////
	for(int i {0}; i != this->mapDimension; i++){
		rowsOfRoute.clear();
		for(int j {0}; j != this->mapDimension; j++){
			rowsOfRoute.push_back('-');
		}
		route.push_back(rowsOfRoute);
	}
	for(size_t i {0}; i != this->route.size(); i++){
		route.at(this->route.at(i).first).at(this->route.at(i).second) = '*';
	}
	cout << " Distance: " << this->sumOfHeights << endl;
	////////////////// Show graphical map /////////////////////
	for(int i {0}; i != this->mapDimension; i++){
		for(int j {0}; j != this->mapDimension; j++){
			cout << setfill(' ') << setw(3) << route.at(i).at(j);
		}
		cout << endl;		
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