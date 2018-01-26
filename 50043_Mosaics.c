#include <stdio.h>
#include <stdlib.h>

int main(void){
	int x1, y1, x2, y2, x3, y3;
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	
	if( (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1) < 0){
		int tmpx, tmpy;
		tmpx = x2, tmpy = y2;
		x2 = x3, y2 = y3;
		x3 = tmpx, y3 = tmpy;
	}
	
	int Xmax, Xmin, Ymax, Ymin;
	Xmax = (x1 >= x2 && x1 >= x3)? x1:( ( x2 >= x3 )? x2:x3);
	Ymax = (y1 >= y2 && y1 >= y3)? y1:( ( y2 >= y3 )? y2:y3);
	Xmin = (x1 <= x2 && x1 <= x3)? x1:( ( x2 <= x3 )? x2:x3);
	Ymin = (y1 <= y2 && y1 <= y3)? y1:( ( y2 <= y3 )? y2:y3);
	
	int ans = 0;
	for(int i = Xmin;i < Xmax;i++)
		for(int j = Ymin;j < Ymax;j++){
			for(int c = 0;c < 4;c++){
				int cx, cy;
				
				if(c == 0)
					cx = i, cy = j;
				else if(c == 1)
					cx = i+1, cy = j;
				else if(c == 2)
					cx = i, cy = j+1;
				else
					cx = i+1, cy = j+1;
					
				int c1, c2, c3;
				c1 = (x1-cx)*(y2-cy) - (x2-cx)*(y1-cy);
				c2 = (x2-cx)*(y3-cy) - (x3-cx)*(y2-cy);
				c3 = (x3-cx)*(y1-cy) - (x1-cx)*(y3-cy);
				
				if( !(c1>=0 && c2>=0 && c3>=0) )  break;
				
				if(c == 3)  ans++;
			}
		}
		
		
	printf("%d", ans);
	
	return 0;
}

