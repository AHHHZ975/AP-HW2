#include <iostream>
#include <vector>
#include <string>
#include <fstream>

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
	void parseDatabaseInformation();
	bool isInTheList(vector<string>& aList, string& element);
private:
	vector<string> databaseInformation;
	vector<string> days;	
	vector<int> productsID;
	vector<int> customersID;
	vector<int> customersCount;
	vector<string> differentDays;
	vector<int> productCount;
	
};