#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

int main(void){
	int n, m;
	scanf("%d%d", &n, &m);
	
	int weight[m][m];
	for(int i = 0;i < m;i++)
		for(int j = 0;j < m;j++)
			weight[i][j] = 1;
			
			
	int thres = 2*m*m, train[16][16]; 
	int acc;
	for(int p = 0;p < n;p++){
		scanf("%d", &acc);
		
		int sum = 0;
		int train[m][m];
		for(int i = 0;i < m;i++)
			for(int j = 0;j < m;j++){
				scanf("%d", &train[i][j]);
				sum += weight[i][j]*train[i][j];
			}
				

			
		if(acc == 1){
			if(sum >= thres)  continue;
			else{
				for(int i = 0;i < m;i++)
					for(int j = 0;j < m;j++)
						if(train[i][j])
							weight[i][j] *= 2;
			}
		}
		else{
			if(sum < thres)  continue;
			else{
				for(int i = 0;i < m;i++)
					for(int j = 0;j < m;j++)
						if(train[i][j]){
							weight[i][j] /= 2;
							
							if(weight[i][j] == 0)
								weight[i][j]++;
						}				
			}
		}
	}
	
	int query;
	scanf("%d", &query);
	
	for(int p = 0;p < query;p++){
		int sum = 0;
		int test[m][m];
		for(int i = 0;i < m;i++)
			for(int j = 0;j < m;j++){
				scanf("%d", &test[i][j]);
				sum += weight[i][j]*test[i][j];	
			}
			
		if(sum >= thres)  printf("1\n");
		else  printf("0\n");	
	}
	
	return 0;
}

