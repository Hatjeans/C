#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char *pc;
	int *pi;
	double *pd;
	
	pc = (char*)10000;
	pi = (int*)10000;
	pd = (double*)10000;
	
	printf("before addition : pc = %d pi = %d pd %d \n", pc, pi, pd);
	
	pc++;
	pi++;
	pd++;
	printf("after addtion : pc = %d pi = %d pd = %d", pc,pi,pd); // +1byte, +4byte, +8byte
	
	
	
	
	
	
	return 0;
}
