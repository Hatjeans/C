//
//  main.c
//  sharkGame
//
#include <stdio.h>
// ----- EX. 1 : Preparation------------
#include <stdlib.h>
#include <time.h>
// ----- EX. 1 : Preparation------------
#include "board.h"
// ----- EX. 4 : player ------------
#define N_PLAYER            3
// ----- EX. 4 : player ------------
#define MAX_CHARNAME        200
// ----- EX. 3 : board ------------
#define MAX_DIE             6
// ----- EX. 4 : player ------------
#define PLAYERSTATUS_LIVE   0
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2
int player_position[N_PLAYER]; // ��ġ  
char player_name[N_PLAYER][MAX_CHARNAME]; // �̸�  
int player_coin[N_PLAYER]; // ���� ���μ�  
int player_status[N_PLAYER]; //0 - live, 1 - die, 2 - end , ���� ����  
char player_statusString[3][MAX_CHARNAME] = {"LIVE", "DIE", "END"}; // ���� ���� ���ڿ� 





 // ��� END�ε� ���� ������ ���� ���, ���� ���� ������ �˾Ƴ�������  ī��Ʈ �ϱ� ����  
int theOrderofEND [N_PLAYER] = {-1,-1,-1};  // ī��Ʈ�� �ε����� �Ͽ� ���� ������� �÷��̾��� �ε����� ����  




// ----- EX. 4 : player ------------
// ----- EX. 3 : board ------------
int rolldie(void)
{
    return rand()%MAX_DIE+1;
}
// ----- EX. 3 : board ------------
// ----- EX. 1 : Preparation------------
void opening(void)
{
    printf("==============================================================\n");
    printf("==============================================================\n");
    printf("==========                SHARK GAME!!!                =======\n");
    printf("==============================================================\n");
    printf("==============================================================\n");
}
// ----- EX. 1 : Preparation------------
// ----- EX. 6 : game end ------------
int game_end(void)
{
    int i;
    int flag_end = 1;

    //if all the players are died?
    for (i=0;i<N_PLAYER;i++)
    {
        if (player_status[i] == PLAYERSTATUS_LIVE)
        {
            flag_end = 0;
            break;
        }
    }
    
    return flag_end;
}
// ----- EX. 6 : game end ------------
// ----- EX. 4 : player ------------
void printPlayerPosition(int player)
{
    int i;
    
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (player_position[player] == i)
            printf("%c", player_name[player][0]);
        else
        {
            if (board_getBoardStatus(i) == BOARDSTATUS_NOK)
                printf("X");
            else
                printf(" ");
        }
    }
    printf("|\n");
}
void printPlayerStatus(void)
{
    int i;
    printf("player status ---\n");
    for (i=0;i<N_PLAYER;i++)
    {
        printf("%s : pos %i, coin %i, status %s\n", player_name[i], player_position[i], player_coin[i], player_statusString[player_status[i]]);
        printPlayerPosition(i);
    }
    printf("-----------------\n");
}
// ----- EX. 4 : player ------------
// ----- EX. 5 : shark ------------
void checkDie(void)
{
    int i;
    for (i=0;i<N_PLAYER;i++)
    {
        if (board_getBoardStatus(player_position[i]) == BOARDSTATUS_NOK)
        {
            printf("%s in pos %i has died!! (coin %i)\n", player_name[i], player_position[i], player_coin[i]);
            player_status[i] = PLAYERSTATUS_DIE;
        }
    }
}
// ----- EX. 5 : shark ------------
// ----- EX. 6 : game end ------------
int getAlivePlayer(void)
{
   int i;
	int cnt = 0;


   for (i=0;i<N_PLAYER;i++)
   {
   	if (player_status[i] == PLAYERSTATUS_END)
   	{
   		cnt++;
		} 
   	
   }
   
   
   return cnt;
}


