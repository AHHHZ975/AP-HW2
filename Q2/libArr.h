#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;


class libArr{
public:
	void createArray(int n);
	void showArray();
	libArr();
	~libArr();
private:
	int* myArray = NULL;
	int myArraySize;
};