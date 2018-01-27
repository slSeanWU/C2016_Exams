#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elevator.h"

struct Elevator{
	int inv; 
	char lastinvCMD;
	int up, down, max;
	int cur;
	char vis[1024];
};
typedef struct Elevator Elevator;
 
Elevator* newElevator(int u, int d, int F){
	Elevator *new = (Elevator *)malloc( sizeof(Elevator) );

	new->inv = 0, new->cur = 1;
	new->up = u, new->down = d, new->max = F;
	memset(new->vis, 0, 1024);
	new->vis[1] = 1;
	new->lastinvCMD = '\0';

	return new;
}

int up(Elevator* elevator){
	if( elevator->cur + elevator->up <= elevator->max ){
		elevator->inv = 0;
		elevator->cur += elevator->up;
		elevator->vis[ elevator->cur ] = 1;

		return 1;
	}
	else{
		if('U' == elevator->lastinvCMD )
			elevator->inv++;
		else{
			elevator->inv = 1,
			elevator->lastinvCMD = 'U';
		}

		if( elevator->inv >= 4 )
			return -1;
		else
			return 0;
	}
}

int down(Elevator* elevator){
	if( elevator->cur - elevator->down >= 1 ){
		elevator->inv = 0;
		elevator->cur -= elevator->down;
		elevator->vis[ elevator->cur ] = 1;

		return 1;
	}
	else{
		if('D' == elevator->lastinvCMD )
			elevator->inv++;
		else{
			elevator->inv = 1,
			elevator->lastinvCMD = 'D';
		}

		if( elevator->inv >= 4 )
			return -1;
		else
			return 0;
	}
}

int visited(Elevator* elevator, int floor){
	if( elevator->vis[floor] )
		return 1;
	else
		return 0;
}

int getPosition(Elevator* elevator){
	return elevator->cur;
}