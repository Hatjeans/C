#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	int input;
	int result=0;
	int i;
	
	printf("Enter a number: ");
	scanf("%d", &input);
	
	for(i=0;i<=input;i++)
	{
		result += i;
	}
	
	
	printf("The result is %d", result);
	
	
	
	
	return 0;
}
