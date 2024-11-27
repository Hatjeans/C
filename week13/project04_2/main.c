#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct point{
	int x;
	int y;
	
};

int getArea (struct point *pPtr1, struct point *pPtr2);

int main(int argc, char *argv[]) {
	
	struct point p1, p2;
	struct point *pPtr1 = &p1, *pPtr2 = &p2;
	int absoluteArea;
	
	
	printf("input the coordinate p1 (x,y) : ");
	scanf("%d %d", &p1.x, &p1.y);
	
	printf("input the coordinate p2 (x,y) : ");
	scanf("%d %d", &p2.x, &p2.y);
	
	absoluteArea = getArea(pPtr1, pPtr2);
	
	if (getArea(pPtr1,pPtr2) < 0){ 
	absoluteArea = - getArea(pPtr1, pPtr2);
	}
	
	printf("Area = %d", absoluteArea );
	return 0;
}

int getArea (struct point *pPtr1, struct point *pPtr2){
	
	return (pPtr1->x - pPtr2->x)*(pPtr1->y -pPtr2->y);
	
}

