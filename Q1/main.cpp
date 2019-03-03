#include "Map.h"

int main(){
	srand(time(NULL));
	int n;	
	cout << "Please enter the dimension of map: " << endl;
	cin >> n;
	Map map{n};	
	map.showMap();
	map.showRoute();
	return 0;
}