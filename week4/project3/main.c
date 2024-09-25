#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char character1, character2;
		
	printf("enter a character : ");
	scanf("%c", &character1 );
	
	printf("the next character of %c (%d) is %c (%d) ", character1, character1, character1 +1, character1 +1  );
	
	return 0;
}
