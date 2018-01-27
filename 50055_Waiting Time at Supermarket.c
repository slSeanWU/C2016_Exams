#include <stdio.h>
#include <stdlib.h>

int main(void){
	int N, M;
	scanf("%d%d", &N, &M);
	
	int ready[N], wait = 0;
	for(int i = 0;i < N;i++)
		ready[i] = 0;
		
	while(M--){
		int arr, len;
		scanf("%d%d", &arr, &len);
		
		int fastest_c = -1, fastest_time = 2000000;
		for(int i = 0;i < N;i++)
			if( ready[i] < fastest_time ){
				fastest_time = ready[i];
				fastest_c = i;
			}
			
		if(ready[fastest_c] > arr){
			wait += ready[fastest_c]-arr;
			ready[fastest_c] += len;
		}
		else
			ready[fastest_c] = arr+len;
	}
	
	printf("%d", wait);
	
	return 0;
}

