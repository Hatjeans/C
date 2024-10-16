#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void square(int a);


int main(int argc, char *argv[]) {
	
	
	int a =2;
	square(a);
	printf("a=%d\n",a);
	
	return 0;
}

void square(int a){
	a = a*a;
}


/*
int square2(int a);


int main(int argc, char *argv[]) {
	
	a= square2(a);
	printf("a =%d\n",a);
	
	return 0;
}

int square2(int a){
	return (a*a);
}

*/

