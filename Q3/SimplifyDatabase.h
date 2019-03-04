#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::getline;

class SimplifyDatabase{
public:
	SimplifyDatabase();
	~SimplifyDatabase();
	void readDatabase();
	void showDBInformation();
private:
	vector<string> databaseInformation;

	
};