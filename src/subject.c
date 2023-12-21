#include "../header/subject.h"

double getAverage(unsigned int type, Subject subject[], int size){
	for(int i = 0; i < size; i++){
		if(subject[i].type == type)
			return subject[i].average;
	}
	return -1;
}

