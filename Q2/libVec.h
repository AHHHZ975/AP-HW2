#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class libVec{
public:
	void createVector();
	void showVector();
	libVec(long long int n);
	~libVec();
private:
	vector<long long int> myVector;
	long long int myVectorSize;
	
};