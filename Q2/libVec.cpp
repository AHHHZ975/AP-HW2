#ifndef LIBVEC_H
#define LIBVEC_H

#include "libVec.h"

libVec::libVec(){

}

void libVec::createVector(int n){		
	for(int i{}; i != n; i++){
		this->myVector.push_back(i);		
	}	
}

void libVec::showVector(){
	for(size_t i{}; i != this->myVector.size(); i++){
		cout << this->myVector.at(i) << " ";
	}
	cout << endl;
}


libVec::~libVec(){

}

#endif