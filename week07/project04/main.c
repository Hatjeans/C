#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int combination (int n, int r);
int factorial (int n);
int get_integer();


int main(int argc, char *argv[]) {
	
	int x, y;
	int n;
	
	
	x = get_integer();
	
	y = get_integer();
	
	combination(x,y);
	
	printf("The result of C(%d,%d) is %d",x,y,combination(x,y));
	
	
	return 0;
}



int combination (int n, int r){
	
	return ((factorial(n))/(factorial(n-r)*factorial(r)));
	
}

int factorial (int n)
{
	int res = 1;
	int i;
	
	for(i=1;i<=n;i++)
		res *=i;
		
	return res;
	
}

int get_integer(){
	
	int input;
	printf("Enter the vaule :");
	scanf("%d",&input);
	return input;
}

