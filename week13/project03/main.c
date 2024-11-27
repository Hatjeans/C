#include <stdio.h>
#include <stdlib.h>
#define STUDENTNUM 4
#define STUDENTNUMF 4.0
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct student {
	int ID;
	int score;
	
};


int main(int argc, char *argv[]) {
	
	int i;
	struct student s[STUDENTNUM];
	int sum = 0;
	double avg;
	int maxID = 0;
	int maxScore =0 ;
	
	
	
	
	
	for(i=0;i<STUDENTNUM;i++){
		
		printf("enter the ID : ");
		scanf("%i", &s[i].ID);
		
		printf("enter the score : ");
		scanf("%i", &s[i].score);
		
		printf("\n");
		
		sum += s[i].score;
		
		
	}
	
	avg =  sum/STUDENTNUMF; // calculate the average
	
	maxID = s[0].ID;
	maxScore = s[0].score;
	
	for (i=1;i<STUDENTNUM;i++){
		if (s[i].score>maxScore){
			maxID = s[i].ID;
			maxScore = s[i].score;
		}
	}
	
	
	
	printf("the average of the students is %f \n", avg);
	printf("the maxium score and the student who got the maxium score is %d and %d ", maxID, maxScore);

	return 0;
}
