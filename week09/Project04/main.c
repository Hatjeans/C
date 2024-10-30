#include <stdio.h>
#include <stdlib.h>

void sub(void);


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// autocount will reset at the begin of every loop
// staticcount will not reset and will last the latest count!

int main(int argc, char *argv[]) {
	
	int i;
	for(i=0;i<3;i++){
		sub();
	}
	
	return 0;
}

void sub (void){
	
	int auto_count = 0;
	static int static_count = 0;
	auto_count++;
	static_count++;
	
	printf("auto_count = %d \n", auto_count);
	printf("static_count = %d \n", static_count);
}
