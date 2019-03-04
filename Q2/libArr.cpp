#ifndef LIBARR_H
#define LIBARR_H


#include "libArr.h"

libArr::libArr(long long int n){
	this->myArraySize = n;
}
libArr::~libArr(){
	delete [] this->myArray;
	this->myArray = NULL;
}

void libArr::createArray(){	
	this->myArray = new long long int[this->myArraySize];
	for(long long int i{}; i != this->myArraySize; i++){
		this->myArray[i] = i;
	}
}

void libArr::showArray(){
	for(long long int i{}; i != this->myArraySize; i++){
		cout << this->myArray[i] << " ";
	}	
	cout << endl;
}
#endif