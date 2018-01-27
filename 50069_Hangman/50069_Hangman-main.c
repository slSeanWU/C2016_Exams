#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hangman.h"

int main(void){
	int N;
	scanf("%d", &N);

	while(N--){
		char answer[128];
		int maxGuess;

		scanf("%s %d", answer, &maxGuess);
		Hangman *game = newGame(answer, maxGuess);

		char guesses[256];
		scanf("%s", guesses);
		int rounds = strlen(guesses);

		for(int i = 0;i < rounds;i++){
			int status = guess(game, guesses[i]);

			printf("%d ", status);
			printStatus(game);

			if( solved(game) ){
				puts("You Win");
				break;
			}
			if( status == -1 ){
				puts("You Lose");
				break;
			}
			if( i == rounds-1 )
				puts("You Quit");
		}

		free(game);
	}

	return 0;
}