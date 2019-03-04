#include "libArr.h"
#include "libVec.h"


typedef void (libVec::*pointerToCreateVector) (int);
typedef void (libArr::*pointerToCreateArray) (int);
int main(){
	// ////////////////////// Vector //////////////////////////
	// myVector.createVector(10);
	// myVector.showVector();
	// /////////////////////// Dynamic array ////////////////
	// myArray.createArray(10);
	// myArray.showArray();
	// //////////////////////////
	pointerToCreateVector pointerToVectorFunction = &libVec::createVector;
	pointerToCreateArray pointerToArrayFunction = &libArr::createArray;
	libVec myVector;
	libArr myArray;
	(myVector.*pointerToVectorFunction)(30);	
	return 0;
}