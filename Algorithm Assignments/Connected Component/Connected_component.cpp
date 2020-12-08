//2019014266_Lim Kyu Min_11802

#include <stdio.h>
#include <stdlib.h>
//#include <iostream>

typedef struct node{
	int src;
	struct node* next;
}NODE;

NODE* ADJ = NULL;
int* VISITED = NULL;
int totalNodeCnt = 0;

void BFS(int, NODE*);

int main(void){
	int N,M = 0;
	int i,j = 0;
	int from,dest = 0;
	scanf("%d %d", &N, &M);

	ADJ = (NODE*)malloc(sizeof(NODE)*(N+1));
	VISITED = (int*)malloc(sizeof(int)*(N+1));

	for(i = 0; i <= N; i++){
		ADJ[i].src = i;
		ADJ[i].next = NULL;
		VISITED[i] = 0;
	}

	for(i = 0; i < M; i++){
		scanf("%d %d",&from,&dest);
		NODE*newNode = (NODE*)malloc(sizeof(NODE));
		NODE*secondNode = (NODE*)malloc(sizeof(NODE));
		newNode->src = dest;
		newNode->next = NULL;
		secondNode->src = from;
		secondNode->next = NULL;

		NODE*curNext = ADJ[from].next;
		NODE*cur = &ADJ[from];

		while(curNext != NULL){
			cur = cur->next;
			curNext = cur->next;
		}
		cur->next = newNode;

		curNext = ADJ[dest].next;
		cur = &ADJ[dest];
		while(curNext != NULL){
			cur = cur->next;
			curNext = cur->next;
		}
		cur->next = secondNode;
	}

	for(i = 1; i <= N; i++){
		if(VISITED[i] == 0){
			BFS(i,&ADJ[i]);
			totalNodeCnt += 1;
		}
	}
	printf("%d\n",totalNodeCnt);

	return 0;
}

void BFS(int target,NODE*curNode){
	if(VISITED[target] != 1){
		VISITED[target] = 1;
	}//Visited
	while(curNode->next != NULL){
		curNode = curNode->next;
		if(VISITED[curNode->src] != 1){
			BFS(curNode->src,&ADJ[curNode->src]);
			//BFS(curNode->src,curNode);
			}
	}
	return;
}
