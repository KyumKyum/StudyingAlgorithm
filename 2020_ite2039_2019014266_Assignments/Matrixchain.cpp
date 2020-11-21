//2019014266_Lim Kyu Min_Algorithm Analysis (13:00 ~ 14:30)

#include <stdio.h>
#include <limits.h>

int m[101][101] = { 0 };
int s[101][101] = { 0 };
int p[101] = { 0 };

void printOptimalParens(int, int);

int main(void){
	int n = 0;
	int i, j, k, l = 0;

	scanf("%d",&n);
	
	for(i = 0; i <= n; i++){
		scanf("%d",&p[i]);
	}

	for(i = 0; i < n; i++){
		m[i][i] = 0;
	}

	for(l = 1; l < n; l++){
		for(i = 0; i < n - l + 1; i++){
			j = i + l;
			m[i][j] = INT_MAX;

			for(k = i; k < j; k++){
				int q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
				if(q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}

	printf("%d\n",m[0][n-1]);
	printOptimalParens(0, n-1);

	return 0;
}

void printOptimalParens(int i, int j){
	
	if(i == j){
		printf("%d ",i + 1);
	}else {
		printf("( ");
		printOptimalParens(i,s[i][j]);
		printOptimalParens(s[i][j]+1, j);
		printf(") ");
	}
}

