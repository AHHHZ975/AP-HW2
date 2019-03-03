#include "Map.h"

int main(){
	srand(time(NULL));
	int n;	
	cout << "Please enter the dimension of map: " << endl;
	cin >> n;
	Map map{n};	
	map.showMap();
	////////////////////// Without diagonal movement ////////////////
	map.showRoute(0);
	////////////////////// With diagonal movement ////////////////
	map.showRoute(1);
	return 0;
}