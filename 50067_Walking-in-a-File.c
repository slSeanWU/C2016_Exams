#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

int Exit = 0;

void command(int type, FILE *fin){
	int toPrint, Ignore, para;

	switch(type){
		case 0:
			fread(&toPrint, sizeof(int), 1, fin);
			printf("%d", toPrint);
			break;

		case 1:
			for(int i = 0;i < 4;i++){
				char show;
				fread(&show, sizeof(char), 1, fin);
				printf("%c", show);
			}
			break;

		case 2:
			fread(&Ignore, sizeof(int), 1, fin);
			char str;
			while( fread(&str, sizeof(char), 1, fin) && str != '\0' )
				printf("%c", str);
			break;

		case 3:
			fread(&para, sizeof(int), 1, fin);
			fseek(fin, para-8, SEEK_CUR);
			break;
		case 4:
			fread(&para, sizeof(int), 1, fin);
			fseek(fin, para, SEEK_SET);
			break;
		case 5:
			fread(&para, sizeof(int), 1, fin);
			fseek(fin, para, SEEK_END);
			break;

		default:
			printf("Seek end");
			Exit = 1;
	}

	return;
}

int main(void){
	char name[16];
	scanf("%s", name);

	FILE *fin = fopen(name, "rb");
	assert( fin != NULL );

	int type;
	while( fread(&type, sizeof(int), 1, fin) == 1 && !Exit )
		command(type, fin);

	fclose(fin);

	return 0;
}