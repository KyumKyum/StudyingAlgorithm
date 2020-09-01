//Linear(Sequential) Search

#include <stdio.h>

#define MAX 20

//Search
int li_search (int key. int a[], int *num){ //num == size of the array --> give unity with other functions.
	int i = 0;
	while (a[i] != key && i < *num) i++; //Searching Key
	return (i < *num ? i : -1); //Searched: return index
}

//Self Organizing Search - send the target to the front of the array
inr lfi_search(int key, int a[], int *num){
	int pos, i;
	if((pos = li_search(key, a, num)) < 0) return -1; //Return -1 if there is not such an element.
	for(i = pos-1; i >= 0; i--) a[i+1] = a[i]; //Self-Organizing: Making space for the first element
	a[0] = key; //Set the key to the front
	return 0; //Return target position (First)
}

//Insert - Must check whether items are not exceeding maximum.
int li_insert (int key, int a[]. int *num){ //inserting at rear of the array
	a[(*num)++] = key;
	return *num - 1; //Return inserted index
} 

//Delete
int li_delete(int key, int a[], int *num){
	int pos, i;

	if(*num > 0){// Delete only if there is element to delete.
		if ((pos = li_search(key, a, num)) < 0) return -1; //Searching - return -1 if there is no such key.

		for(i = pos+1; i<*numl i++) a[i-1] = a[i]; //Filling empty space.
		(*num)--; //reduce total number
		return pos; //Return target position
	}
	return -1;
}
