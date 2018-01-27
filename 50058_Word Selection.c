#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char word[20][64];
int cost[20], len[20], N;
int minCost = 2147483647;

int rec[26] = {0};

void compute(int included, int nowCost, int step){
	if(included == 26){
		if(nowCost < minCost)
			minCost = nowCost;
			
		return;
	}
	
	if(step == N)
		return;
	
	int newAlpha = 0;
	for(int i = 0;i < len[step];i++){
		if( !rec[ word[step][i]-'a' ] )
			newAlpha++;
			
		rec[ word[step][i]-'a' ]++;
	}
	
	compute(included+newAlpha, nowCost+cost[step], step+1);
	
	for(int i = 0;i < len[step];i++)
		rec[ word[step][i]-'a' ]--;
		
	compute(included, nowCost, step+1);	
	
	return;
}

int main(void){
	scanf("%d", &N);
	
	for(int i = 0;i < N;i++){
		scanf("%s %d", word[i], &cost[i]);
		len[i] = strlen(word[i]);
	}
	
	compute(0, 0, 0);
	
	printf("%d", minCost);
	
	return 0;
}

