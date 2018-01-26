#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 

struct pos{
	short x, y;
};

int n, m;
bool wall(int x, int y){
	if(x<0 || x>=n || y<0 || y>=m)
		return true;
	else
		return false;
}

int main(void){
	scanf("%d%d", &n, &m);
	
	bool board[n+1][m+1];
	memset(board, false, sizeof(board));
	
	int sx, sy, ex, ey;
	scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
	int len = ( abs(ex-sx)>abs(ey-sy) )? abs(ex-sx)+1:abs(ey-sy)+1;
	
	int index = 0;
	struct pos body[len];
	struct pos tmp;
	if(sx != ex){
		if(sx > ex){
			for(int i = sx;i >= ex;i--){
				tmp.x = i;
				tmp.y = sy;
				body[index++] = tmp;
				board[i][sy] = true;
			}
		}
		else{
			for(int i = sx;i <= ex;i++){
				tmp.x = i;
				tmp.y = sy;
				body[index++] = tmp;
				board[i][sy] = true;
			}
		}
	}
	else{
		if(sy > ey){
			for(int i = sy;i >= ey;i--){
				tmp.x = sx;
				tmp.y = i;
				body[index++] = tmp;
				board[sx][i] = true;
			}
		}
		else{
			for(int i = sy;i <= ey;i++){
				tmp.x = sx;
				tmp.y = i;
				body[index++] = tmp;
				board[sx][i] = true;
			}
		}
	}
	
	short head_I = 0, tail_I = len-1;
	int q, cmd;
	scanf("%d", &q);
	
	while(q--){
		scanf("%d", &cmd);
		
		switch(cmd){
			case 0:
				tmp.x = body[head_I].x + 1;
				tmp.y = body[head_I].y;
				break;
			case 1:
				tmp.x = body[head_I].x - 1;
				tmp.y = body[head_I].y;
				break;
			case 2:
				tmp.x = body[head_I].x;
				tmp.y = body[head_I].y + 1;
				break;
			case 3:
				tmp.x = body[head_I].x;
				tmp.y = body[head_I].y - 1;
				break;
		}
		
		if( wall(tmp.x, tmp.y) ||
		  ( board[tmp.x][tmp.y] == 1 && (tmp.x != body[tail_I].x || tmp.y != body[tail_I].y) ) )
			break;
		
		board[ body[tail_I].x ][ body[tail_I].y ] = false;
		board[tmp.x][tmp.y] = true;
		body[tail_I] = tmp;
			
		head_I = tail_I;
		tail_I--;
		if(tail_I < 0)  tail_I = len-1;
	}
	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++)
			printf("%d", board[i][j]);
		
		printf("\n");
	}
		
	return 0;
}

