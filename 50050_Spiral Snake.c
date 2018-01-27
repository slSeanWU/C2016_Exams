#include <stdio.h>
#include <assert.h>
 
#define MAXLEN 1000
 
static int snake[MAXLEN*MAXLEN];
static int result[MAXLEN*MAXLEN];

void SpiralSnake(int N, int *snake, int *result){
	const int move[] = {-1, -N, 1, N};
	int snI = 0, reI = (N*N)/2, turnStep = 1, cmd = 0;
	
	while(snI < N*N){
		for(int i = 0;i < turnStep && snI < N*N;i++){
			result[reI] = snake[snI++];
			reI += move[cmd];
		}
		
		if( cmd%2 == 1 )  
			turnStep++;
		cmd++, cmd %= 4;
	}
	
	return;
}

// main function provided for testing
int main(){
    int N;
    while(scanf("%d", &N)!=EOF){
        for(int i=0; i<N*N; i++)
              assert(scanf("%d", &snake[i])==1);
        SpiralSnake(N, snake, result);
        for(int i=0; i<N*N; i++)
             printf("%d%c", result[i], " \n"[i==N*N-1]);
    }
    return 0;
}
