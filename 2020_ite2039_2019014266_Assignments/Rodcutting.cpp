//2019014266_LimKyuMin_AlgorithmAnalysis(13:00~14:30)

#include <stdio.h>

int p[101];
int r[101];
int s[101];

int main(void){
	int n = 0;
	int i = 0;
	int j = 0;
	int max = 0;

	scanf("%d",&n);

	p[0] = 0;
	s[0] = 0;

	for(i = 1; i <= n; i++)
		scanf("%d",&p[i]);

	for(i = 0; i <= n; i++){
		max = 0;
		for(j = 1; j <= i; j++){
			if(max < p[j] + r[i-j]){
				max = p[j] + r[i-j];
				s[i] = j;
				//printf("Longest Updated: left rod = %d", j);
			}
			r[i] = max;
			//printf("%d: %d, %d\n",i,r[i],max);
		}
		//printf("%d: %d",i,s[i]);
	}

//	for(i=0;i<=n;i++)
//		printf("%d ",s[i]);

	printf("%d\n", r[n]);//Maximum Profit

	while(n>0){
		printf("%d ",s[n]);
		n-=s[n];
	}
}

