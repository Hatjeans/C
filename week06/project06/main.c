#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int answer = 50;
	int input;
	int i;
	
	
	do{
	
	printf("Guess the number! : ");
	scanf("%d", &input);
	
	if (input>answer)
	{
		printf("Down\n");
		
	}
	
	if (input<answer)
	{
		printf("Up\n");
	}
	
	
	i++;
	
	
}while((input>answer)||(input<answer));
	
	printf("\nCongrats! Trials : %d", i);
	
	
	
	return 0;
}
