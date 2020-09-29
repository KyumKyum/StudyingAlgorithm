//2019014266_LimKyuMin_Algorithm Analysis (13:00~14:30)

#include <stdio.h>
#include <stdlib.h>

int N,M = 0;

int main(void){
	int *inputA, *inputB, *result  = NULL;
	int i = 0;
	int j = 0;
	int idx = 0;
	
	scanf("%d %d",&N,&M);
	inputA = (int*)malloc(sizeof(int)*N);
	inputB = (int*)malloc(sizeof(int)*M);

	int size = N > M ? N : M;
	//printf("size : %d\n",size);
	result = (int*)malloc(sizeof(int)*size);

	for(i = 0; i < N; i++){
		scanf("%d",&inputA[i]);
	}

	for(j = 0; j < M; j++){
		scanf("%d",&inputB[j]);
	}


//	printf("FINDING SAME KEY\n");

	for(i = 0; i < N; i++){
		//printf("i: %d\n",i);
		for(j = 0; j < M; j++){
			//printf("j: %d\n",j);
			if(inputA[i] == inputB[j]){
			//	printf("idx: %d\n",idx);
			//	printf("A B Duplicate: %d\n",inputB[j]);
				result[idx] = inputB[j];
				idx++;
			//	printf("%d\n", idx);
				break;
			}
		}
	}

	//Remove Duplicates
	size = idx;
	//printf("SIZE: %d\n",size);

	//printf("REMOVE DUPLICATES\n");
	for(i = 0; i < size; i++){
		int curValue = result[i];
		for(j = 0; j < size; j++)
			if(curValue == result[j] && j != i){
				//printf("Duplicate Found : %d\n",result[j]);
				int temp = result[j];
				result[j] = result[size];
				result[size] = temp;
				size--;
			}
	}

	printf("%d\n", size);

	return 0;
	
}
