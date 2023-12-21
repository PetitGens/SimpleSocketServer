#include "../header/subject.h"

double getAverage(char* name, Subject subject[], int size){
	for(int i = 0; i < size; i++){
		if(subject[i].name == name)
			return subject[i].average;
	}
	return -1;
}