//2019014266_LimKyuMin_Algorithm Analysis(13:00 ~ 14:30)

#include <stdio.h>

int A[2][101] = { 0 };
int T[2][101] = { 0 };
int S[2][101] = { 0 };
int L[2][101] = { 0 };
int R[101] = { 0 };
int E[2] = { 0 };
int X[2] = { 0 };


int main(void){
	int i = 0;
	int j = 0;
	int N = 0;
	int fastestTime = 0;
	int fastestLine = 0;
	scanf("%d",&N);

	for(i = 0; i < 2; i++)
		scanf("%d",&E[i]);

//	printf("Input Check: E\n");
//	for(i = 0; i < 2; i++)
//		printf("%d ",E[i]);
//	printf("\n");


	for(i = 0; i < 2; i++)
		scanf("%d",&X[i]);

//	printf("Input Check: X\n");
//	for(i = 0; i < 2; i++)
//		printf("%d ", X[i]);
//	printf("\n");

	for(i = 0; i < 2; i++){
		for(j = 0; j < N; j++)
			scanf("%d",&A[i][j]);
	}

//	printf("Input Check: A\n");
//	for(i = 0; i < 2; i++){
//		for(j = 0; j < N; j++)
//			printf("%d ",A[i][j]);
//		printf("\n");
//	}

	for(i = 0; i < 2; i++){
		for(j = 0; j < N-1; j++)
			scanf("%d",&T[i][j]);
	}

//	printf("Input Check: T\n");
//	for(i = 0; i < 2; i++){
//		for(j = 0; j < N-1; j++)
//			printf("%d ",T[i][j]);
//		printf("\n");
//	}

	for(i = 0; i < 2; i++){
		S[i][0] = A[i][0] + E[i];
		L[i][0] = -1;
	}

	for(i = 1; i < N; i++){
		if(S[0][i-1] <= S[1][i-1] + T[1][i-1]){ //Assembly Line 1
			S[0][i] = S[0][i-1] + A[0][i];
			L[0][i] = 0;
		}else{
			S[0][i] = S[1][i-1] + T[1][i-1] + A[0][i];
			L[0][i] = 1;
		}

		if(S[1][i-1] <= S[0][i-1] + T[0][i-1]){//Assembly Line 2
			S[1][i] = S[1][i-1] + A[1][i];
			L[1][i] = 1;
		}else{
			S[1][i] = S[0][i-1] + T[0][i-1] + A[1][i];
			L[1][i] = 0;
		}
	}

//	for(i = 0; i < 2; i++){
//		for(j = 0; j < N; j++){
//			printf("%d ",S[i][j]);
//		}
//		printf("\n");
//	}

	if(S[0][N-1] + X[0] <= S[1][N-1] + X[1]){
		fastestTime = S[0][N-1] + X[0];
		fastestLine = 0;
	}else{
		fastestTime = S[1][N-1] + X[1];
		fastestLine = 1;
	}

	for(i = N-1; i >= 0; i--){
		R[i] = fastestLine + 1;
		fastestLine = L[fastestLine][i];
	}

	printf("%d\n",fastestTime);

	for(i = 0; i < N; i++){
		printf("%d %d\n",R[i],i+1);
	}

	return 0;


}
