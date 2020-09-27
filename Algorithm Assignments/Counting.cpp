//2019014266_LimKyuMin_Algorithm Analysis(13:00 ~ 14:30)

#include <stdio.h>
#include <stdlib.h>

int N,M,K = 0;

typedef struct range{
	int start;
	int end;
} RANGE;

int main(void){
int i = 0;

	int *input = NULL;
	RANGE *range = NULL;
	
	scanf("%d %d %d",&N, &M, &K);

	input = (int*)malloc(sizeof(int)*N);
	range = (RANGE*)malloc(sizeof(RANGE)*K);

	for(i = 0; i < K; i++){
		scanf("%d %d",&range[i].start, &range[i].end);
	}

	for(i = 0; i < N; i++){
		scanf("%d",&input[i]);
	}


	for(i = 0; i < K; i++){
		int j = 0;
		int result = 0;
		
		for(j = 0; j < N; j++){
			if(input[j] > M){
				continue;
			}else{
				if(input[j] >= range[i].start && input[j] <= range[i].end)
					result++;
			}
		}

		printf("%d\n",result);
	}

	return 0;
}
