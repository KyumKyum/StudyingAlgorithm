//2019014266_Lim Kyu Min_Algorithm Analysis 11802

#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>

typedef struct heap{
	char str[5];
	int number;
	struct heap* leftChild;
	struct heap* rightChild;
}HEAP;

HEAP* MINHEAP[60001]; //= {{{'\0'},INT_MAX,NULL,NULL}};

int N = 0;
int SIZE = 0;
int TOTAL = 0;
int RESULT = 0;

void minHeapify();
void percolateDown(int);
void percolateUp(int);
HEAP* buildHuffman();
HEAP* extractMin();
void calculateHuffman(HEAP*,int);
int calculateBitnum();

int main(void){
	int i = 0;
	scanf("%d",&N);

	for(i = 0; i < N; i++){
		MINHEAP[i] = (HEAP*)malloc(sizeof(HEAP));
		scanf("%s",MINHEAP[i]->str);
		scanf("%d",&(MINHEAP[i]->number));
//		printf("INPUT\n");
	}

	scanf("%d",&TOTAL);
	SIZE = N;

	if(SIZE <= 1){
		printf("%d\n",TOTAL);
		printf("%d\n",TOTAL);
	}else{

		minHeapify();
		//printf("HEAPIFY OK\n");
		HEAP* startNode = buildHuffman();
		//printf("HUFFMAN BUILD\n");
		calculateHuffman(startNode,0);

		printf("%d\n%d\n",calculateBitnum()*TOTAL,RESULT);
	}
	return 0;
}

void minHeapify(){
	int mid = (int)(SIZE/2)-1;
	int i = 0;

	for(i = mid; i >= 0; i--){
		percolateDown(i);
	}

//	for(i = 0; i < N; i++){
//		printf("%s %d\n",MINHEAP[i].str, MINHEAP[i].number);
//	}
}

void percolateDown(int curPos){
	HEAP* left = NULL;// = {{'\0'},INT_MAX,NULL,NULL};
	HEAP* right = NULL;// = {{'\0'},INT_MAX,NULL,NULL};

	if((2*(curPos+1) - 1) < SIZE && (2*(curPos+1) < SIZE)){
		//printf("HAVE TWO CHILD\n");
		//if(2*(curPos+1) - 1 < SIZE)
		left = MINHEAP[2*(curPos+1)-1];
		//if(2*(curPos+1) < SIZE)
		right = MINHEAP[2*(curPos+1)];

		if(MINHEAP[curPos]->number > left->number || MINHEAP[curPos]->number > right->number){
			if(left->number < right->number){
				HEAP* temp = MINHEAP[curPos];
				MINHEAP[curPos] = MINHEAP[2*(curPos+1)-1];
				MINHEAP[2*(curPos+1)-1] = temp;
				percolateDown(2*(curPos+1)-1);
			}else{
				HEAP* temp = MINHEAP[curPos];
				MINHEAP[curPos] = MINHEAP[2*(curPos+1)];
				MINHEAP[2*(curPos+1)] = temp;
				percolateDown(2*(curPos+1));
			}
		}
	}else if(2*(curPos+1) - 1 < SIZE){
		//printf("HAVE ONLY LEFT CHILD\n");
		if(2*(curPos+1)-1 < SIZE)
			left = MINHEAP[2*(curPos+1)-1];

		if(MINHEAP[curPos]->number > left->number){
			HEAP* temp = MINHEAP[curPos];
			MINHEAP[curPos] = MINHEAP[2*(curPos+1)-1];
			MINHEAP[2*(curPos+1)-1] = temp;
		}
	}else{
		return;
	}
}

void percolateUp(int curPos){
	if(curPos > 0){
		int parentPos = 0;
		if(curPos%2 == 0)
			parentPos = (int)((curPos/2)-1);
		else
			parentPos = (int)((curPos/2));
		
		if(MINHEAP[parentPos]->number > MINHEAP[curPos]->number){
			HEAP* temp = MINHEAP[parentPos];
			MINHEAP[parentPos] = MINHEAP[curPos];
			MINHEAP[curPos] = temp;

			percolateUp(parentPos);
		}
	}
}

HEAP* buildHuffman(){
	//HEAP* returnNode = NULL;
	while(SIZE > 1){
		HEAP* leftNode = NULL;
		HEAP* rightNode = NULL;
		HEAP* parentNode = (HEAP*)malloc(sizeof(HEAP));

		leftNode = extractMin();
		rightNode = extractMin();
		//printf("EXTRACTED TWO NODES\n");

		parentNode -> str[0] = '\0';
		parentNode -> number = leftNode -> number + rightNode -> number;
		parentNode -> leftChild = leftNode;
		parentNode -> rightChild = rightNode;

		//if(SIZE > 0){
		MINHEAP[SIZE++] = parentNode;
		percolateUp(SIZE-1);
		//printf("PERCOLATE UP\n");
		//}else{
		//	returnNode = parentNode;
	//	}
	}
	return extractMin();
	//return returnNode;
}

HEAP* extractMin(){
	//printf("EXTRACTING...\n");
	HEAP* extracted = MINHEAP[0];
	MINHEAP[0] = MINHEAP[--SIZE];

	//printf("PERCOLATE DOWN FROM EXTRACTMIN\n");
	percolateDown(0);
	//printf("PERCOLATE DOWNED\n");
	return extracted;
}

void calculateHuffman(HEAP* curNode,int bitNum){
	if(curNode->str[0] == '\0'){
		calculateHuffman(curNode->leftChild,bitNum+1);
		calculateHuffman(curNode->rightChild,bitNum+1);
	}else if((curNode->leftChild == NULL) && (curNode->rightChild == NULL)){
		RESULT += ((curNode->number)*bitNum);
	}
}

int calculateBitnum(){
	int i = 0;
	int power = 1;
	for(i = 1; power*2 < N; i++){
		power *= 2;
	}

	return i;
}
