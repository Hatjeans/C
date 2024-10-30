#include <stdio.h>
#include <stdlib.h>


int all_files;

extern void sub();

int main(int argc, char *argv[]) {
	
	sub();
	printf("%d \n", all_files);
	
	return 0;
}


