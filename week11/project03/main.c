#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	char src[] = "The worst thing is to eat before you sleep";
	char dst[100];
	
	dst[100] = strcpy(dst,src);
	
	printf("copied string : %s", dst);
	
	return 0;
}



