#include <stdio.h>
#include <stdlib.h>

int main(void){
	int mts;
	scanf("%d", &mts);
	
	int h1, h2, h3;
	int cost = 0;
	short rec;
	
	scanf("%d%d", &h1, &h2);
	if(h2-h1 > 0){
		rec = 1;
		cost += 3*abs(h2-h1);
	}
	else{
		rec = 0;
		cost += 2*abs(h2-h1);
	}
	
	mts -= 2;
	while(mts--){
		scanf("%d", &h3);
		
		if(h3-h2 > 0){
			if(rec){
				rec = 1;
				cost += 4*abs(h3-h2);
			}
			else{
				rec = 1;
				cost += 3*abs(h3-h2);
			}
		}
		else{
			if(rec){
				rec = 0;
				cost += 3*abs(h3-h2);
			}
			else{
				rec = 0;
				cost += 2*abs(h3-h2);
			}
		}
		
		h1 = h2;
		h2 = h3;
	}
	
	printf("%d\n", cost);
	
	return 0;
}

