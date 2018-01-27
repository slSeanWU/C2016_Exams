#include <stdio.h>
#include <stdlib.h>

int main(void){
	int N;
	scanf("%d", &N);
	int in;
	scanf("%d", &in);
	
	int pre = (in >> 31 & 1), total = 0;
	for(int i = 0;i < N;i++){
		if(i > 0)
			scanf("%d", &in);
			
		for(int j = 31;j >= 0;j--){
			if((in >> j & 1) == pre)
				printf("%d", pre);
			else{
				pre = (in >> j & 1);
				printf("\n");
				
				int space = total%40;
				while(space--)
					printf(" ");
				
				printf("%d", pre);
			}
			
			total++;
		}
	}
	
	return 0;
}

