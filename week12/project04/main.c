#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i;
	int grade[5];
	int *fp;
	int sum = 0;
	
	for (i=0;i<5;i++){
		printf("input value - grade[%d] = ", i);
		scanf("%d", &grade[i]);
	}
	
	fp = grade;
	
	for(i=0;i<5;i++){
		printf("grade[%d] = %d\n", i, fp[i]);
		sum += fp[i]; 
	}
	
	printf("the avergae is %.2f", sum/5.0);
	return 0;
}
