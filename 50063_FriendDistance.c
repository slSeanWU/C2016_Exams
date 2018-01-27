#include <stdio.h>
#include <string.h>

#define MAX(a, b) (a>b)? a:b

int minMaxDis = 16, isFriend[16][16], N;
int ans[16], finalAns[16];

int findNewDis(int consider, int nowPos){
	for(int i = 0;i < nowPos;i++)
		if( isFriend[consider][ ans[i] ] )
			return nowPos-i;

	return 0;
}

void findAns(int pos, int maxdistance, unsigned int used){
	if(pos == N){
		if( maxdistance < minMaxDis ){
			minMaxDis = maxdistance;
			memcpy(finalAns, ans, N*sizeof(int));
		}

		return;
	}

	if( maxdistance >= minMaxDis )
		return;

	for(int i = 0;i < N;i++)
		if( !( (used>>i) & 1) ){
			int newDis = findNewDis(i, pos);

			ans[pos] = i;
			findAns(pos+1, MAX(newDis, maxdistance), used+(1<<i));
		}

	return;
}

int main(void){
	memset(isFriend, 0, sizeof(isFriend));

	int pairs;
	scanf("%d %d", &N, &pairs);
	while(pairs--){
		char pa[2], pb[2];
		scanf("%s %s", pa, pb);

		isFriend[ pa[0]-'A' ][ pb[0]-'A'] = isFriend[ pb[0]-'A'][ pa[0]-'A' ] = 1;
	}

	findAns(0, 0, 0);

	printf("%d\n%c", minMaxDis, finalAns[0]+'A');
	for(int i = 1;i < N;i++)
		printf(" %c", finalAns[i]+'A');

	return 0;
}