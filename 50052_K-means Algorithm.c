#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
 
 
int main(void){
    int N, L, R;
    scanf("%d%d%d", &N, &L, &R);
 
    char group[3][N][L+2], leader[3][L+2], strs[N][L+2];
    short count[3] = {0};
 
    // Get the Leaders (first round)
    for(int i = 0;i < 3;i++){
        scanf("%s", strs[i]);
        memcpy(leader[i], strs[i], L+1);
    }
 
    // Get the remaining strings
    for(int i = 3;i < N;i++)
        scanf("%s", strs[i]);
 
    while(R--){
        for(int i = 0;i < 3;i++){
            memcpy(group[i][0], leader[i], L+1);
            count[i] = 1;
        }
 
        // Step 1: Assign strings to Leaders
        char tmp[L+2];
        for(int i = 0;i < N;i++){
            memcpy(tmp, strs[i], L+1);
 
 			// Don't process the Leaders
            if( strcmp(tmp, leader[0]) == 0 || strcmp(tmp, leader[1]) == 0 || strcmp(tmp, leader[2]) == 0 )
                continue;
 
            int min = 20000000;
            int ans = -1, hold;
 
            for(int i = 0;i < 3;i++){
                hold = 0;
 
                for(int j = 0;j < L;j++)
                    hold += abs(tmp[j] - leader[i][j]);
 
                if(hold < min){
                    min = hold;
                    ans = i;
                }
                else if(hold == min){
                    if( strcmp(leader[i], leader[ans]) < 0 )
                        ans = i;
                }
            }
 
            memcpy(group[ans][ count[ans]++ ], tmp, L+1); 
        }
 
        // Step 2: Calculate the mean
        int mean[3][L], sum;
        for(int i = 0;i < 3;i++)
            for(int j = 0;j < L;j++){
                sum = 0;
 
                for(int k = 0;k < count[i];k++)
                    sum += (int)group[i][k][j];
 
                mean[i][j] = sum/count[i];
            }
 
        // Step 3: Determine the new Leader
        for(int i = 0;i < 3;i++){
            int next = -1, min = 20000000;
 
            for(int j = 0;j < count[i];j++){
                int diff = 0;
 
                for(int k = 0;k < L;k++)
                    diff += abs( group[i][j][k] - mean[i][k] );
 
                if(diff < min){
                    next = j;
                    min = diff;
                }
                else if(diff == min && strcmp(group[i][j], group[i][next]) < 0 )
                    next = j;
            }
 
            memcpy(leader[i], group[i][next], L+1);
        }        
    }
 
    // Bubble-sort the Leaders
    for(int i = 1;i >= 0;i--){
        for(int j = 0;j <= i;j++)
            if( strcmp(leader[j], leader[j+1]) > 0 ){
                char tmp[L+2];
 
                memcpy(tmp, leader[j], L+1);
                memcpy(leader[j], leader[j+1], L+1);
                memcpy(leader[j+1], tmp, L+1);
            }
    }
 
    for(int i = 0;i < 3;i++)
        printf("%s\n", leader[i]);
 
    return 0;
}