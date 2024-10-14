#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int number1, number2;
	char op;
	int result;	
	double result_1;
	
	printf("Enter the calculation :");
	scanf("%d %c %d",&number1,&op,&number2);
	
	
	switch (op)
	{
		case '+':
			result = number1 + number2;
				printf("\n= %d", result);

			break;
		
		case '-':
			result = number1 - number2;
				printf("\n= %d", result);

			break;
			
		case '*':
			result = number1*number2;
				printf("\n= %d", result);

			break;
			
		case '/':
			result_1 = (double)number1/number2;
				printf("\n= %f", result_1);

			break;
			
	}
	
	
	return 0;
}
