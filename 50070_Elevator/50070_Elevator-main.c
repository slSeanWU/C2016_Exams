#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elevator.h"

int main(void){
	int N;
	scanf("%d", &N);

	while(N--){
		int u, d, Max;
		scanf("%d %d %d", &u, &d, &Max);

		Elevator *game = newElevator(u, d, Max);

		char cmd[1536];
		scanf("%s", cmd);
		int len = strlen(cmd);

		for(int i = 0;i < len;i++){
			int status = (cmd[i] == 'U')? up(game):down(game);

			if(status == -1){
				puts("Broken");
				break;
			}
			else if(status == 0)
				puts("Invalid");
			else
				printf("Valid %d\n", getPosition(game));
		}

		for(int f = 1;f <= Max;f++)
			if( visited(game, f) )
				printf("%d\n", f);

		free(game);
	}

	return 0;
}