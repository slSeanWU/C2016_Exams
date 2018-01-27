#include <stdio.h>
#include <stdlib.h>

void count_day(int year, int day, int month, int results[7]){
	int isL = 0;
	if( year%4 == 0 ){
		if( year%400 == 0 )
			isL = 1;
		else if( year%100 != 0 )
			isL = 1;
	}
	
	int plus[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	day += plus[ month-1 ];
	if(month > 2 && isL == 1)  day++;
	
	int md[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for(int i = 0;i < 7;i++)
		results[i] = 4;
		
	int index = day%7;
	
	for(int i = 0;i < md[month-1]-28;i++){
		results[index++]++;
		index %= 7;
	}
	if(month == 2 && isL == 1)
		results[index]++;
		
	return;
}
int main(){
    int year, day, month, results[7] = {0}, i;
 
    while(scanf("%d %d %d", &year, &day, &month) == 3){
        for(i = 0; i < 7; i++)
            results[i] = 0;
        count_day(year, day, month, results);
        for(i = 0; i < 6; i++)
            printf("%d ", results[i]);
        printf("%d\n", results[i]);
    }
    return 0;
}
