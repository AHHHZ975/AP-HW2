#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::pair;

class SimplifyDatabase{
public:
	SimplifyDatabase();
	~SimplifyDatabase();
	void readDatabase();
	void showDBInformation();
	void parseDatabaseInformation();
	void writeNewDatabase();
	bool isInTheList(vector<string>& aList, string& element, int& index);
	bool isInTheList(vector<pair<int,int>>& aList, pair<int,int> element, int& index);
	void makePacket();
private:
	vector<string> databaseNewInformation;
	vector<string> databaseInformation;
	vector<string> days;
	vector<string> differentDays;	
	vector<int> productsID;
	vector<int> customersID;
	vector<int> customerCount;	
	vector<int> productCount;
	
};