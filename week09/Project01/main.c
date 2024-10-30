#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int flag = 1;
	while (flag !=0)
	{
		int y;
		y=3;
		
		flag = 0; // y is local variable so, y is only valid in block 
		
		y=4;
	}
	

	
	return 0;
}
