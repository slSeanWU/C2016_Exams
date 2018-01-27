#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
	char name[56];
	char books[100][56];
	int bookNum, sell;
};

int main(void){
	int N;
	scanf("%d", &N);
	
	struct data author[N];
	for(int i = 0;i < N;i++)
		author[i].sell = 0;
		
	int authNum = 0;
	for(int i = 0;i < N;i++){
		char aName[56], bName[56];
		scanf("%s%s", aName, bName);
		
		int searchA;
		for(searchA = 0;searchA < authNum;searchA++)
			if( !strcmp(aName, author[ searchA ].name) )
				strcpy(author[ searchA ].books[ author[ searchA ].bookNum++ ], bName);
				
		if(searchA == authNum){
			strcpy(author[ authNum ].name, aName);
			strcpy(author[ authNum ].books[0], bName);
			author[ authNum ].bookNum = 1;
			authNum++;
		}
	}
	
	int bestA = -1, maxsell = 0;
	while(N--){
		char bName[56];
		int sell;
		scanf("%s%d", bName, &sell);
		
		int found = 0;
		for(int i = 0;i < authNum && !found;i++){
			for(int j = 0;j < author[i].bookNum && !found;j++)
				if( !strcmp(bName, author[i].books[j]) ){
					author[i].sell += sell;
					
					if(author[i].sell > maxsell)
						bestA = i, maxsell = author[i].sell;
					else if(author[i].sell == maxsell && 
							strcmp(author[i].name, author[bestA].name) < 0)
						bestA = i;
						
					found = 1;
				}
		}
	}
	
	printf("%s %d", author[bestA].name, author[bestA].sell);
	
	return 0;
}

