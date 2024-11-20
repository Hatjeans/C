#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *fp = NULL;
	fp = fopen("sample.txt", "r");
	char c;
	
	if (fp==NULL)
	printf("cannot open a file");
	
	while ( (c=fgetc(fp)) != EOF)
	{
		putchar(c);
	}
	
	fclose(fp);
	
	return 0;
}
