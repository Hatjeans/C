//
//  board.c
//  sharkGame
//

#include "board.h"

// ----- EX. 3 : board ------------
#define N_COINPOS       12
#define MAX_COIN        4
// ----- EX. 3 : board ------------


// ----- EX. 5 : shark ------------
#define MAX_SHARKSTEP   6
#define SHARK_INITPOS   -4
// ----- EX. 5 : shark ------------


// ----- EX. 3 : board ------------
static int board_coin[N_BOARD];
static int board_status[N_BOARD]; //0 - OK, 1 - destroyed
// ----- EX. 3 : board ------------






static int shark_position;








// ----- EX. 3 : board ------------
void board_printBoardStatus(void)
{
    int i;
    
    printf("----------------------- BOARD STATUS -----------------------\n");
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (board_status[i] == BOARDSTATUS_NOK)
            printf("X");
        else
            printf("O");
    }
    printf("|\n");
    printf("------------------------------------------------------------\n");
}

int board_initBoard(void)
{
    int i;
    
    //variable initialization
    for (i=0;i<N_BOARD;i++)
    {
        board_status[i] = BOARDSTATUS_OK; // board_status의 i번째 요소 0설정
        board_coin[i] = 0; // board_coin의 i번째 요소 0설정 
    }
    
// ----- EX. 5 : shark ------------
    shark_position = SHARK_INITPOS;
// ----- EX. 5 : shark ------------

    //coin allocation
   for (i=0;i<N_COINPOS;i++) // 
   {
   		while (1) // 
   		{
   			
   			int randomPosition = rand() % N_BOARD; //동전 놓을 칸을 랜덤으로 지정  
   			
   			if(board_coin[randomPosition] == 0) // 칸에 이미 동전이 있지 않으면  
   			{
   				board_coin[randomPosition] = (rand() % MAX_COIN) +1 ; // i번째 코인 할당, board_coin[지정칸] = (1~MAX_COIN 중 랜덤) 
			   } 
			   
			
   		
   		break; // 
	   	}
   	
   }
    
    return N_COINPOS;
}
// ----- EX. 3 : board ------------










// ----- EX. 5 : shark ------------
int board_stepShark(void)
{
	int i; 
	int shark_step;
	
	shark_step = rand () % MAX_SHARKSTEP +1;
	
	shark_position += shark_step; 
	
	
	
	for (i=0;i<shark_position;i++)
    {
        board_status[i] = BOARDSTATUS_NOK; // 이동하는 경로에서 board_status 배열요소 변경 
    }
	
	
	
	return (shark_position); 

}
// ----- EX. 5 : shark ------------











// ----- EX. 3 : board ------------
int board_getBoardStatus(int pos)
{
	
    return board_status[pos];
}

int board_getBoardCoin(int pos)
{
    int coin = board_coin[pos];
    board_coin[pos] = 0;
    return coin;
}
// ----- EX. 3 : board ------------










