//2091014266_LimKyuMin_Algorithm Analysis (13:00 ~ 14:30)

#include <stdio.h>
#include <stdlib.h>

int N,K = 0;

void maxHeapify(int*,int);
void extractMax(int*, int*, int);
void percolateDown(int*,int,int);

int main(void){
	int i = 0;
	int length = 0;
	int startIndex = 0;
	int *heap = NULL;
	int *result = NULL;

	scanf("%d %d", &N, &K);
	heap = (int*)malloc(sizeof(int)*N);
	result = (int*)malloc(sizeof(int)*N);

	for(i = 0; i < N; i++){
		scanf("%d",&heap[i]);
	}

	length = N;

	for(i = 0; i < K; i++){//Sorting

		//printf("Current Length: %d\n",length);
		maxHeapify(heap,length);
		extractMax(heap,result,length);
		percolateDown(heap,0, --length);
	}

	for(i = 0; i < K; i++){
		printf("%d ", result[i]);
	}

	printf("\n");

	for(i = 0; i < N-K; i++){
		printf("%d ", heap[i]);
	}

	return 0;
}

void maxHeapify(int* heap, int len){
	int mid = (int)(len/2) - 1;
	int i = 0;

	for(i = mid; i >= 0; i--){
		percolateDown(heap,i,len);
	}
}

void percolateDown(int*heap, int i, int len){
	int left =  0; 
	int right = 0;
	
	if(2*(i+1) <= len)
		left = heap[2*(i + 1) - 1];

	if(2*(i + 1) + 1 <= len) //if current node have right child
		right = heap[2*(i + 1)];

		//printf("CurNode: %d, Left: %d, Right: %d\n",heap[i],left,right);

	if(heap[i] < left || heap[i] < right){
		if(left > right){
			//printf("Bigger Left!\n");
			int temp = heap[2*(i+1) - 1];
			heap[2*(i+1) - 1] = heap[i];
			heap[i] = temp;
			percolateDown(heap,2*(i+1)-1,len);

		}else{
			//printf("Bigger Right!\n");
			int temp = heap[2*(i+1)];
			heap[2*(i+1)] = heap[i];
			heap[i] = temp;
			percolateDown(heap,2*(i+1),len);
		}
	}
}

void extractMax(int* heap, int* result, int len){
	int curIdx = N - len;
	//printf("MAX: %d\n", heap[0]);
	result[curIdx] = heap[0];

	//printf("Changing with the rightmost leaf: %d\n", heap[len-1]);
	int temp = heap[len-1];
	heap[len-1] = heap[0];
	heap[0] = temp;
}

