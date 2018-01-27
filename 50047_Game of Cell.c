#include <stdio.h> 

int inside(int y, int x){
	if(y<0 || y>=50 || x<0 || x>=50)
		return 0;
	else
		return 1;
}

void game_of_cell(int grid[50][50],int outcome[50][50],int N){
	int gridB[50][50];
	int gox[] = {1, 0, -1, -1, -1, 0, 1, 1};
	int goy[] = {1, 1, 1, 0, -1, -1, -1, 0};
	
	for(int i = 1;i <= N;i++){
		if( i%2 == 1 ){
			
			for(int j = 0;j < 50;j++)
				for(int k = 0;k < 50;k++){
					int hCnt = 0;
						
					for(int p = 0;p < 8;p++)
						if( inside(j+goy[p], k+gox[p]) && grid[ j+goy[p] ][ k+gox[p] ] == 2)
							hCnt++;
					
					if(grid[j][k] == 2)			
						if(hCnt < 2)
							gridB[j][k] = 0;
						else if(hCnt == 2 || hCnt == 3)
							gridB[j][k] = 2;
						else
							gridB[j][k] = 1;
					
					else if(grid[j][k] == 1){
						if(hCnt == 2)
							gridB[j][k] = 2;
						else
							gridB[j][k] = 1;
					}
					
					else{
						if(hCnt == 3)
							gridB[j][k] = 2;
						else
							gridB[j][k] = 0;
					}
				}
		}
		
		else{
			
			for(int j = 0;j < 50;j++)
				for(int k = 0;k < 50;k++){
					int hCnt = 0;
						
					for(int p = 0;p < 8;p++)
						if( inside(j+goy[p], k+gox[p]) && gridB[ j+goy[p] ][ k+gox[p] ] == 2)
							hCnt++;
					
					if(gridB[j][k] == 2)			
						if(hCnt < 2)
							grid[j][k] = 0;
						else if(hCnt == 2 || hCnt == 3)
							grid[j][k] = 2;
						else
							grid[j][k] = 1;
					
					else if(gridB[j][k] == 1){
						if(hCnt == 2)
							grid[j][k] = 2;
						else
							grid[j][k] = 1;
					}
					
					else{
						if(hCnt == 3)
							grid[j][k] = 2;
						else
							grid[j][k] = 0;
					}
				}
		}
	}
	
	if(N%2 == 1)
		for(int i = 0;i < 50;i++)
			for(int j = 0;j < 50;j++)
				outcome[i][j] = gridB[i][j];
	else
		for(int i = 0;i < 50;i++)
			for(int j = 0;j < 50;j++)
				outcome[i][j] = grid[i][j];
	
	return;	
}

int main()
{
    int grid[50][50]={0},outcome[50][50]={0},N;
    scanf("%d",&N);
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            scanf("%d",&grid[i][j]);
    game_of_cell(grid,outcome,N);
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            printf("%d%c",outcome[i][j]," \n"[j==49]);
    return 0;
}
