#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct point{
	int x;
	int y;
	
};

int getArea (struct point p1, struct point p2);

int main(int argc, char *argv[]) {
	
	struct point p1, p2;
	int absoluteArea;
	
	
	printf("input the coordinate p1 (x,y) : ");
	scanf("%d %d", &p1.x, &p1.y);
	
	printf("input the coordinate p2 (x,y) : ");
	scanf("%d %d", &p2.x, &p2.y);
	
	absoluteArea = getArea(p1,p2);
	
	if (getArea(p1,p2) < 0){ 
	absoluteArea = - getArea(p1,p2);
	}
	
	printf("Area = %d", absoluteArea );
	return 0;
}

int getArea (struct point p1, struct point p2){
	
	return (p1.x-p2.x)*(p1.y-p2.y);
	
}

