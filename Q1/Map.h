#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::pair;
using std::setfill;
using std::setw;
using std::make_pair;

class Map{
public:
	Map(int n);
	~Map();
	void showMap();
	void findRoute(vector<vector<int>>& mapHeights, pair<int,int>& currentlocation);
	void showRoute();
	void moveRight(pair<int,int>& currentLocation);
	void moveDown(pair<int,int>& currentLocation);
	bool canMoveRight(pair<int,int>& currentLocation);	
	bool canMoveDown(pair<int,int>& currentLocation);
private:	
	int mapDimension;
	pair<int,int> currentLocation;
	vector<vector<int>> mapHeights;
	
};