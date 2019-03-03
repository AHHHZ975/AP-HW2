#include "Map.h"

Map::Map(int n){
	this->mapDimension = n;
	this->mapArea = n*n;
	///////////////////// Create the map ////////////////
	mapHeights.clear();
	for(int i {0}; i != this->mapArea; i++){
		mapHeights.push_back(rand() % 100);
	}
}
Map::~Map(){

}
void Map::showMap(){
	for(int i {0}; i != this->mapArea; i++){
		cout << setfill(' ') << setw(3) << mapHeights.at(i);		
		if((i+1) % this->mapDimension == 0){
			cout << endl;
		}
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
