#include "Map.h"

Map::Map(int n){
	vector<int> rowsOfMap;
	this->mapDimension = n;
	this->mapArea = n*n;
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
Map::~Map(){

}
void Map::showMap(){	
	for(int i {0}; i != this->mapDimension; i++){
		for(int j {0}; j != this->mapDimension; j++){
			cout << setfill(' ') << setw(3) << mapHeights.at(i).at(j);
		}
		cout << endl;		
	}	
}
void Map::findRoute(){

}
void Map::showRoute(){
	
}
void Map::moveRight(){

}
void Map::moveDown(){

}
