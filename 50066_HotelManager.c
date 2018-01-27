#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct RoomStatus {
    int capacity;
    struct Reservation *reservation;
} RoomStatus;
 
typedef struct Reservation {
    int nP;
    int StartTime;
    int EndTime;
    struct Reservation *next;
} Reservation;

int suitable(RoomStatus list[], int now, int nP, int StartTime, int EndTime){
	Reservation *ptr = list[now].reservation, *prev = NULL;

	while( ptr != NULL ){
		if( ( StartTime >= ptr->StartTime && StartTime < ptr->EndTime ) ||
		    ( EndTime > ptr->StartTime && EndTime <= ptr->EndTime) ||
		    ( StartTime < ptr->StartTime && EndTime > ptr->EndTime ) )
		    return 0;

		if( EndTime <= ptr->StartTime )
			break;

		prev = ptr;
		ptr = ptr->next;
	}

	Reservation *new = (Reservation *)malloc( sizeof(Reservation) );
	new->nP = nP, new->StartTime = StartTime, new->EndTime = EndTime;

	new->next = ptr;
	if(prev == NULL)
		list[now].reservation = new;
	else
		prev->next = new;

	return 1;
}
 
int ReserveRoom(RoomStatus list[], int n, int nP, int StartTime, int EndTime){
	for(int i = 0;i < n;i++)
		if(nP <= list[i].capacity)
			if( suitable(list, i, nP, StartTime, EndTime) )
				return 1;

	return 0;
}

int main(){
    int n = 3;
    RoomStatus list[n];
    for(int i=0; i < n; i++){
        list[i].capacity = i+2;
        list[i].reservation = NULL;
    }

    int nP, sTime, eTime;
    while(scanf("%d %d %d", &nP, &sTime, &eTime)!=EOF)
        printf("%d", ReserveRoom(list, n, nP, sTime, eTime));
    puts("");
    printf("---Room Status List---\n");
    for(int i=0; i<n; i++){
        printf("%d ---", list[i].capacity);
        for(Reservation *tmp = list[i].reservation; tmp!=NULL; tmp=tmp->next)
            printf("->(%d:%d, %d)", tmp->nP, tmp->StartTime, tmp->EndTime);
        puts("");
    }

    printf("---      End       ---\n");
    return 0;
}