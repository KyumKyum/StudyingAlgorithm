//2019014266_Lim Kyu Min_Algorithm Analysis (13:00~14:30)

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int*);

int n = 0;

int main (void)
{
	int i = 0;
	int *arr = NULL;

	scanf("%d",&n);

	arr = (int*)malloc(sizeof(int)*n); //Dynamic Allocation
	
	for(i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}

	insertionSort(arr);

	return 0;
}

void insertionSort(int* arr){
	int i,j,curKey = 0;

	for(i = 1; i < n; i++){ //Scan all array
		curKey = arr[i];

		for(j = i-1; j >= 0 && arr[j] < curKey; j--){
			arr[j + 1] = arr[j];
		}

		arr[j + 1] = curKey;
	}

	
	for(i = 0; i < n; i++){
		printf("%d\n", arr[i]);
	}

	return;
}


