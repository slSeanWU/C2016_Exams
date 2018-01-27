#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int dis[16][16];
bool passed[16];
int N, best = 2147483647;

void travel(int nowAt, int traveled, int step){
	if(traveled >= best)
		return;

	if(step == N-1){
		traveled += dis[nowAt][0];

		if(traveled < best)
			best = traveled;

		return;
	}

	for(int i = 0;i < N;i++){
		if(nowAt == i)
			continue;

		if(!passed[i]){
			passed[i] = true;
			travel(i, traveled+dis[nowAt][i], step+1);
			passed[i] = false;
		}	
	}
}

int main(void){
	scanf("%d", &N);

	for(int i = 0;i < N;i++)
		for(int j = 0;j < N;j++)
			scanf("%d", &dis[i][j]);

	memset(passed, 0, sizeof(passed));

	passed[0] = true;
	travel(0, 0, 0);

	printf("%d\n", best);

	return 0;
}