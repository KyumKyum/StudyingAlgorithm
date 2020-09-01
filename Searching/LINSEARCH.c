/*
 * Linear Search Code In C
  */

#include <stdio.h>
#include <stdlib.h>

#define BASE(i) ((char*)base + (i)*width) //Locating cur index

typedef int (*FCMP) (const void*, const void*); // FCMP function pointer - Compare two records size & return the result

//Search
int lv_search(void *key, void *base, size_t *num, size_t width, FCMP fcmp){
	int i = 0;
	while (fcmp(BASE(i),key) != 0 && i < *num) i++; //Sequential Search
	
	return ( i < *num ? i : -1); //Return index if the value is found.
}

int lv_insert(void *key, void *base, size_t *num, size_t width, FCMP fcmp){
	memcpy(BASE((*num)++), key, width); //Insert & Increase num
	return *num - 1; //Return index
}

int lv_delete(void *key, void *base, size_t *num, size_t width, FCMP fcmp){
	int pos, i;

	if(*num > 0) { // Check whether there is element to check
		if((pos = lv_search(key,base,num,width,fcmp)) < 0) return -1; // return -1 if target key isn't found

		for(i = pos + 1; i < *num; i++) memcpy(BASE(i-1), BASE(i), width); //Filling empty space

		(*num)--; //Reduce #element
		return pos; //Return position
	}
	return -1;
}

int lfv_search(void *key, void *base, size_t *num, size_t width, FCMP fcmp){
	int i = 0, j;
	void *v;

	while(fcmp(BASE(i), key) != 0, i < *num) i++; // Sequential Search
	
	if(i >= *num) return -1;

	v = malloc(width);
	memcpy(v, BASE(i), width); //Copy the target value to v
	
	for(j = i-1; j >= 0; j--) memcpy(BASE(j+1),BASE(j),width); // Making a space on the front.

	memcpy(base, v, width); //Move to the front
	return 0;
}
