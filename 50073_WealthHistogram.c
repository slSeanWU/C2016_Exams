#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct{
	char name[12];
	int wealth;
}Person;
Person records[1024];

int cmp(const void *a, const void *b){
	Person *c = (Person *)a, *d = (Person *)b;

	if(c->wealth < d->wealth)  return -1;
	else if(c->wealth > d->wealth)  return 1;
	else  return strcmp(c->name, d->name);
}

int main(int argc, char const *argv[])
{
	FILE *fin = fopen(argv[1], "rb");
	assert(fin != NULL);

	int total = 0;
	while( fread(&records[total], sizeof(Person), 1, fin) == 1 )  total++;
	fclose(fin);
	qsort(records, total, sizeof(Person), cmp);

	int idx = 0;
	for(int seg = 1;seg < 2147484 && idx < total;seg++){
		int this = 0, bound = 1000*seg;

		while(records[idx].wealth < bound && idx < total)
			idx++, this++;
		seg = records[idx].wealth/1000;

		if(this > 0)  printf("%d\n", this);
	}
	if(idx < total) printf("%d\n", total-idx);

	printf("%s\n", records[0].name);

	idx = total-1;
	while( records[idx].wealth == records[total-1].wealth )  idx--;
	printf("%s\n", records[idx+1].name);

	if(total % 2)  printf("%d", records[total/2].wealth);
	else{
		long long w1 = records[total/2].wealth, w2 = records[total/2 - 1].wealth;
		printf("%d", (w1+w2) / 2);
	} 

	return 0;
}