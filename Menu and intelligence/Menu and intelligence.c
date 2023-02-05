#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include<battleship.h>
struct xy{
int x;
int y;

};
struct battle{
int a[3];
struct xy n[3];
};

int main()
{
    srand(time(0));
    //Part1 (Difining variables)
    int input,temp=1;
    int i,j,x,y,n,menu,ran,co1,co2;
    co1=0;
    co2=0;
    int battlesNumber = 0;
    int counterBattlesRemaining1 = 0;
    int counterBattlesRemaining2 = 0;
    int xBattle , yBattle;
    int xAttack , yAttack;
    char direction;



  printf("                      WELCOME TO BATTLESHIP \n ");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  printf("                              enter District of your table:");



    scanf("%d",&input);
    printf("\n");
    if(input<=2){input=3;}
    n=input;
  printf("                        choose your opponent\n");
  printf("                             1-your friend\n");
  printf("                             2-computer(easy)\n");
  printf("                             3-computer(hard)\n");
  scanf("%d",&menu);

    //Part 2(Making 2 board with input+1 row & input+1 col)
    int board1[40][40];
    int board2[40][40];


    //Part 3(Putting row number)
    putrownumber(board1,board2,input);

    //Part 4(Putting col number)
    putcolnumber(board1,board2,input);

    //Part 5(Making base boards)
    makebaseboards(board1,board2,input);

		clearScreen();
		printf("\n");
		//Part 6(Printing 2 boards)
		printtwoboards(board1,board2,input);
		//Part 7(Getting number of battles)
		//sleep(5);
		clearScreen();
		setTextColor(7,0);

    //Part 7(Getting number of battles)
    printf("\nInput number of battles: ");
    scanf("%d" , &battlesNumber);
    counterBattlesRemaining1= battlesNumber*3;
    counterBattlesRemaining2= battlesNumber*3;

		clearScreen();
    //Part 8(Getting coordinates & direction of player1 battles)
    printf("\nTurn of Player1\n");
    printf("\nInput coordinates & direction of your battles:\n");

    printf("\n");

    for (i = 1 ; i<=battlesNumber ; i++){
        scanf("%d %d %c", &yBattle , &xBattle , &direction );
        if((yBattle<=1)&&(direction=='v')){yBattle=2;}
        if((yBattle>=n)&&(direction=='v')){yBattle=n-1;}
        if((xBattle<=1)&&(direction=='h')){xBattle=2;}
        if((xBattle>=n)&&(direction=='h')){xBattle=n-1;}
        battle(board1,xBattle,yBattle,direction,i,&counterBattlesRemaining1,battlesNumber);

    }

    clearScreen();

    //Part 9(Getting coordinates & direction of player2 battles)
		setTextColor(7,0);
    printf("\nTurn of Player2\n");
    printf("\nInput coordinates & direction of your battles:\n");
    printf("\n");

    for (i = 1 ; i<=battlesNumber ; i++){
            switch(menu){
            case 1:
                scanf("%d %d %c", &yBattle , &xBattle , &direction );
        if((yBattle<=1)&&(direction=='v')){yBattle=2;}
        if((yBattle>=n)&&(direction=='v')){yBattle=n-1;}
        if((xBattle<=1)&&(direction=='h')){xBattle=2;}
        if((xBattle>=n)&&(direction=='h')){xBattle=n-1;}
        battle(board2,xBattle,yBattle,direction,i,&counterBattlesRemaining2,battlesNumber);

                break;
            case 2:
            ran=rand();
            xBattle=ran%9+1;
            ran=rand();
            yBattle=ran%9+1;
            ran=rand();
            if((ran%2)==0){direction='v';}else{direction='h';}
            if((yBattle<=1)&&(direction=='v')){yBattle=2;}
        if((yBattle>=n)&&(direction=='v')){yBattle=n-1;}
        if((xBattle<=1)&&(direction=='h')){xBattle=2;}
        if((xBattle>=n)&&(direction=='h')){xBattle=n-1;}
        battle(board2,xBattle,yBattle,direction,i,&counterBattlesRemaining2,battlesNumber);


                break;
            case 3:
                 ran=rand();
            xBattle=ran%9+1;
            ran=rand();
            yBattle=ran%9+1;
            ran=rand();
            if((ran%2)==0){direction='v';}else{direction='h';}
            if((yBattle<=1)&&(direction=='v')){yBattle=2;}
        if((yBattle>=n)&&(direction=='v')){yBattle=n-1;}
        if((xBattle<=1)&&(direction=='h')){xBattle=2;}
        if((xBattle>=n)&&(direction=='h')){xBattle=n-1;}
        battle(board2,xBattle,yBattle,direction,i,&counterBattlesRemaining2,battlesNumber);

                break;

            }

    }
		clearScreen();

		printf("\n");

		//Part 6(Printing 2 boards)
		printtwoboards(board1,board2,input);
		sleep(10);
		    clearScreen();

		    //Start attacking
		    do {
		        if (counterBattlesRemaining1 != 0 && counterBattlesRemaining2 != 0){
						clearScreen();
		        //Attacking player 1
						setTextColor(7,0);
		        printf("\nPlayer1 | Try your luck\n\n");
		        scanf("%d %d",&yAttack , &xAttack);
		        printf("\n");
 attack(board2,xAttack,yAttack,input,&counterBattlesRemaining2);
		      }


		      //Attacking player 2
		      if (counterBattlesRemaining2 != 0 && counterBattlesRemaining1 != 0){
					sleep(5);
					clearScreen();
					setTextColor(7,0);
		      printf("\nPlayer2 | Try your luck\n\n");
		      //sleep(3);
		      //xAttack = printRandoms(1 , input , 1);
		      //yAttack = printRandoms(1 , input , 1);
		      switch(menu){
        case 1:
            scanf("%d %d",&yAttack , &xAttack);
            break;
        case 2:
            ran=rand();
            xBattle=ran%9+1;
            ran=rand();
            yBattle=ran%9+1;
            break;
        case 3:
            // is loading
            break;
		      }

					printf("\n");
attack(board1,xAttack,yAttack,input,&counterBattlesRemaining1);
				sleep(5);
		    }
		  } while(counterBattlesRemaining1 != 0 && counterBattlesRemaining2 != 0);
		    setTextColor(7,0);
		    if (counterBattlesRemaining1==0)
		        printf("\nPlayer2 won\n");
		    if (counterBattlesRemaining2==0)
		        printf("\nPlayer1 won\n");


    return 0;
}
