#ifndef __SUBJECT_H__
#define __SUBJECT_H__

typedef struct {
	int number;
	char* name;
	double average;
} Subject;

double getAverage(char* name, Subject subject[], int size);

#endif //__SUBJECT_H__