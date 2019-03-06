#ifndef MAP_H
#define MAP_H

#include "Map.h"

Map::Map(int n){
	vector<int> rowsOfMap;
	this->allRoutes.clear();
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

void Map::findRouteWithoutDiagonalMovement(vector<vector<int>>& mapHeights, pair<int,int>& currentlocation){
	this->route.clear();
	this->sumOfHeights = 0;
	int minDistance = mapHeights.at(0).at(0);
	bool isNextLocationGoal = false;
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
				this->moveDown(currentLocation, isNextLocationGoal);			
			}		
			else{				
				minDistance = rightDistance;				
				this->moveRight(currentLocation, isNextLocationGoal);
			}	
		}
		else if(canMoveRight(currentLocation)){
			minDistance = rightDistance;			
			this->moveRight(currentLocation, isNextLocationGoal);
		}
		else if(canMoveDown(currentLocation)){			
			minDistance = downDistance;
			this->moveDown(currentLocation, isNextLocationGoal);
		}
		this->sumOfHeights += minDistance;
		route.push_back(currentLocation);
	}
}

void Map::findRouteWithDiagonalMovement(vector<vector<int>>& mapHeights, pair<int,int>& currentlocation){
	this->route.clear();
	this->sumOfHeights = 0;
	int minDistance = mapHeights.at(0).at(0);
	bool isNextLocationGoal = false;
	this->route.push_back(make_pair(0,0));	
	int rightDistance{}, downDistance{}, diagonalDistance{};
	while(currentLocation.first != (this->mapDimension-1) || currentLocation.second != (this->mapDimension-1)){		
		if(canMoveRight(currentLocation)){
			rightDistance = abs(mapHeights.at(currentLocation.first).at(currentLocation.second+1)
			 - mapHeights.at(currentLocation.first).at(currentLocation.second));
		}
		if(canMoveDown(currentLocation)){
			downDistance = abs(mapHeights.at(currentLocation.first+1).at(currentLocation.second)
			 - mapHeights.at(currentLocation.first).at(currentLocation.second));
		}
		if(canMoveDiagonal(currentLocation)){
			diagonalDistance = abs(mapHeights.at(currentLocation.first+1).at(currentLocation.second+1)
			 - mapHeights.at(currentLocation.first).at(currentLocation.second));	
		}
		if(canMoveDiagonal(currentLocation)){
			minDistance = std::min({downDistance, rightDistance, diagonalDistance});			
			if(minDistance == downDistance){				
				this->moveDown(currentLocation, isNextLocationGoal);			
			}		
			else if(minDistance == rightDistance){										
				this->moveRight(currentLocation, isNextLocationGoal);
			}
			else if(minDistance == diagonalDistance){				
				this->moveDiagonal(currentLocation, isNextLocationGoal);
			}
		}
		else if(canMoveRight(currentLocation)){
			minDistance = rightDistance;			
			this->moveRight(currentLocation, isNextLocationGoal);
		}
		else if(canMoveDown(currentLocation)){			
			minDistance = downDistance;
			this->moveDown(currentLocation, isNextLocationGoal);
		}		
		this->sumOfHeights += minDistance;
		route.push_back(currentLocation);
	}
}
void Map::findRoute(vector<vector<int>>& mapHeights, pair<int,int>& currentlocation, bool hasDiagonalMovement){
	return hasDiagonalMovement ? findRouteWithDiagonalMovement(mapHeights,currentLocation) : findRouteWithoutDiagonalMovement(mapHeights,currentLocation);
}


void Map::findAllRoutes(int currentRow, int currentColumn, vector<int> aRoute){  			
	//////// When we reached at the right of the map /////////////
	if(currentRow == this->mapDimension - 1){			
			for (int i = currentColumn; i < this->mapDimension; i++) {				
				aRoute.push_back(mapHeights.at(currentRow).at(i));
			}
			this->allRoutes.push_back(aRoute);
			return;
	}
	//////// When we reached at the bottom of the map /////////////
	else if(currentColumn == this->mapDimension - 1){		
		for (int i = currentRow; i < this->mapDimension; i++) {			
			aRoute.push_back(mapHeights.at(i).at(currentColumn));
		}
		this->allRoutes.push_back(aRoute);
		return;
	}	
	aRoute.push_back(mapHeights.at(currentRow).at(currentColumn));
	findAllRoutes(currentRow + 1, currentColumn, aRoute); // For down movement
	findAllRoutes(currentRow, currentColumn + 1, aRoute); // For right movement
	//findAllRoutes(currentRow + 1, currentColumn + 1, path); // For diagonal movement
}
void Map::findMinimumRoute(){
	this->routesHeight.clear();
	this->sumOfHeights = 0;
	pair<int, int> minValue;	
	for(size_t i{}; i != this->allRoutes.size(); i++){
		for(size_t j{}; j != this->allRoutes.at(i).size(); j++){
			if(j != this->allRoutes.at(i).size() - 1){
				this->sumOfHeights += abs(this->allRoutes.at(i).at(j) - this->allRoutes.at(i).at(j+1));
			}			
		}
		this->routesHeight.push_back(make_pair(this->sumOfHeights,i));
		sumOfHeights = 0;
	}
	minValue = this->routesHeight.at(0);
	for(size_t i{}; i != this->routesHeight.size(); i++){
		for(size_t j{i+1}; j != this->routesHeight.size(); j++){
			if(this->routesHeight.at(j).first < minValue.first){
				minValue = this->routesHeight.at(j);
			}
		}
	}


	for(size_t i{}; i != this->allRoutes.at(minValue.second).size(); i++){
		cout << this->allRoutes.at(minValue.second).at(i) << " ";		
	}
	cout << endl;
	cout << "The minimum distance is: " << minValue.first << endl;
}	
void Map::showAllRoutes(){	
	for(size_t i{}; i != this->allRoutes.size(); i++){
		for(size_t j{}; j != this->allRoutes.at(i).size(); j++){
			cout << this->allRoutes.at(i).at(j) << " ";
		}
		cout << endl;
	}
}
void Map::showRoute(bool hasDiagonalMovement){
	this->currentLocation = make_pair(0,0);
	this->findRoute(this->mapHeights, this->currentLocation, hasDiagonalMovement);
	vector<vector<char>> route;	
	route.clear();
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
bool Map::canMoveRight(pair<int,int>& currentlocation){
	return currentLocation.second < (this->mapDimension - 1);
}
bool Map::canMoveDiagonal(pair<int,int>& currentLocation){
	return currentLocation.second < (this->mapDimension - 1) &&
		   currentLocation.first < (this->mapDimension - 1);	
}
bool Map::isGoal(pair<int,int>& location){
	return (location.first == this->mapDimension-1) &&
		   (location.second == this->mapDimension-1);
}
void Map::moveDown(pair<int,int>& currentLocation, bool& isNextLocationGoal){
	currentLocation.first += 1;
	if(this->isGoal(currentLocation)){
		isNextLocationGoal = true;
	}
}
void Map::moveDiagonal(pair<int,int>& currentLocation, bool& isNextLocationGoal){
	currentLocation.first += 1;	
	currentLocation.second += 1;
	if(this->isGoal(currentLocation)){
		isNextLocationGoal = true;
	}
}
void Map::moveRight(pair<int,int>& currentlocation, bool& isNextLocationGoal){
	currentLocation.second += 1;
	if(this->isGoal(currentLocation)){
		isNextLocationGoal = true;
	}
}

Map::~Map(){

}


#endif