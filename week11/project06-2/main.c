#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *fp;
	char word[100];
	
	fp = fopen("sample.txt","r");
	
	if (fp == NULL)
	printf("cannot open a file");
	
	while(fscanf(fp,"%s",word) != EOF)
	{
		printf("%s \n", word);
	}
	
	fclose(fp);
	
	return 0;
}
