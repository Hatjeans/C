#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char *proverb = "All that glisters is not gold";
void setPointer(char **q);


int main(int argc, char *argv[]) {
	
	char *p = "zzz";
	setPointer(&p);
	printf("%s",p);
	
	return 0;
}

void setPointer(char **q){
	*q = proverb;
}

