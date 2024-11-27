#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct point{
	int x;
	int y;
	
};


int main(int argc, char *argv[]) {
	
	struct point p1, p2;
	int xdiff, ydiff;
	float dist;
	
	printf("input p1 doordinate (x,y) : ");
	scanf("%d %d", &p1.x, &p1.y);
	
	printf("input p2 coordinate (x, y) : ");
	scanf("%d %d", &p2.x, &p2.y);
	
	xdiff = p1.x - p2.x;
	ydiff = p1.y - p2.y;
	
	dist = sqrt((xdiff*xdiff)+(ydiff*ydiff));
	
	printf("distnace : %f", dist);

	
	return 0;
}
