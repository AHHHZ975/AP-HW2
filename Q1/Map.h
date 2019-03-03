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

class Map{
public:
	Map(int n);
	~Map();
	void showMap();
	void findRoute();
	void showRoute();
	void moveRight();
	void moveDown();
private:
	int mapArea;
	int mapDimension;
	vector<int> mapHeights;
	
};