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
    int savesw = 0;
    char temp1[100];
    int board1[40][40];
    int board2[40][40];
    int o = 1;
    int t = 2;
    FILE *information;
    FILE *save;

    printf("\nDo you want to continue your last game? (Insert 1 to accept)");
    printf("\n                                     ");
    scanf("%d" , &savesw);

    if (savesw==1){
        printf("Yes");
        save = fopen("save.txt" , "r");
        fscanf(save,"%d",&input);
        printf("%d" , input);
        //Part 3(Putting row number)
        PutRowNumber(board1,board2,input);
        //Part 4(Putting col number)
        PutColNumber(board1,board2,input);
        //Part 5(Making base boards)
        MakeBaseBoards(board1,board2,input);
        printf("%d" , input);
        fscanf(save,"%d",&battlesNumber);
        counterBattlesRemaining1= battlesNumber*3;
        counterBattlesRemaining2= battlesNumber*3;
        printf("%d" , input);
        for (i = 1 ; i<=battlesNumber ; i++){
        fscanf(save,"%d %d %c", &yBattle, &xBattle, &direction);
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
        printf("%d" , input);
        for (i = 1 ; i<=battlesNumber ; i++){
        fscanf(save,"%d %d %c", &yBattle, &xBattle, &direction);
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
        while(!feof(save)){
            fscanf(save,"%d", &temp);
            if (temp == 1){
                fscanf(save,"%d %d", &yAttack , &xAttack);
                board1[xAttack][yAttack] = 42;
                counterBattlesRemaining1--;
            }
            if (temp == 2){
                fscanf(save,"%d %d", &yAttack , &xAttack);
                board2[xAttack][yAttack] = 42;
                counterBattlesRemaining2--;
            }
        }
        savesw = 0;
        fclose(save);
    }
    else{
    scanf("%d",&input);
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
    scanf("%d" , &battlesNumber);
    counterBattlesRemaining1= battlesNumber*3;
    counterBattlesRemaining2= battlesNumber*3;
    printf("%d\n", counterBattlesRemaining1);

		clearScreen();
    //Part 8(Getting coordinates & direction of player1 battles)
    printf("\n                                Turn of Player1\n");
    printf("\n                 Input coordinates & direction of your battles:");
    for (i = 1 ; i<=battlesNumber ; i++){
        scanf("%d %d %c", &yBattle , &xBattle , &direction );
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


    //Part 9(Getting coordinates & direction of player2 battles)
		setTextColor(7,0);
    printf("\n                                Turn of Player2\n");
    printf("\n                 Input coordinates & direction of your battles:");
    for (i = 1 ; i<=battlesNumber ; i++){
        scanf("%d %d %c", &yBattle , &xBattle , &direction );
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
    }
    save = fopen("save.txt" , "w");
    clearScreen();

		printf("\n");

		//Part 6(Printing 2 boards)
		//PrintTwoBoards(board1,board2,input);
		//sleep(10);
		clearScreen();
        //savesw = 0;
        //Start attacking
        do {
             if (savesw != 1){
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
               fprintf(save,"%d\n", t);
               fprintf(save,"%d %d\n" , yAttack , xAttack);
               counterBattlesRemaining2--;
               sw=1;
            }
            fprintf(save,"%d\n" , counterBattlesRemaining2);
            setTextColor(7,0);
            if (counterBattlesRemaining2 % 3 ==0 && counterBattlesRemaining2!=0 && sw==1){
                if (board2[xAttack-1][yAttack] != 254 && board2[xAttack+1][yAttack] != 254 &&  board2[xAttack][yAttack+1] != 254 && board2[xAttack][yAttack-1] != 254){
                    printf("\n                         One of Player2's battle drowned\n");
                    sw=0;
                }
            }
            }
             }
             printf("\n               Do you want to save the game and quit?(Insert 1 to accept)\n");
             printf("\n                                     ");
             scanf("%d" , &savesw);

            if (savesw != 1){
                   //Attacking player 2
            if (counterBattlesRemaining2 != 0 && counterBattlesRemaining1 != 0){
                //sleep(5);
                clearScreen();
                setTextColor(7,0);
                printf("\n                            Player2 | Try your luck\n");
                printf("\n                                     ");
                scanf("%d %d",&yAttack , &xAttack);
                fprintf(save,"%d %d\n" , yAttack , xAttack);
                printf("\n");
                attack(board1,xAttack,yAttack,input);
            if (board1[xAttack][yAttack]==42){
                fprintf(save,"\n");
                fprintf(save,"%d %d\n" , yAttack , xAttack);
                counterBattlesRemaining1--;
                sw=1;
            }
            fprintf(save,"%d\n" , counterBattlesRemaining1);
            setTextColor(7,0);
            if (counterBattlesRemaining1 % 3 ==0 && counterBattlesRemaining1!=0 && sw==1){
                if (board1[xAttack-1][yAttack] != 254 && board1[xAttack+1][yAttack] != 254 &&  board1[xAttack][yAttack+1] != 254 && board1[xAttack][yAttack-1] != 254){
                    printf("\n                         One of Player1's battle drowned\n");
                    sw=0;
                }
            }
            }
                        //sleep(5);
            printf("\n               Do you want to save the game and quit?(Insert 1 to accept)\n");
            printf("\n                                     ");
            scanf("%d" , &savesw);
            }

		  } while(counterBattlesRemaining1 != 0 && counterBattlesRemaining2 != 0 && savesw != 1);
       if (savesw ==1){
           setTextColor(7,0);
           printf("\n                            Game saved successfully!\n");
       }
       if (counterBattlesRemaining1==0)
           printf("\n                                   Player2 won\n");
       if (counterBattlesRemaining2==0)
           printf("\n                                   Player1 won\n");
       fclose(save);
       fclose(information);
}
