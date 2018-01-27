#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(void){
	char in[10];
	char vl1[30][10], vl2[30][10];
	int vl1_c = 0, vl2_c = 0;
	
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%s", in);
		
		// get rid of No-hyphen or Hyphen-in-wrong-place cases
		if( in[2] != '-' && in[3] != '-' )
			continue;
			
		int digit_sum = 0;
		bool invalid = 0, digitA = 0;
		short appear[128] = {0};
		for(int k = 0;k < 7;k++){
			if( !(isalnum(in[k])) && in[k] != '-'){
				invalid = true;
				break;
			}
			
			if(isdigit(in[k])){
				digit_sum += in[k]-'0';
				digitA = true;
				
				if(in[k] == '4' && in[k+1] == '4'){
					invalid = true;
					break;
				}
			}
				
			if( appear[ in[k] ] == 2 || (in[k] == '-' && appear[ (int)'-' ])){
				invalid = true;
				break;
			}
			else
				appear[ in[k] ]++;
		}
		
		if( digitA == false || digit_sum%7 == 0 )
			invalid = true;
			
		if(invalid)
			continue;
		else{
			if(in[2] == '-')
				memcpy(vl1[ vl1_c++ ], in, 8);
			else
				memcpy(vl2[ vl2_c++ ], in, 8);
		}
	}
	
	char tmp[10];	
	for(int i = vl1_c-2;i >= 0;i--){
		for(int j = 0;j <= i;j++)
			if( strcmp(vl1[j], vl1[j+1]) > 0 ){
				memcpy(tmp, vl1[j], 8);
				memcpy(vl1[j], vl1[j+1], 8);
				memcpy(vl1[j+1], tmp, 8);
			}
	}
	
	for(int i = vl2_c-2;i >= 0;i--){
		for(int j = 0;j <= i;j++)
			if( strcmp(vl2[j], vl2[j+1]) > 0 ){
				memcpy(tmp, vl2[j], 8);
				memcpy(vl2[j], vl2[j+1], 8);
				memcpy(vl2[j+1], tmp, 8);
			}
	}
	
   	for(int i = 0;i < vl1_c;i++)
		printf("%s\n", vl1[i]);
	for(int i = 0;i < vl2_c;i++)
		printf("%s\n", vl2[i]);	
		
	return 0;
}