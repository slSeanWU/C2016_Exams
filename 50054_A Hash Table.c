#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char table[1000][10000][102];
int count[1000] = {0};

int computeIndex(char s[], int Size){
	int len = strlen(s), ans = 0;
	
	for(int i = 0;i < len;i++){
		if( isdigit(s[i]) )
			ans += s[i]-'0';
		else if( isalpha(s[i]) )
			ans += s[i];
	}
	
	return ans%Size;
}

int main(void){
	int Size, N, Q;
	scanf("%d%d%d", &Size, &N, &Q);
	
	while(N--){
		char in[128];
		scanf("%s", in);
		
		int index = computeIndex(in, Size);
		
		strcpy( table[index][ count[index]++ ], in);
	}
	
	while(Q--){
		char query[128];
		scanf("%s", query);
		
		int index = computeIndex(query, Size);
		
		int check;
		for(check = 0;check < count[index];check++)
			if( !strcmp(query, table[index][check]) ){
				printf("%d\n", index);
				break;
			}
		
		if(check == count[index])
			printf("-1\n");
	}
	return 0;
}

