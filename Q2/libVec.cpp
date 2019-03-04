#ifndef LIBVEC_H
#define LIBVEC_H

#include "libVec.h"

libVec::libVec(long long int n){	
	this->myVectorSize = n;
}

void libVec::createVector(){		
	for(long long int i{}; i != this->myVectorSize; i++){		
		this->myVector.push_back(i);		
	}	
}

void libVec::showVector(){
	for(long long int i{}; i != this->myVectorSize; i++){
		cout << this->myVector.at(i) << " ";
	}
	cout << endl;
}


libVec::~libVec(){

}

#endif