int getWinner(void)
{
	int i,j,k;
	int winner=-1;
	int max_coin = -1;
	
	// �ߺ� ����� ���� ������  
	
	int check[100] = {}; // �� ������ ���� Ƚ���� ������ �迭 
	int idx; // ���� �迭�� ��ȸ�ϸ� check�� ���� Ƚ���� �����ϴ� ����  
	int bigger,smaller;


	for(i=0;i<N_PLAYER;i++)
	{
			if (player_status[i] == PLAYERSTATUS_END ) {
					if (player_coin[i] > max_coin){

						max_coin = player_coin[i];
						winner = i; // �ߺ��� ���� ��� max�� �����  winner�� ����� ����  
			
				}
				
					 
			}

	}
	
	
	
	 // �ߺ��� �ִ°�쿡winner�� ����  
	 
	 //���� ���� �迭 (1~`100�� ����) �� �ߺ��� ���
	 for (i = 0; i<N_PLAYER;i++){
	 	idx = player_coin[i];
		check[idx]++;
	 }


	for(i=0;i<N_PLAYER;i++)
	{
			if (player_status[i] == PLAYERSTATUS_END ) {
					for(j=0;j<100;j++){
						
						if (check[j]==2)
						{	
							winner = theOrderofEND[0]; //End���°� 3���� �ƴҶ� 
							 
							for(k=0;k<100;k++)
							{
								if (check[k]==1) //  End ���� 3�� 
								{
									if (k<j) // end ���� ����, ���� �迭 {4,4,3}, {4,3,4}, {3,4,4}�� ���  
									{
										if (player_coin[0]>=player_coin[1]) // {4,4,3}
										  winner = 0;
										else 
										  winner = 1;	
									}
										
								}
							}
						 } 
							
						if (check[j] ==3) 
						 winner = theOrderofEND[0];
						
					}
			
				}	 
			}


	

	
		/*
	//�ߺ����θ� Ž���� �迭
Player_coin[N_PLAYER] // ���� ��� {4,4,3}

//�迭�� ���� N_PLAYER

// �� ������ ���� Ƚ���� ������ �迭 
int check [Coin_max] = {};

int idx


for (i = 0; i<N_PLAYER;i++)
idx = a[i];
check[idx]++;

for(i=0;i<coin_max;i++)
if check[i] == 2*/
	
	

	if (winner == -1) // ��� ����� �׾��� ��� ���ʴ� �������� ����  
		winner = -1;

	return winner;

}
// ----- EX. 6 : game end ------------
int main(int argc, const char * argv[]) {
    
    int i;
    int turn=0; 
    int cnt = 0; 
    
    int pos=0;// ��ġ���� ���� 18p 
// ----- EX. 1 : Preparation------------
    srand(time(NULL));
    opening();
// ----- EX. 1 : Preparation------------
// ----- EX. 2 : structuring ------------
    //step1 : initialization
    //step1-1 : board initialization
    board_initBoard();
// ----- EX. 4 : player ------------
    //step1-2 : initialize player
    for (i=0;i<N_PLAYER;i++)
    {
        player_position[i] = 0;
        player_coin[i] = 0;
        player_status[i] = PLAYERSTATUS_LIVE; // ���� ���� �ʱ�ȭ position, coin, status 
        printf("Player %i's name: ", i);
        scanf("%s", player_name[i]); // �̸� �Է�  
    }
// ----- EX. 4 : player ------------
    
    //step 2. : game start, turn loop
    do {
        int dieResult;
        int coinResult;
        int dum;
    
        
// ----- EX. 3 : board ------------
        board_printBoardStatus(); // 18p do while �� �ȿ� �� �ֱ�
		dieResult = rolldie(); // �ֻ����� ������ �̵�Ƚ�� ���� 
		pos = dieResult; // �̵� Ƚ�� ��ŭ pos ����  
		coinResult = board_getBoardCoin(pos); //coinResult = board_getBoardCoin(pos);
        
// ----- EX. 3 : board ------------
// ----- EX. 4 : player ------------
        printPlayerStatus();
         //step 2-1. status printing
        // player ���� ���
		//printPlayerPosition(int player)
        //printPlayerStatus(void)
        
// ----- EX. 4 : player ------------
        if (player_status[turn] != PLAYERSTATUS_LIVE)
        {
            turn = (turn + 1)%N_PLAYER;  
            continue;
        }
// ----- EX. 4 : player ------------
        //step 2-2. rolling die
// ----- EX. 4 : player ------------
        printf("%s turn!! ", player_name[turn]);
        printf("Press any key to roll a die!\n");
        scanf("%d", &dum);
        fflush(stdin);
// ----- EX. 4 : player ------------
        dieResult = rolldie();
        //step 2-3. moving
        player_position[turn] += dieResult; // �ǽ�4 23p player_position[turn] += dieReuslt�� �ֻ��� ����� ����
// ���� ��Ȳ�� ���� ��ó (N_BOARD �̻� ������) QQQQQ
// ���� �� ������ �̵��� ��쿡 ���� ó��
//player_position[turn]�� N_BOARD -1 ���� ���θ� ���ǹ����� Ȱ��QQQQQ
//player_status[turn]��PLAYERSTATUS_END ������ ����
 		if (player_position[turn] > N_BOARD-1){
 			
 			player_position[turn] = N_BOARD-1;
 			player_status[turn] = PLAYERSTATUS_END;
			theOrderofEND [cnt] = turn; // PLAYERSTATUS�� END�� �Ǿ��� �� turn�� ���� ex {0,2,-1} sm, jyp�� ����� -1��  
 			cnt++;
 			
		 }
		 
 
 
// �̵� ��� ��� 
	printf("Die result : %d , %s moved to %d \n", dieResult, player_name[turn], player_position[turn]);
        //step 2-4. coin
// �̵��� ��ġ���� board_getBoardCoin �Լ� ȣ��
// ��ȯ�� coin ���� player_coin[turn]�� ����
//coin�� �����ϴ� ��� coin ���� ������ ���
	
	coinResult = board_getBoardCoin (player_position[turn]);
	player_coin[turn] += coinResult;
	
	
	printf("Coin : %d, the coin that %s has got so far : %d\n", coinResult, player_name[turn],	player_coin[turn]);
 
 
 
 
        
        //step 2-5. end process
        
// ----- EX. 4 : player ------------
// �� player�� turn ���� ���� 
// game �ݺ������� �ѹ� �ݺ� �� ���� player�� �Ѿ 
// turn ������ �����ϰ� �ݺ����� 1�� ����
//N_PLAYER�� �����⿬�� ����  
        turn = (turn+1) % N_PLAYER;

	printf("\n");
	printf("\n");

	printf("\n"); // turn�� �����ϱ� ���ؼ�  �� ���ڽ��ϴ�.  


    
 // ----- EX. 5 : making shark ------------   
    
	if (turn == 0)
	{
	int shark_pos = board_stepShark();
	printf("\n Shark moved to %d \n", shark_pos);
	printf("\n");
	checkDie();
	}



 // ----- EX. 5 : making shark ------------ 




    printf("\n");
	printf("\n");

// ----- EX. 6 : game end ------------
    } while(game_end() == 0);
    
    //step 3. game end process
    printf("GAME END!!\n");
    
    if (getWinner() != -1)
    printf("%i players are alive! winner is %s\n", getAlivePlayer(), player_name[getWinner()]);
    else 
    printf("there is no winner");
// ----- EX. 6 : game end ------------
    
    
    
    
    
    
    
// ----- EX. 2 : structuring ------------



    return 0;
}
