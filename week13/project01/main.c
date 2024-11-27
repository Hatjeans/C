#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct student {
	int ID;
	char name[100];
	double grade;
	
};


int main(int argc, char *argv[]) {
	
	struct student s1 = {24, "Eunju", 4.3	};
	
	s1.ID = 2413732;
	s1.grade = 4.22;
	strcpy(s1.name, "HAEJIN");
	
		
	
	printf("ID : %d\n", s1.ID);
	printf("name : %s\n", s1.name);
	printf("grade : %f\n", s1.grade);

	
	
	
	return 0;
}
