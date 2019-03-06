#include "Map.h"

int main(){
	srand(time(NULL));
	int n;		
	vector<int> aRoute;
	cout << "Please enter the dimension of map: " << endl;
	cin >> n;
	Map map{n};	
	///////////////////////// Produce random map /////////////////////
	cout << "The random map is: " << endl;
	map.showMap();
	cout << endl;
	////////////////////// A) Without diagonal movement ////////////////
	cout << "The path with right && down movement:" << endl;
	map.showRoute(0);
	cout << endl;
	////////////////////// B) With diagonal movement ////////////////
	cout << "The path with right && down && diagonal movement:" << endl;
	map.showRoute(1);
	cout << endl;
	///////////////////// C) Minimum route ////////////////////
	map.findAllRoutes(0,0, aRoute);
	cout << "All paths are: " << endl;
	map.showAllRoutes();
	cout << endl;
	cout << "The minimum path is:(With right && down movement) " << endl;
	map.findMinimumRoute();
	return 0;
}