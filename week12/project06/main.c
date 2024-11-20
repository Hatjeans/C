#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i = 100;
	int *p = &i;
	int **q = &p;
	
	*p = 200;
	printf("i = %d *p = %d **q = %d \n", i, *p, **q); // changed the value of *p, and **q = *(p) = 200 so 200 200 200
	
	**q = 300;
	printf("i = %d *p = %d **q = %d", i, *p, **q);  // changed the vaule of **q -> 300 300 300
	
	return 0;
}
