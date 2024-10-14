#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int number=0;
	char input;
	
	
	printf("Input a string:");
	
	while ((input=getchar()) !='\n')
	{
		if (48<=input)
		{
			if(input<=57)
			{
				number++;
			}
		}
	}
	
	printf("The number of digits is %d",number);
	
	return 0;
}
