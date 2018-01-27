#include <stdio.h>
#include <assert.h>
#define MAXN 100

typedef struct{
    int x, y;
    int g;
} CarStatus;
 
typedef struct{
    int t, v;
} Command;
 
typedef struct{
    int num;
    CarStatus status[MAXN];
} CarStatusList;

int gox[] = {1, -1, 0, 0};
int goy[] = {0, 0, 1, -1};

CarStatusList carSimulation(CarStatus car, Command commands[]){
    CarStatusList list;
    list.num = 0;

    CarStatus tmp;
    tmp.x = car.x;
    tmp.y = car.y;
    tmp.g = car.g;

    int fuelHold = car.g;

    for(int i = 0;commands[i].t != 0;i++){
        if(commands[i].t == 1)
            fuelHold += commands[i].v;

        else{
            if(fuelHold - commands[i].v < 0)
                break;

            int nowAt = list.num, prev = list.num-1;
            int cmd = commands[i].t-2, incre = commands[i].v;
            fuelHold -= incre;

            list.status[nowAt].x = tmp.x + gox[cmd]*incre;
            list.status[nowAt].y = tmp.y + goy[cmd]*incre;
            list.status[nowAt].g = fuelHold;

            list.num++;
            tmp = list.status[nowAt];
        }
    }

    return list;
}

int main(){
    int N;
    CarStatus car;
    Command commands[MAXN];
 
    assert(scanf("%d%d%d", &car.x, &car.y, &car.g) == 3);
    assert(scanf("%d", &N) == 1);
    for(int i = 0; i < N; i++)
        assert(scanf("%d%d", &commands[i].t, &commands[i].v) == 2);
 
    CarStatusList result= carSimulation(car, commands);
 
    for(int i = 0; i < result.num; i++)
        printf("%d %d %d\n", result.status[i].x, result.status[i].y, result.status[i].g);
 
    return 0;
}