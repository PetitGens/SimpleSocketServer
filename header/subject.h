#ifndef __SUBJECT_H__
#define __SUBJECT_H__

typedef struct {
	unsigned int type;
	char* name;
	double average;
} Subject;

/**
 * Returns the average mark of the subject of the specified type
 * @param type the type of the study (integer)
 * @param subject an array containing all the subjects
 * @param size the size of the array
 * @return the average of the subject
*/
double getAverage(unsigned int type, Subject subject[], int size);

#endif //__SUBJECT_H__

