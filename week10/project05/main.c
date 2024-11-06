#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define CLOS 3

void addMatrix(int a[ROWS][CLOS], int b[ROWS][CLOS],int c[ROWS][CLOS]);
void printMatrix(int c[ROWS][CLOS]);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int A[ROWS][CLOS] = {
	{2,3,0},
	{8,9,1},
	{7,0,5}
	};
	
	int B[ROWS][CLOS] = {
	{1,0,0},
	{0,1,0},
	{0,0,1}
	};
	
	
	int C[ROWS][CLOS];
	
	addMatrix(A,B,C);
	printMatrix(C);
	
	return 0;
}

void addMatrix(int a[ROWS][CLOS], int b[ROWS][CLOS],int c[ROWS][CLOS]){
	
	int i,j;
	
	for (i=0;i<ROWS;i++){
		for(j=0;j<CLOS;j++){
			c [i][j] = a[i][j] + b[i][j];
	
					}
	}
	
}

void printMatrix(int c[ROWS][CLOS]){
	
	int i,j;
	
		for (i=0;i<ROWS;i++){
		for(j=0;j<CLOS;j++){
			printf("%3d ",c[i][j]);
					}
		printf("\n");
	}
}
