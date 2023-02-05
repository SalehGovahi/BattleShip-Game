#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "battleship.h"


int main()
{
    //Part1 (Difining variables)
    int input,temp=1;
    int i,j,x,y;
    int battlesNumber = 0;
    int counterBattlesRemaining1 = 0;
    int counterBattlesRemaining2 = 0;
    int counter1=0;
    int counter2=0;
    int xBattle , yBattle;
    int xAttack , yAttack;
    char direction;
    int sw=0;
    char temp1[100];

    FILE *information;
    information = fopen ("information.txt" , "rt");

    StartingText();

    fscanf(information,"%d",&input);
    printf("\n");

    //Part 2(Making 2 board with input+1 row & input+1 col)
    int board1[40][40];
    int board2[40][40];


    //Part 3(Putting row number)
    PutRowNumber(board1,board2,input);

    //Part 4(Putting col number)
    PutColNumber(board1,board2,input);

    //Part 5(Making base boards)
    MakeBaseBoards(board1,board2,input);

		clearScreen();
		printf("\n");
		//Part 6(Printing 2 boards)
		//PrintTwoBoards(board1,board2,input);
		//Part 7(Getting number of battles)
		//sleep(5);
		clearScreen();
		setTextColor(7,0);

    //Part 7(Getting number of battles)
    printf("\n                        Input number of battles: ");
    fscanf(information,"%d",&battlesNumber);
    counterBattlesRemaining1= battlesNumber*3;
    counterBattlesRemaining2= battlesNumber*3;
    printf("%d\n", counterBattlesRemaining1);

		clearScreen();
    fscanf(information,"%s",temp1);
    //Part 8(Getting coordinates & direction of player1 battles)
    printf("\n                                Turn of Player1\n");
    printf("\n                 Input coordinates & direction of your battles:");
    for (i = 1 ; i<=battlesNumber ; i++){
        fscanf(information,"%d %d %c",&yBattle,&xBattle,&direction);
        if (direction=='h'){                      //These Ifs are for checking that batlles not be on baseboard
          if ((xBattle != 0) && (yBattle != 0))
              board1[xBattle][yBattle]=254;
          else
              counterBattlesRemaining1--;
          if ((xBattle+1 != 0) && (yBattle != 0))
              board1[xBattle+1][yBattle]=254;
          else
              counterBattlesRemaining1--;
          if ((xBattle-1 != 0) && (yBattle != 0))
              board1[xBattle-1][yBattle]=254;
          else
              counterBattlesRemaining1--;
        }
        if (direction=='v'){                      //These Ifs are for checking that batlles not be on baseboard
            if ((xBattle != 0) && (yBattle != 0))
                board1[xBattle][yBattle]=254;
            else
                counterBattlesRemaining1--;
            if ((xBattle != 0) && (yBattle-1 != 0))
                board1[xBattle][yBattle-1]=254;
            else
                counterBattlesRemaining1--;
            if ((xBattle != 0) && (yBattle+1 != 0))
                board1[xBattle][yBattle+1]=254;
            else
                counterBattlesRemaining1--;
        }
        PlaceBattle1(board1,xBattle,yBattle,direction,i,battlesNumber);
    }

    clearScreen();
    fscanf(information,"%s",temp1);
    fscanf(information,"%s",temp1);
    //Part 9(Getting coordinates & direction of player2 battles)
		setTextColor(7,0);
    printf("\n                                Turn of Player2\n");
    printf("\n                 Input coordinates & direction of your battles:");
    for (i = 1 ; i<=battlesNumber ; i++){
        fscanf(information,"%d %d %c",&yBattle,&xBattle,&direction);
        if (direction=='h'){                      //These Ifs are forchecking that batlles not be on baseboard
          if ((xBattle != 0) && (yBattle != 0))
              board2[xBattle][yBattle]=254;
          else
              counterBattlesRemaining2--;
          if ((xBattle+1 != 0) && (yBattle != 0))
              board2[xBattle+1][yBattle]=254;
          else
              counterBattlesRemaining2--;
          if ((xBattle-1 != 0) && (yBattle != 0))
              board2[xBattle-1][yBattle]=254;
          else
              counterBattlesRemaining2--;
        }
        if (direction=='v'){                      //These Ifs are for checking that batlles not be on baseboard
            if ((xBattle != 0) && (yBattle != 0))
                board2[xBattle][yBattle]=254;
            else
                counterBattlesRemaining2--;
            if ((xBattle != 0) && (yBattle-1 != 0))
                board2[xBattle][yBattle-1]=254;
            else
                counterBattlesRemaining2--;
            if ((xBattle != 0) && (yBattle+1 != 0))
                board2[xBattle][yBattle+1]=254;
            else
                counterBattlesRemaining2--;
        }
        PlaceBattle2(board2,xBattle,yBattle,direction,i,battlesNumber);
    }
		clearScreen();

		printf("\n");

		//Part 6(Printing 2 boards)
		//PrintTwoBoards(board1,board2,input);
		//sleep(10);
		clearScreen();

		    //Start attacking
		    do {
            //Attacking player 1
		        if (counterBattlesRemaining1 != 0 && counterBattlesRemaining2 != 0){
						clearScreen();
						setTextColor(7,0);
            printf("\n                            Player1 | Try your luck\n");
						printf("\n                                     ");
		        scanf("%d %d",&yAttack , &xAttack);
		        printf("\n");
            attack(board2,xAttack,yAttack,input);
            if (board2[xAttack][yAttack]==42){
                counterBattlesRemaining2--;
                sw=1;
              }
            setTextColor(7,0);
            if (counterBattlesRemaining2 % 3 ==0 && counterBattlesRemaining2!=0 && sw==1)
            if (board2[xAttack-1][yAttack] != 254 && board2[xAttack+1][yAttack] != 254 &&  board2[xAttack][yAttack+1] != 254 && board2[xAttack][yAttack-1] != 254){
            printf("\n                         One of Player2's battle drowned\n");
            sw=0;}
		      }


		      //Attacking player 2
		      if (counterBattlesRemaining2 != 0 && counterBattlesRemaining1 != 0){
					sleep(5);
					clearScreen();
					setTextColor(7,0);
          printf("\n                            Player2 | Try your luck\n");
					printf("\n                                     ");
					scanf("%d %d",&yAttack , &xAttack);
					printf("\n");
          attack(board1,xAttack,yAttack,input);
          if (board1[xAttack][yAttack]==42){
              counterBattlesRemaining1--;
              sw=1;
            }
          setTextColor(7,0);
          if (counterBattlesRemaining1 % 3 ==0 && counterBattlesRemaining1!=0 && sw==1){
              if (board1[xAttack-1][yAttack] != 254 && board1[xAttack+1][yAttack] != 254 &&  board1[xAttack][yAttack+1] != 254 && board1[xAttack][yAttack-1] != 254){
              printf("\n                         One of Player1's battle drowned\n");
              sw=0;}
            }
				  sleep(5);
		    }
		  } while(counterBattlesRemaining1 != 0 && counterBattlesRemaining2 != 0);
        setTextColor(7,0);
       if (counterBattlesRemaining1==0)
           printf("\n                                   Player2 won\n");
       if (counterBattlesRemaining2==0)
           printf("\n                                   Player1 won\n");


    return 0;
}
