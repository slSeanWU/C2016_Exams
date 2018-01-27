#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool chosen[64], hatred[64][64];
int total, best = 0, donate[64];

void compute(int pos, int raised){
	if(pos == total){
		if(raised > best)
			best = raised;

		return;
	}

	bool causeHate = false;
	for(int i = 0;i < pos;i++)
		if(chosen[i] && hatred[i][pos]){
			causeHate = true;
			break;
		}

	if(!causeHate){
		chosen[pos] = true;
		compute(pos+1, raised+donate[pos]);
		chosen[pos] = false;
	}
	compute(pos+1, raised);

	return;
}

int main(void){
	scanf("%d", &total);

	for(int i = 0;i < total;i++)
		scanf("%d", &donate[i]);

	for(int i = 0;i < total;i++)
		for(int j = 0;j < total;j++)
			scanf("%d", &hatred[i][j]);

	compute(0, 0);

	printf("%d", best);

	return 0;
}