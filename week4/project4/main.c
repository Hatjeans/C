#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	float integer1, integer2;
	
	
	printf("enter two integers : ");
	scanf("%f %f", &integer1, &integer2);
	
	printf(" %f / %f = %f", integer1, integer2, integer1 / integer2 );
	
	
	return 0;
}
