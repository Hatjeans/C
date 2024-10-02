#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	int a=0;
	
	int result=0;
	
	printf("Input the year : ");
	scanf("%d",&a);
	
	
	result = ( ((a%4) == 0)&&((a%100) != 0) ) || ( (a%400) == 0 );
	
	
	printf("Is the year %d the leap year? : %d",a,result);
	
	
	return 0;
}
