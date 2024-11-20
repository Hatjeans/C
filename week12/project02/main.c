#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i = 300;
	int *pi = &i;
	char *pc = &i;
	
	printf("%d %d %d",i, *pi, *pc); // i =4; 444 i = 300; 300300 44
	return 0;
}
