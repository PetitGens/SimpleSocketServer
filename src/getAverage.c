#include "header/subject.h"

double getAverage(char* name, Subject subject[], int taille){
	for(int i = 0; i < taille; i++){
		if(subject[i].name == name)
			return subject[i].average;
	}
	return -1;
}