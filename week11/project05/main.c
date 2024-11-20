#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE* fp;
	char str1[100];
	char str2[100];
	char str3[100];

	printf("input a word : ");
	scanf("%s", str1);
	
		printf("input a word : ");
	scanf("%s", str2);
	
		printf("input a word : ");
	scanf("%s", str3);
	
	fp = fopen("sample.txt", "w");	
	fprintf(fp, "%s \n", str1);
	fprintf(fp, "%s \n", str2);
	fprintf(fp, "%s \n", str3);
	fclose(fp);
	
	return 0;
	
}
