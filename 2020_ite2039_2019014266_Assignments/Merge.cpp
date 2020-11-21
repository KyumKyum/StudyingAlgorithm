//2019014266_Lim Kyu Min_Algorithm Analysis(13:00 ~ 14:30)

#include <stdio.h>
#include <stdlib.h>

void merge(int*, int, int, int);
void mergeSort(int*, int, int);

int n = 0;
int *arr = NULL;

int main(void) {
	int i = 0;

	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	mergeSort(arr, 0, n-1);

	for (i = 0; i < n; i++)
		printf("%d\n", arr[i]);

	return 0;
}

void mergeSort(int* arr, int p, int r) {
	int i = 0;
	if (p < r) {
		int q = (int)((p + r) / 2);
		mergeSort(arr, p, q);
		mergeSort(arr, q+1, r);
		merge(arr, p, q, r);
	}

	return;
}

void merge(int* arr, int p, int q, int r) {
	//printf("p= %d, q= %d, r= %d\n", p, q, r);

	int *left_arr, *right_arr = NULL;
	int left, right, dest = 0;
	int left_size = q - p + 1;
	int right_size = r - q;

	left_arr = (int*)malloc(sizeof(int)*left_size);
	right_arr = (int*)malloc(sizeof(int)*right_size);

	for (left = 0; left < left_size; left++){
		//printf("%d goes left array\n", arr[p+left]);
		left_arr[left] = arr[p + left];
	}

	for (right = 0; right < right_size; right++){
		//printf("%d goes right array\n", arr[q+right+1]);
		right_arr[right] = arr[q + right + 1];
	}

	left = 0;
	right = 0;

	for (dest = p; dest <= r; dest++) { //Case 1: Right element exhausted - Automatically insert left element
		if (right >= right_size){
			//printf("Right Array Exhausted: Left element inserted\n");
			arr[dest] = left_arr[left];
			left++;
		}else if(left >= left_size){ //Case 2: Left element exhausted - Automatically insert right element
			//printf("Left Array Exhausted: Right element inserted\n");
			arr[dest] = right_arr[right];
			right++;
		}else if(left_arr[left] >= right_arr[right]){ //Case 3: Left element is bigger or equal than right element - Insert left element
			//printf("Bigger left element\n");
			arr[dest] = left_arr[left];
			left++;
		}else{ //Case 4: Right element is bigger than left element - Insert right element
			//printf("Bigger right element\n");
			arr[dest] = right_arr[right];
			right++;
		}
	}

	free(left_arr);
	free(right_arr);

	//printf("\n\n");

	return;
}
