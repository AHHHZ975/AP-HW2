#ifndef LIBARR_H
#define LIBARR_H


#include "libArr.h"

libArr::libArr(){

}
libArr::~libArr(){
	delete [] this->myArray;
	this->myArray = NULL;
}

void libArr::createArray(int n){
	this->myArraySize = n;
	this->myArray = new int[this->myArraySize];
	for(int i{}; i != this->myArraySize; i++){
		this->myArray[i] = i;
	}
}

void libArr::showArray(){
	for(int i{}; i != this->myArraySize; i++){
		cout << this->myArray[i] << " ";
	}	
	cout << endl;
}
#endif