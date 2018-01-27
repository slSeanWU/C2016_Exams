#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hangman.h"

struct Hangman{
	char answer[128], current[128], alphabet[26];
	int len, maxWrong, curWrong;
};
typedef struct Hangman Hangman;
 
Hangman* newGame(char *answer, int G){
	Hangman *new = (Hangman *)malloc( sizeof(Hangman) );
	strcpy(new->answer, answer);
	new->len = strlen(answer);
	new->maxWrong = G, new->curWrong = 0;

	memset(new->current, '*', new->len);
	new->current[new->len] = '\0';
	memset(new->alphabet, 0, 26);

	for(int i = 0;i < new->len;i++)
		new->alphabet[ answer[i]-'a' ] = 1;

	return new;
}

int guess(Hangman* hangman, char ch){
	if( hangman->alphabet[ ch-'a' ] ){
		for(int i = 0;i < hangman->len;i++)
			if(ch == hangman->answer[i])
				hangman->current[i] = ch;

		return 1;
	}
	else{
		hangman->curWrong++;

		if(hangman->curWrong >= hangman->maxWrong)
			return -1;
		else
			return 0;
	}
}

void printStatus(Hangman* hangman){
	puts(hangman->current);
	return;
}

int solved(Hangman* hangman){
	if( !strcmp(hangman->current, hangman->answer) )
		return 1;
	else
		return 0;
}