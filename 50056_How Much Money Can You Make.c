#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ig{
	char name[64];
	int amount, unitPrice;
};

int main(void){
	int igC, prC;
	scanf("%d%d", &igC, &prC);
	
	struct ig ingre[igC];
	for(int i = 0;i < igC;i++)
		scanf("%s %d %d", ingre[i].name, &(ingre[i].amount), &(ingre[i].unitPrice));
		
	int maxPro = 0;
	char toMake[64];
	while(prC--){
		char food[64];
		int igNeed;
		scanf("%s %d", food, &igNeed);
		
		int igData[100] = {0};
		int produceable = 0x6f6f6f6f;
		while(igNeed--){
			char igName[64];
			int needed;
			scanf("%s %d", igName, &needed);
			
			for(int i = 0;i < igC;i++)
				if( strcmp(igName, ingre[i].name) == 0 ){
					igData[i] = needed;
					
					if( (ingre[i].amount/needed) < produceable )
						produceable = ingre[i].amount/needed;
						
					break;
				}
		}
		
		int totalCost = 0;
		for(int i = 0;i < igC;i++)
			if( igData[i] > 0 )
				totalCost += produceable*ingre[i].unitPrice*igData[i];
				
		int Profit = 0, sellPrice;
		scanf("%d", &sellPrice);
		Profit = sellPrice*produceable - totalCost;
		
		if(Profit > maxPro){
			maxPro = Profit;
			strcpy(toMake, food);
		}
		else if( (Profit == maxPro) && strcmp(food, toMake) < 0 )
			strcpy(toMake, food);
	}
	
	printf("%s %d", toMake, maxPro);
	
	return 0;
}

