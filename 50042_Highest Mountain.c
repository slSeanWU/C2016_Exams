#include <stdio.h>
#include <stdlib.h>

int main(void){
	int maxAll_ir, maxAll_ic, maxAll_v;
	int fi_i, fi_v, se_i, se_v;
	
	int r, c;
	scanf("%d%d", &r, &c);
	int now;
	scanf("%d", &now);
	fi_i = se_i = maxAll_ir = maxAll_ic = 1;
	fi_v = maxAll_v = now;
	se_v = 0;
	
	for(int j = 2;j <= c;j++){
		scanf("%d", &now);
		
		if(now >= fi_v){
			if(now >= maxAll_v){
				maxAll_v = now;
				maxAll_ic = j;
			}
			se_v = fi_v;
			se_i = fi_i;
			fi_v = now;
			fi_i = j;
		}
		else if(now >= se_v){
			se_v = now;
			se_i = j;
		}
	}
	printf("%d %d\n", fi_i, se_i);
	
	for(int i = 2;i <= r;i++){
		scanf("%d", &now);
		fi_i = se_i = 1;
		fi_v = now;
		se_v = 0;
		if(now >= maxAll_v){
			maxAll_v = now;
			maxAll_ir = i;
			maxAll_ic = 1;
		}
		
		for(int j = 2;j <= c;j++){
			scanf("%d", &now);
			
			if(now >= fi_v){
				if(now >= maxAll_v){
					maxAll_v = now;
					maxAll_ir = i;
					maxAll_ic = j;
				}
				se_v = fi_v;
				se_i = fi_i;
				fi_v = now;
				fi_i = j;
			}
			else if(now >= se_v){
				se_v = now;
				se_i = j;
			}
		}
		
		printf("%d %d\n", fi_i, se_i);
	}
	
	printf("%d %d", maxAll_ir, maxAll_ic);
	
	return 0;
}

