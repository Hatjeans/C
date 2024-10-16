#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


	
	int sumTwo (int a, int b);
	int square (int n);
	int get_max (int x, int y);


int main(int argc, char *argv[]) {
	
	int input1, input2;
	
	
	printf("Enter the integers : ");
	scanf("%d %d",&input1, &input2);
	
	printf("result -> Sum : %d square : %d Max : %d", sumTwo(input1, input2), square(input1), get_max(input1, input2));
	
	return 0;
}


	
	int sumTwo (int a, int b)
	{
		return a+b;
	}
	int square (int n)
	{
		return n*n;
		
	}
	int get_max (int x, int y)
	{
		int bigger;
		
		if (x>y)
		bigger = x;
		else 
		bigger = y;
		
		return bigger;
		
	}


