#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

#define INT_MAX 2147483647

int N, M;
typedef struct{
	int x, y;
}Coord;
Coord attractions[65536];

int BoundaryDistance(int x, int y, int *dir){
	int ret = INT_MAX;

	if( y < ret )
		*dir = 0, ret = y;
	if( ( (N-1)-x ) < ret )
		*dir = 1, ret = (N-1)-x;
	if( ( (N-1)-y ) < ret )
		*dir = 2, ret = (N-1)-y;
	if( x < ret )
		*dir = 3, ret = x;

	return ret;
}

int Order(const void *a, const void *b){
	Coord *c = (Coord *)a, *d = (Coord *)b;
	int cDirection, dDirection;

	int cDis = BoundaryDistance(c->x, c->y, &cDirection);
	int dDis = BoundaryDistance(d->x, d->y, &dDirection);

	if(cDis < dDis)	      return -1;
	else if(cDis > dDis)  return 1;
	else if(cDirection < dDirection)  return -1;
	else if(cDirection > dDirection)  return 1;

	// cDirection == dDirection
	if(cDirection == 0){
		if(c->x < d->x)	 return -1;
		else             return 1;
	}
	else if(cDirection == 1){
		if(c->y < d->y)	 return -1;
		else             return 1;
	}
	else if(cDirection == 2){
		if(c->x > d->x)	 return -1;
		else             return 1;
	}
	else{
		if(c->y > d->y)	 return -1;
		else             return 1;
	}
}

int main(int argc, char const *argv[])
{
	FILE *data = fopen(argv[1], "rb");
	assert(data != NULL);

	scanf("%d %d", &N, &M);
	for(int i = 0;i < M;i++)
		fread(&attractions[i], sizeof(Coord), 1, data);

	qsort(attractions, M, sizeof(Coord), Order);

	for(int i = 0;i < M;i++)
		printf("%d %d\n", attractions[i].x, attractions[i].y);

	fclose(data);
	
	return 0;
}