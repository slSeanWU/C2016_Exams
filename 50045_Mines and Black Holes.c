#include <stdio.h>
#include <stdlib.h>

int main(void){
	int x, y, z;
	int mx, my, mz, bx, by, bz;
	scanf("%d%d%d%d%d%d%d%d%d", &x, &y, &z, &mx, &my, &mz, &bx, &by, &bz);
	
	int n, cmd;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		int dis;
		scanf("%d", &cmd);
		
		switch(cmd){
			case 1:
				x += 1;
				break;
			case 2:
				x -= 1;
				break;
			case 3:
				y += 1;
				break;
			case 4:
				y -= 1;
				break;
			case 5:
				z += 1;
				break;
			case 6:
				z -= 1;
		}
		
		dis = abs(x-mx) + abs(y-my) + abs(z-mz);
		if(dis < 10)  break;
		dis = abs(x-bx) + abs(y-by) + abs(z-bz);
		if(dis < 10){
			x = bx, y = by, z = bz;
			bx = by = bz = 200;
		}
		
		if(i%5 == 0)
			printf("%d %d %d\n", x, y, z);
	}
	
	return 0;
}

