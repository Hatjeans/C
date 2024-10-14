#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int input;
	printf("Enter an integer :");
	scanf("%d",&input);
	
	if (input==0)
	{
		printf("This is zero");
		
	}
	
	else 
	{
		if (input >0)
		{
			printf("This is positive number");
		}
		
		else
		{
			printf("This is negative number");
		}
	}
	
	return 0;
}
