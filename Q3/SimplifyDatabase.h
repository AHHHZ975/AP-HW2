#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class SimplifyDatabase{
public:
	SimplifyDatabase();
	~SimplifyDatabase();
	void readDatabase();
private:
	vector<string> databaseInformation;

	
};