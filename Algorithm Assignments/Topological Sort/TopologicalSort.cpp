//2019014266_LimKyuMin_11802

#include <stdio.h>
#include <stdlib.h>
#include <stack>

typedef struct node{
	int visited;
	int src;
	struct node* next;
}NODE;

NODE*ADJ = NULL;
int N,M = 0;
int*engress = NULL;
int*answer = NULL;
int cnt = 1;

bool topoSort();

int main(void){
	int i = 0;
	int from,dest = 0;

	scanf("%d %d",&N,&M);
	ADJ = (NODE*)malloc(sizeof(NODE)*(N+1));
	engress = (int*)malloc(sizeof(int)*(N+1));
	answer = (int*)malloc(sizeof(int)*(N+1));
	for(i = 0; i <= N; i++){
		ADJ[i].visited = 0;
		ADJ[i].src = i;
		ADJ[i].next = NULL;
		engress[i] = 0;
		answer[i] = 0;
	}

	for(i = 0; i < M; i++){
		scanf("%d %d",&from,&dest);
		NODE*newNode = (NODE*)malloc(sizeof(NODE));
		newNode->src = dest;
		newNode->next = NULL;
		newNode->visited = 0;
		
		NODE*curNode = &ADJ[from];
		NODE*nextNode = ADJ[from].next;

		while(nextNode != NULL){
			curNode = curNode->next;
			nextNode = curNode->next;
		}
		curNode->next = newNode;
		engress[dest] += 1;

		//printf("%d: input %d %d\n",i,from,dest);
	}
	//printf("End of input\n");
	
	if(topoSort()){
		printf("1\n");
		for(i = 1; i <= N; i++){
			printf("%d ",answer[i]);
		}
		printf("\n");
	}else{
		printf("0\n");
	}

}

bool topoSort(){
	int i = 1;
	std::stack<int> s;

	for(i = 1; i <= N; i++){
		if(engress[i] == 0){
			s.push(i);
			//printf("Push %d\n",i);
		}
	}

	while(!(s.empty())){
		int curIdx = s.top();
		s.pop();

		NODE*curNode = &ADJ[curIdx];
		while(curNode != NULL){
			int idx = curNode->src;
			engress[idx] -= 1;
			if(engress[idx] == -1){
				answer[cnt++] = idx;
				//printf("%d ",idx);
			}
			else if(engress[idx] == 0){
				s.push(idx);
				//printf("Push %d\n",idx);
			}
			curNode = curNode->next;
		}
	}

	for(i = 1; i <= N; i++){
		if(engress[i] != -1){
			return false;
		}
	}
	return true;
}
