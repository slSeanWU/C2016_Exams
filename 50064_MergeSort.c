#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

int main(void){
	char filename[16];
	int hold[16], ended[16] = {0}, remaining, N;
	FILE *fin[16];

	scanf("%d", &N);
	remaining = N;

	for(int i = 0;i < N;i++){
		scanf("%s", filename);

		fin[i] = fopen(filename, "rb");
		assert( fin[i] != NULL );

		int success = fread(&hold[i], sizeof(int), 1, fin[i]);
		if( !success )
			ended[i] = 1, remaining--;
	}

	do{
		int min = 2147483647, minIndex = -1;

		for(int i = 0;i < N;i++)
			if( !ended[i] && hold[i] < min )
				min = hold[i], minIndex = i;

		printf("%d\n", min);

		int success = fread(&hold[minIndex], sizeof(int), 1, fin[minIndex]);
		if( !success )
			ended[minIndex] = 1, remaining--;
		
	} while(remaining);

	for(int i = 0;i < N;i++)
		fclose(fin[i]);

	return 0;
}