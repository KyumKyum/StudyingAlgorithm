//2019014266_LimKyuMin_Algorithm Analysis(13:00 ~ 14:30)

#include <stdio.h>
#include <stdlib.h>

void maxHeapify(int*, int);
void extractMax(int*, int*, int, int);
void percolateDown(int*,int,int);
void substituteKey(int*,int,int);

int first = 0;
int second = 0;
int third = 0;
int heapSize = 0;
int extractedSize = 0;

int main(void){
	int i = 0;

	int heap[100000] = { 0 };
	int extracted[100000] = { 0 };
	int priorityQueue[100000] = { 0 };

	while(1){

		//printf("Before scan\n");
		scanf("%d",&first);
		if(first == 0)
			break;
		else if(first == 1 || first == 3){
			scanf("%d",&second);

			if(first == 3)
				scanf("%d",&third);
		}

		//printf("Before Switch\n");

		switch(first){
			case 1:
				//printf("Heapsize: %d\n",heapSize);
				heap[++heapSize-1] = second;
				maxHeapify(heap,heapSize);
				break;

			case 2:
				extractMax(heap,extracted,--heapSize,++extractedSize);
				percolateDown(heap,0,heapSize);
				break;

			case 3:
				substituteKey(heap,second,third);
				maxHeapify(heap,heapSize);
				break;
		}
	}

	for(i = 0; i < extractedSize; i++)
		printf("%d ", extracted[i]);

	printf("\n");

	for(i = 0; i < heapSize; i++)
		printf("%d ", heap[i]);

	printf("\n");

	return 0;
}

void maxHeapify(int* heap, int len){
	int mid = (int)(len/2) - 1;
	if(mid < 0)
		mid = 0;

	int i = 0;

	for(i = mid; i >= 0; i--){
		percolateDown(heap,i,len);
	}
}

void percolateDown(int*heap, int i, int len){
	
	int left = heap[2*(i + 1) - 1];
	int right = heap[2*(i + 1)];

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

void extractMax(int* heap, int* extracted, int len, int curIdx){
	extracted[curIdx-1] = heap[0];

	//printf("Changing with the rightmost leaf: %d\n", heap[len-1]);
	int temp = heap[len];
	heap[len] = heap[0];
	heap[0] = temp;

	heap[len] = 0;
}

void substituteKey(int*heap, int target, int key){

	heap[target-1] = key;
}
