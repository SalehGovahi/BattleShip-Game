#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "mybattle.h"


int main(){

    //Defining variables
    int input,temp=1;
    int i,j,x,y,n,h;
    h=0;
    int battlesNumber = 0;
    int counterBattlesRemaining1 = 10;
    int counterBattlesRemaining2 = 10;
    int NumberOfSize;
    int counter1=0;
    int counter2=0;
    int xBattle , yBattle;
    int xAttack , yAttack;
    int cp1,cp2;
    cp1=0;cp2=0;
    int n1,n2;
    n1=0,n2=0;
    char direction;
    int tmpChar1;
    int tmpChar2;
    int sw1=0;
    int sw2=0;
    int sw11=0;
    int sw22=0;
    char character[100];
    int MaximumSize;
    int SumSize = 0;
    int tmp1,tmp2;
    int repair;
    int repairPlayer2;
    int repairPlayer1;
    int number;
    FILE* info;
    // struct ship p1[100],p2[100];

    info = fopen("info.txt" , "r+");
    StartingText();

    //printf("                            Enter a number : ");
    fscanf(info, "%d", &input);
    printf("%d" , input);
    //scanf("%d", &input);
    if(input<=2)
        input=3;
    n=input;
    //sleep(10);

    clearScreen();

    //printf("                            Enter Maximumsize : ");
    fscanf(info, "%d", &MaximumSize);
    //printf("%d" , MaximumSize);
    //scanf("%d" , &MaximumSize);
    //sleep(10);
    clearScreen();

    //Making 2 board
    int board1[40][40];
    int board2[40][40];

    //Putting row number
    PutRowNumber(board1,board2,input);

    //Putting col number
    PutColNumber(board1,board2,input);

    //Making base boards
    MakeBaseBoards(board1,board2,input);

	//scanf("%s" , character);
	fscanf(info, "%s", character);
	//printf("%s" , character);
	//sleep(10);

    //Getting number of battles
    setTextColor(7,0);
    //printf("\n                        Input size & number of this size battles: ");
    fscanf(info, "%d %d %d", &tmp1 , &tmp2 , &number);
    //sleep(10);
    //scanf("%d %d %d", &tmp1 , &tmp2 , &number);
    for (i = 0 ; i<number ; i++){
        //printf("                            Enter a number : ");
        fscanf(info, "%d %d %c", &yBattle , &xBattle , &direction);
        if( (yBattle+tmp1>n+1) && (direction=='v') )
            yBattle=n-tmp1+1;
        if( (yBattle+tmp2>n+1) && (direction=='h') )
            yBattle=n-tmp2+1;
        if( (xBattle+tmp2>n+1) && (direction=='v') )
            xBattle=n-tmp2+1;
        if( (xBattle+tmp1>n+1) && (direction=='h') )
            xBattle=n-tmp1+1;
        if((yBattle<1))
            yBattle=1;
        if((xBattle<1))
            xBattle=1;

        //sleep(10);
        //scanf("%d %d %c" , &yBattle , &xBattle , &direction);
        if (direction == 'h'){
            for (j=xBattle ; j <(xBattle+tmp2) ; j++){
                board1[j][yBattle] = 254;
                for (x=yBattle ; x <(yBattle+tmp1); x++){
                board1[j][x] = 254;
            }
            }
            //for (x=yBattle ; x <(yBattle+tmp1); x++){
                //board1[xBattle][x] = 254;
            //}
        }
        if (direction == 'v'){
            for (x=yBattle ; x <(yBattle+tmp2) ; x++){
                board1[xBattle][x] = 254;
                for (j=xBattle ; j <(xBattle+tmp1) ; j++){
                board1[j][x] = 254;
            }
            }
        }
    }

    fscanf(info, "%s", character);
    //sleep(10);
    //scanf("%s" , character);
    //printf("%s" , character);

    if (strcmp(character,"$$$")==0){
        fscanf(info, "%d %d %d", &tmp1 , &tmp2 , &number);
        //sleep(10);
        //scanf("%d %d %d", &tmp1 , &tmp2 , &number);
        for (i = 0 ; i<number ; i++){
        //printf("                            Enter a number : ");
        fscanf(info, "%d %d %c", &yBattle , &xBattle , &direction);
        //sleep(10);
        //scanf("%d %d %c" , &yBattle , &xBattle , &direction);

        if( (yBattle+tmp1>n+1) && (direction=='v') )
            yBattle=n-tmp1+1;
        if( (yBattle+tmp2>n+1) && (direction=='h') )
            yBattle=n-tmp2+1;
        if( (xBattle+tmp2>n+1) && (direction=='v') )
            xBattle=n-tmp2+1;
        if( (xBattle+tmp1>n+1) && (direction=='h') )
            xBattle=n-tmp1+1;
        if((yBattle<1))
            yBattle=1;
        if((xBattle<1))
            xBattle=1;

        if (direction == 'h'){
            for (j=xBattle ; j <(xBattle+tmp2) ; j++){
                board1[j][yBattle] = 254;
                for (x=yBattle ; x <(yBattle+tmp1); x++){
                board1[j][x] = 254;
            }
            }
        }
        if (direction == 'v'){
            for (x=yBattle ; x <(yBattle+tmp2) ; x++){
                board1[xBattle][x] = 254;
                for (j=xBattle ; j <(xBattle+tmp1) ; j++){
                board1[j][x] = 254;
            }
            }

        counter1++;
    }
    }
    }

    if (strcmp(character,"---")==0){
        fscanf(info, "%s", character);
        //sleep(10);
        //scanf("%s" , character);
        setTextColor(7,0);
        //printf("\n                        Input size & number of this size battles: ");
        fscanf(info, "%d %d %d", &tmp1 , &tmp2 , &number);
        //sleep(10);
        //scanf("%d %d %d", &tmp1 , &tmp2 , &number);
        for (i = 0 ; i<number ; i++){
        //printf("                            Enter a number : ");
        fscanf(info, "%d %d %c", &yBattle , &xBattle , &direction);
        //sleep(10);
        //scanf("%d %d %c" , &yBattle , &xBattle , &direction);
        if (direction == 'h'){
            for (j=xBattle ; j <(xBattle+tmp2) ; j++){
                board2[j][yBattle] = 254;
                for (x=yBattle ; x <(yBattle+tmp1); x++){
                board2[j][x] = 254;
            }
            }
        }
        if (direction == 'v'){
            for (x=yBattle ; x <(yBattle+tmp2) ; x++){
                board2[xBattle][x] = 254;
                for (j=xBattle ; j <(xBattle+tmp1) ; j++){
                board2[j][x] = 254;
            }
            }
        }
        counter1++;
        }
        fscanf(info, "%s", character);
        //sleep(10);
        //scanf("%s" , character);

    if (strcmp(character,"$$$")==0){
        //printf("\n                        Input size & number of this size battles: ");
        fscanf(info, "%d %d %d", &tmp1 , &tmp2 , &number);
        //sleep(10);
        //scanf("%d %d %d", &tmp1 , &tmp2 , &number);
        for (i = 0 ; i<number ; i++){
        //printf("                            Enter a number : ");
        fscanf(info, "%d %d %c", &yBattle , &xBattle , &direction);
        //sleep(10);
        //scanf("%d %d %c" , &yBattle , &xBattle , &direction);
        if (direction == 'h'){
            for (j=xBattle ; j <(xBattle+tmp2) ; j++){
                board2[j][yBattle] = 254;
                for (x=yBattle ; x <(yBattle+tmp1); x++){
                board2[j][x] = 254;
            }
            }
        }
        if (direction == 'v'){
            for (x=yBattle ; x <(yBattle+tmp2) ; x++){
                board2[xBattle][x] = 254;
                for (j=xBattle ; j <(xBattle+tmp1) ; j++){
                board2[j][x] = 254;
            }
            }
        }
        counter1++;
        }

    }
    fscanf(info, "%s", character);
    //sleep(10);
    //scanf("%s" , character);
    if (strcmp(character,"---")==0){
        fscanf(info , "%d" , &repair);
        repairPlayer2 = repair;
        repairPlayer1 = repair;
        //sleep(10);
    }
    }
    PrintTwoBoards(board1,board2,input);

    sleep(5);
    clearScreen();

     do
    {
        //Attacking player 1
        if (counterBattlesRemaining1 != 0 && counterBattlesRemaining2 != 0){
					clearScreen();
					setTextColor(7,0);
                    printf("\n                            Player1 | Try your luck\n");
                    printf("\n                            Do you want to repair your battle?(1 to accept /0 to deny)\n");
                    scanf("%d" , &tmpChar1);
                    if (tmpChar1 == 1 && h==0){
                        if (repairPlayer1 == 0 && h==0){
                            printf("\nYou have done all your allowed repair");
                            sleep(5);
                            clearScreen();
                            printf("\n                            Attack player2\n");
                            printf("\n                                     ");
                            scanf("%d %d",&yAttack , &xAttack);
		                    printf("\n");
                            attack(board2,xAttack,yAttack,input);
                            sleep(5);
                        }
                        else{
                            printf("Repair your battle:");
                            scanf("%d %d",&yAttack , &xAttack);
                            board1[xAttack][yAttack] == 254;
                            repairPlayer1--;
                        }
                    }
                    else if (tmpChar1 == 0 && h==0){
                        printf("\n                            Attack player2\n");
                        printf("\n                                     ");
                        scanf("%d %d",&yAttack , &xAttack);
		                printf("\n");
                        attack(board2,xAttack,yAttack,input);
                        sleep(5);
                    }
                    sw22=0;
                    for(i = 0 ; i<=input ; i++){
                        for(j = 0 ; j<=input ; j++){
                            if (board1[i][j] == 254){
                                sw22 = 1;
                                break;
                            }
                        }
                    }
                //    if (sw22==0)
                 //       sw2 = 1;
                 //   sw22 = 0;
		}

        //Attacking player 2
        if (counterBattlesRemaining1 != 0 && counterBattlesRemaining2 != 0){
					clearScreen();
					setTextColor(7,0);
                    printf("\n                            Player2 | Try your luck\n");
                    printf("\n                            Do you want to repair your battle?(1 to accept /0 to deny)\n");
                    scanf("%d" , &tmpChar2);
                    if (tmpChar2 == 1 && h==0){
                        if (repairPlayer2 == 0){
                            printf("\nYou have done all your allowed repair");
                            sleep(5);
                            clearScreen();
                            printf("\n                            Attack player1\n");
                            printf("\n                                     ");
                            scanf("%d %d",&yAttack , &xAttack);
		                    printf("\n");
                            attack(board1,xAttack,yAttack,input);
                            sleep(5);
                        }
                        else{
                            printf("Repair your battle:");
                            scanf("%d %d",&yAttack , &xAttack);
                            board2[xAttack][yAttack] == 254;
                            repairPlayer2--;
                        }
                    }
                    else if (tmpChar2 == 0 && h==0){
                        printf("\n                            Attack player1\n");
                        printf("\n                                     ");
                        scanf("%d %d",&yAttack , &xAttack);
		                printf("\n");
                        attack(board1,xAttack,yAttack,input);
                        sleep(5);
                    }
                    sw11=0;
                    for(i = 0 ; i<input ; i++){
                        for(j = 0 ; j<input ; j++){
                            if (board2[i][j] == 254){
                                sw11 = 1;
                                break;
                            }
                        }
                    }
                  //  if (sw11==0)
                    //    sw1 = 1;
                 //   sw11 = 0;

		}
		if( sw11==0){h=1;}
		if( sw22==0){h=1;}
    } while (h==0);



    fclose(info);




}
