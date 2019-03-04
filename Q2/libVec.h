#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class libVec{
public:
	void createVector(int n);
	void showVector();
	libVec();
	~libVec();
private:
	vector<int> myVector;
	
};