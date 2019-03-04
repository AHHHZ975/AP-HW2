#include "libArr.h"
#include "libVec.h"
#include <chrono>
#include <utility>

using std::cin;

template <typename object, typename function>
void getPointerFunction(object obj, function func){
    return (obj.*func)();
}


template<typename object, typename function>
double functionTime(object obj, function func){
    auto start = std::chrono::high_resolution_clock::now();
    (obj.*func)();
    auto stop = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
}


int main(){
	long long int n = 1000000;
	cout << "Please enter the n: ";
	cin >> 	n;
	libVec myVector{n};
	libArr myArray{n};
	cout << "The time of Vector is: ";		
	cout << functionTime(myVector, &libVec::createVector) << "ms" << endl;
	cout << "The time of Array is: ";		
	cout << functionTime(myArray, &libArr::createArray) << "ms" << endl;
	return 0;
}