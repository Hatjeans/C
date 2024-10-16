#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void print_star();


int main(int argc, char *argv[]) {
	

		
	print_star();
	print_star();
	print_star();
	
	return 0;
}

void print_star(){
		
	int i;
	for(i=0;i<10;i++)
		printf("*");
	
}
