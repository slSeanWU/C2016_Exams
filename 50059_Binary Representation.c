#include <stdio.h>
#include <stdlib.h>

int main(void){
	char word[64];
	int N, block = 0, count = 0;
	scanf("%s %d", word, &N);
	
	while(N--){
		int in;
		scanf("%d", &in);
		
		for(int i = 31;i >= 0;i--){
			int toAdd = (in>>i) & 1;
			block = block<<1 | toAdd;
			count++;
			
			if(count == 5){
				putchar(word[block]);
				block = 0, count = 0;
			}
		}
	}
	
	return 0;
}

