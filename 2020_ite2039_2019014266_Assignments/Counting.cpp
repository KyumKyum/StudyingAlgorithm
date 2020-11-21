//2019014266_LimKyuMin_Algorithm Analysis (13:00 ~ 14:30)

#include <stdio.h>
#include <stdlib.h>

typedef struct range{
	int start;
	int end;
}RANGE;

typedef struct count{
	int key;
	int number;
}COUNT;

int N,M,K = 0;

int main(void){
	RANGE*range = NULL;
	COUNT*count = NULL;

	int i = 0;

	scanf("%d %d %d",&N,&M,&K);
	range = (RANGE*)malloc(sizeof(RANGE)*K);
	count = (COUNT*)malloc(sizeof(COUNT)*(M+1));

	for(i=0;i<=M;i++){
		count[i].key = i;
	}

	for(i = 0; i < K; i++){
		int start = 0;
		int end = 0;

		scanf("%d %d",&start, &end);

		range[i].start = start <= end ? start : end;
		range[i].end = start <= end ? end : start;

		//printf("st: %d e: %d\n",range[i].start,range[i].end);
	}

	for(i = 0; i < N; i++){
		int input = 0;
		scanf("%d",&input);

		if(input > M)
			continue;
		else{
			count[input].number += 1;

			//printf("Input: %d, Number: %d\n",count[input].key,count[input].number);
		}
	}

	for(i = 1; i <= M; i++){
		count[i].number += count[i-1].number;
	}

//	for(i = 0; i <= M; i++){
//		printf("[%d - %d] ",count[i].key,count[i].number);
//	}

//	printf("\n");

	for(i = 0; i < K; i++){
		printf("%d\n",count[range[i].end].number -count[(range[i].start)-1].number);
	}

	return 0;

}
