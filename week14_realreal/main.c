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
int player_position[N_PLAYER]; // 위치  
char player_name[N_PLAYER][MAX_CHARNAME]; // 이름  
int player_coin[N_PLAYER]; // 누적 코인수  
int player_status[N_PLAYER]; //0 - live, 1 - die, 2 - end , 현재 상태  
char player_statusString[3][MAX_CHARNAME] = {"LIVE", "DIE", "END"}; // 상태 설명 문자열 





 // 모두 END인데 동전 개수가 같을 경우, 먼저 들어온 순서를 알아내기위해  카운트 하기 위함  
int theOrderofEND [N_PLAYER] = {-1,-1,-1};  // 카운트를 인덱스로 하여 들어온 순서대로 플레이어의 인덱스를 저장  
int turn_cnt=0;


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
	
	// 중복 계산을 위한 변수들  
	
	int check[100] = {}; // 각 원소의 등장 횟수를 저장할 배열 
	int idx; // 코인 배열을 순회하며 check에 등장 횟수를 저장하는 변수  
	int bigger,smaller;


	for(i=0;i<N_PLAYER;i++)
	{
			if (player_status[i] == PLAYERSTATUS_END ) {
					if (player_coin[i] > max_coin){

						max_coin = player_coin[i];
						winner = i; // 중복이 없는 경우 max인 사람을  winner로 만드는 로직  
			
				}
			}

	}
	
	
	
	 // 중복이 있는경우에winner를 갱신  
	 
	 //코인 개수 배열 (1~`100개 까지) 중 중복을 계산
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
							winner = theOrderofEND[0]; //End상태가 3개가 아닐때 
							 
							for(k=0;k<100;k++)
							{
								if (check[k]==1) //  End 상태 3개 
								{
									if (k<j) // end 상태 세개, 코인 배열 {4,4,3}, {4,3,4}, {3,4,4}인 경우  
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
	//중복여부를 탐색할 배열
Player_coin[N_PLAYER] // 예를 들어 {4,4,3}

//배열의 길이 N_PLAYER

// 각 원소의 등장 횟수를 저장할 배열 
int check [Coin_max] = {};

int idx


for (i = 0; i<N_PLAYER;i++)
idx = a[i];
check[idx]++;

for(i=0;i<coin_max;i++)
if check[i] == 2*/
	
	

	if (winner == -1) // 모든 사람이 죽었을 경우 위너는 존재하지 않음  
		winner = -1;

	return winner;

}
// ----- EX. 6 : game end ------------
int main(int argc, const char * argv[]) {
    
    int i;
    int turn=0; 
    int cnt;
 
    
    int pos=0;// 위치변수 선언 18p 
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
        player_status[i] = PLAYERSTATUS_LIVE; // 각종 변수 초기화 position, coin, status 
        printf("Player %i's name: ", i);
        scanf("%s", player_name[i]); // 이름 입력  
    }
// ----- EX. 4 : player ------------
    
    //step 2. : game start, turn loop
    do {
        int dieResult;
        int coinResult;
        int dum;
    
        
// ----- EX. 3 : board ------------
        board_printBoardStatus(); // 18p do while 문 안에 값 넣기
		dieResult = rolldie(); // 주사위를 굴려서 이동횟수 지정 
		pos = dieResult; // 이동 횟수 만큼 pos 결정  
		coinResult = board_getBoardCoin(pos); //coinResult = board_getBoardCoin(pos);
        
// ----- EX. 3 : board ------------
// ----- EX. 4 : player ------------
        printPlayerStatus();
         //step 2-1. status printing
        // player 상태 출력
		//printPlayerPosition(int player)
        //printPlayerStatus(void)
        
// ----- EX. 4 : player ------------
        if (player_status[turn] != PLAYERSTATUS_LIVE)
        {	
        	printf("%d\n",turn);
            turn = (turn + 1)%N_PLAYER;  
            printf("%d\n",turn);
            
            
            if (turn == 0)  // 여기에도 샤크를 넣어줘야 상태가 변해도 빼먹지 않고 상어가 움직임  
		{
			int shark_pos = board_stepShark();
			if (shark_pos>18) 
			{
				shark_pos = 18;
			}
			printf("\n Shark moved to %d \n", shark_pos);
			printf("\n");
			
			checkDie();
			printf("%d\n",turn); 
		}

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
        player_position[turn] += dieResult; // 실습4 23p player_position[turn] += dieReuslt에 주사위 결과를 더함
// 예외 상황에 대한 대처 (N_BOARD 이상 갔을때) QQQQQ
// 보드 맨 끝까지 이동한 경우에 대해 처리
//player_position[turn]이 N_BOARD -1 인지 여부를 조건문으로 활용QQQQQ
//player_status[turn]을PLAYERSTATUS_END 값으로 설정
 		if (player_position[turn] > N_BOARD-1){
 			
 			player_position[turn] = N_BOARD-1;
 			player_status[turn] = PLAYERSTATUS_END;
 			
			theOrderofEND [cnt] = turn; // PLAYERSTATUS가 END가 되었을 때 turn을 저장 ex {0,2,-1} sm, jyp만 저장됨 -1을  
 			cnt++;
 			
		 }
		 
 
 
// 이동 결과 출력 

	if(player_status[turn] == PLAYERSTATUS_END)
	{
		printf("player %s reached to the end line and survived\n", player_name[turn]);
	}
	else
	printf("Die result : %d , %s moved to %d \n", dieResult, player_name[turn], player_position[turn]);
        //step 2-4. coin
// 이동한 위치에서 board_getBoardCoin 함수 호출
// 반환된 coin 값을 player_coin[turn]에 더함
//coin이 존재하는 경우 coin 습득 정보를 출력
	
	coinResult = board_getBoardCoin (player_position[turn]);
	player_coin[turn] += coinResult;
	
	
	printf("Coin : %d, the coin that %s has got so far : %d\n", coinResult, player_name[turn],	player_coin[turn]);
 
 
 
 
        
        //step 2-5. end process
        
// ----- EX. 4 : player ------------
// 각 player의 turn 동작 구현 
// game 반복문에서 한번 반복 후 다음 player로 넘어감 
// turn 변수를 선언하고 반복마다 1씩 증가
//N_PLAYER로 나누기연산 수행  

    

 
 
 

	printf("%d\n",turn); 
        turn = (turn+1) % N_PLAYER; // turn== 0 1 2
		turn_cnt++; 
    printf("%d\n",turn); 
	printf("\n");
	printf("\n");

	printf("\n"); // turn을 구분하기 위해서  좀 띄우겠습니다.  

    printf("\n");
	printf("\n");
	
	
	 // ----- EX. 5 : making shark ------------   
    
    
     

    if (turn == 0) 
		{
			int shark_pos = board_stepShark();
			
			if (shark_pos>18) 
			{
				shark_pos = 18;
			}
			printf("\n Shark moved to %d \n", shark_pos);
			printf("\n");
			checkDie();
			printf("%d\n",turn); 
		}



 // ----- EX. 5 : making shark ------------ 

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
