//2019014266_Lim Kyu Min_Algorithm Analysis (13:00 ~ 14:30) 11802

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Heap{
	char str[5];
	int number;
	struct Heap* leftChild;
	struct Heap* rightChild;
}HEAP;

HEAP* extractMin();
void percolateDown(int);
void percolateUp(int);
void calculate(HEAP*, int);

HEAP heap[30000] = {{{'\0'},-1,NULL,NULL}};

int N = 0;
int SIZE = 0;
int TOTAL = 0;
int REDUCED = 0;

int main(void){
	int i = 0;
	int mid = 0;
	scanf("%d",&N);

	//heap = (HEAP*)malloc(sizeof(HEAP));
	//RESULT = (NODE*)malloc(sizeof(HEAP));

	for(i = 0; i < N; i++){
		scanf("%s",heap[i].str);
		scanf("%d",&heap[i].number);
	}

	scanf("%d",&TOTAL);

//	for(i = 0; i < N; i++){
//		printf("%s %d\n",heap[i].str,heap[i].number);
//	}

	mid = (N/2)-1; //0 based code
	SIZE = N;
	//Build Min Heap
	
	for(i = mid; i >= 0; i--){
		int left = heap[(2*i)+1].number;
		int right = 0;
		if(2*i+2 < SIZE)
			right = heap[(2*i)+2].number;
		else
			right = INT_MAX;

		//printf("NODE %d: left: %d, right: %d\n",i,left, right);
		if(heap[i].number > left || heap[i].number > right){
			if (left < right){
				HEAP temp = heap[i];
				heap[mid] = heap[(2*i)+1];
				heap[(2*i)+1] = temp;
			} else{
				HEAP temp = heap[i];
				heap[i] = heap[(2*i)+2];
				heap[(2*i)+2] = temp;
			}
		}
	}

//	printf("\n");
//	for(i = 0; i < N; i++){
//		printf("%s %d\n",heap[i].str,heap[i].number);
//	}
//	printf("\n");

//	printf("MIN HEAPIFY\n");

	HEAP* parentNode = NULL; 

	while(SIZE > 0){

		HEAP*first = (HEAP*)malloc(sizeof(HEAP));
		HEAP*second = (HEAP*)malloc(sizeof(HEAP));
		HEAP*newNode = (HEAP*)malloc(sizeof(HEAP));

		first = extractMin();
		second = extractMin();

		//printf("first & second extracted\n");

		newNode->str[0] = '\0';
		newNode->number = first->number + second->number;
		newNode->leftChild = first;
		newNode->rightChild = second;

		
		if(SIZE >  0){
			heap[SIZE++] = *newNode;
			percolateUp(SIZE - 1);
		}else{
			parentNode = newNode;
		}
	}

	calculate(parentNode, 0);

	printf("%d\n",3*TOTAL);

	printf("%d\n",REDUCED);

	return 0;
}

HEAP* extractMin(){
	HEAP* minVal = (HEAP*)malloc(sizeof(HEAP));
	//printf("BEFORE HEAP\n");
	*minVal = heap[0];
	heap[0] = heap[SIZE-1];
	SIZE--;
	//printf("BEFORE PERCOLATEDOWN\n");
	percolateDown(0);
	
	return minVal;
}

void percolateDown(int curPos){
	
	HEAP left = {{'\0'},INT_MAX,NULL,NULL};
	HEAP right = {{'\0'},INT_MAX,NULL,NULL};

	//printf("SIZE = %d\n",SIZE);
	//printf("curPos = %d\n",curPos);
	//printf("curNum = %d\n",heap[curPos].number);

	if((2*curPos)+1 < SIZE){
		//printf("CASE 1: LEFT EXIST, POSITION %d\n",2*curPos+1);
		left = heap[(2*curPos)+1];
	}
	if((2*curPos)+2 < SIZE){
		//printf("CASE 2: RIGHT EXIST, POSITION %d\n",2*curPos+2);
		right = heap[(2*curPos)+2];
	}
	
	if(heap[curPos].number > left.number || heap[curPos].number > right.number){
		if(left.number<right.number){
			HEAP temp = heap[curPos];
			heap[curPos] = heap[(2*curPos)+1];
			heap[(2*curPos)+1] = temp;
			percolateDown(2*curPos+1);
		}else{
			HEAP temp = heap[curPos];
			heap[curPos] = heap[2*(curPos)+2];
			heap[(2*curPos)+2] = temp;
			percolateDown(2*curPos+2);
		}
	}

	return;
}

void percolateUp(int curPos){
	int parent = 0;
	if(curPos%2 == 0)
		parent = (curPos/2)-1;
	else
		parent = curPos/2;

	if(heap[parent].number > heap[curPos].number){
		HEAP temp = heap[parent];
		heap[parent] = heap[curPos];
		heap[curPos] = temp;
		percolateUp(parent);
	}

	return;
}

void calculate(HEAP* node, int code){
	if(node->str[0] == '\0'){
		//printf("\nNODE IN LEVEL %d\n",code + 1);
		//printf("CurNode: %s, %d\n",node->str,node->number);
		calculate(node->leftChild, code + 1);
		calculate(node->rightChild, code + 1);
	}else{
		//printf("\nLEAF IN LEVEL %d\n",code + 1);
		//printf("CurNode: %s, %d\n",node->str, node->number);
		REDUCED += ((node->number) * code);
	}
}
