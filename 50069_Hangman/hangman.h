struct Hangman;
typedef struct Hangman Hangman;
 
Hangman* newGame(char *answer, int G);
int guess(Hangman* hangman, char ch);
void printStatus(Hangman* hangman);
int solved(Hangman* hangman);