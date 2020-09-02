//Merge Sort

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void merge_sort(int a[], int n){
	int i, j, k, first, second, size;
	int *b;
	b = (int*)malloc(sizeof(int)*n); //Merge Dest

	for(size = 1; size < n; size*=2){ //Start from 1 element, double it for each sort
		first = -2*size; //Initial value of first and second
		second = first + size;

		while (second + size*2 < n){ //While next second value is less than n
			first = second + size; //first += size*2
			second = first + size; //second += size*2
			i = first;
			j = second;
			k = first;

			while (i < first + size || (j < second+size && j < n)){ //While merge incomplete
				if(a[i] <= a[j]){ //smaller first
					if(i < first + size) b[k++] = a[i++]; //not exhausted
					else b[k++] = a[j++]; //exhausted
				}else{//smaller second
					if(j < second+size && j < n) b[k++] = a[j++]; //not exhausted
					else b[k++] = a[i++]; //exhausted
				}
			}
		}

		//Merged
		//for(i = 0; i < n; i++) a[i]=b[i]; //Paste Merged result to original array
		//Pointer Swapping
		int *c = a;
		a = b;
		b = c;
	}
	free(b);

	for(i = 0; i < n; i++){
		printf("%d ",a[i]);
	}

	return;
}

int main(){
	int i = 0;
	int arr[10] = { 0 };
	printf("Merge Sort\n");
	printf("Enter 10 Elements to Sort: ");

	for(int i = 0; i < SIZE; i++){
		scanf("%d", &arr[i]);
	}

	merge_sort(arr,SIZE);

	return 0;
}
