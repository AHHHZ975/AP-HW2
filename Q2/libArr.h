#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;


class libArr{
public:
	void createArray();
	void showArray();
	libArr(long long int n);
	~libArr();
private:
	long long int* myArray = NULL;
	long long int myArraySize;
};