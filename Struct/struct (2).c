#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

void clearScreen() {
 system("cls");
}

void setTextColor(int textColor, int backColor) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    int colorAttribute = backColor << 4 | textColor;
    SetConsoleTextAttribute(consoleHandle, colorAttribute);
}

void StartingText(){
    setTextColor(7,0);
    printf("\n                                  Hello\n");
    printf("                                 Welcome \n");
    printf("                            Enter a number : ");
}

void PutRowNumber(int board1[][40],int board2[][40],int input){
    int i,temp;
    temp=1;
    for(i=1 ; i<input+1 ; i++){
        board1[i][0] = temp;
        board2[i][0] = temp;
        temp++ ;
    }
}

void PutColNumber(int board1[][40],int board2[][40],int input){
    int i,temp;
    temp = 1;
    for(i=1 ; i<input+1 ; i++){
        board1[0][i] = temp ;
        board2[0][i] = temp ;
        temp++ ;
    }
}

void MakeBaseBoards(int board1[][40],int board2[][40],int input){
    int i,j;
    for(i=1 ; i<input+1 ; i++){
        for(j=1 ; j<input+1 ; j++){
            board1[i][j] = 0;
            board2[i][j] = 0;
        }
    }
  }

void PlaceBattle1(int board1[][40],int xBattle,int yBattle,char direction,int i,int battlesNumber){
if (direction=='h'){                      //These Ifs are for checking that batlles not be on baseboard
          if ((xBattle != 0) && (yBattle != 0))
              board1[xBattle][yBattle]=254;
          if ((xBattle+1 != 0) && (yBattle != 0))
              board1[xBattle+1][yBattle]=254;
          if ((xBattle-1 != 0) && (yBattle != 0))
              board1[xBattle-1][yBattle]=254;
        }
        if (direction=='v'){                      //These Ifs are for checking that batlles not be on baseboard
            if ((xBattle != 0) && (yBattle != 0))
                board1[xBattle][yBattle]=254;
            if ((xBattle != 0) && (yBattle-1 != 0))
                board1[xBattle][yBattle-1]=254;
            if ((xBattle != 0) && (yBattle+1 != 0))
                board1[xBattle][yBattle+1]=254;
        }
        if ((battlesNumber-i) != 0){
					  setTextColor(7,0);
            printf("\n\n                             Remaining battle : %d\n",(battlesNumber-i) );
						printf("\n                 Input coordinates & direction of your battles:");
        }


}

void PlaceBattle2(int board2[][40],int xBattle,int yBattle,char direction,int i,int battlesNumber){
if (direction=='h'){                      //These Ifs are for checking that batlles not be on baseboard
          if ((xBattle != 0) && (yBattle != 0))
              board2[xBattle][yBattle]=254;
          if ((xBattle+1 != 0) && (yBattle != 0))
              board2[xBattle+1][yBattle]=254;
          if ((xBattle-1 != 0) && (yBattle != 0))
              board2[xBattle-1][yBattle]=254;
        }
        if (direction=='v'){                      //These Ifs are for checking that batlles not be on baseboard
            if ((xBattle != 0) && (yBattle != 0))
                board2[xBattle][yBattle]=254;
            if ((xBattle != 0) && (yBattle-1 != 0))
                board2[xBattle][yBattle-1]=254;
            if ((xBattle != 0) && (yBattle+1 != 0))
                board2[xBattle][yBattle+1]=254;
        }
        if ((battlesNumber-i) != 0){
					  setTextColor(7,0);
            printf("\n\n                             Remaining battle : %d\n",(battlesNumber-i) );
						printf("\n                 Input coordinates & direction of your battles:");
        }


}
void attack(int board2[][40],int xAttack,int yAttack,int input){
int i,j;
if (board2[xAttack][yAttack]==254){
		            board2[xAttack][yAttack]=42;
		            for(j=0 ; j<input+1 ; j++){
                    printf("                             ");
		                for(i=0 ; i<input+1 ; i++){
		                    if((i==1) && (j<10)){
		                        printf(" ");
		                    }
		                    if((i != 0)||(j != 0)){
		                        if(board2[i][j]== 0 || board2[i][j]==254 ){
		                            if(i>=10){
		                                printf(" ");
		                            }
																setTextColor(9,0);
		                            printf("~ ");
		                        }
		                        else if(board2[i][j]==42){
															  setTextColor(12,0);
		                            printf("%c ",board2[i][j]);
		                        }
		                        else {
															  setTextColor(7,0);
		                            printf("%d ", board2[i][j]);
		                        }
		                    }
		                    else{
		                        printf("  ");
		                    }
		                }
		                printf("\n");
		            }
		            //(*counterBattlesRemaining2)--;
		        }
		        else{
		            board2[xAttack][yAttack]=111;
		            for(j=0 ; j<input+1 ; j++){
                    printf("                             ");
		                for(i=0 ; i<input+1 ; i++){
		                    if((i==1) && (j<10)){
		                        printf(" ");
		                    }
		                    if((i != 0)||(j != 0)){
		                        if(board2[i][j]== 0 || board2[i][j]==254 ){
		                            if(i>=10){
		                                printf(" ");
		                            }
																setTextColor(9,0);
		                            printf("~ ");
		                        }
		                        else if(board2[i][j]==42){
															  setTextColor(12,0);
		                            printf("%c ",board2[i][j]);
		                        }
		                        else if(board2[i][j]==111){
															  setTextColor(7,0);
		                            printf("%c ",board2[i][j]);
		                        }
		                        else {
															  setTextColor(7,0);
		                            printf("%d ", board2[i][j]);
		                        }
		                    }
		                    else{
		                        printf("  ");
		                    }
		              }
		              printf("\n");
		          }
		          board2[xAttack][yAttack]=0;
		      }

}
void PrintTwoBoards(int board1[][40],int board2[][40],int input){
int i,j;
printf("                   Player1                        Player2\n\n");
for(j=0 ; j<input+1 ; j++){
        printf("            ");
				for(i=0 ; i<input+1 ; i++){
						if((i==1) && (j<10)){
								printf(" ");
						}
						if((i != 0)||(j != 0)){
								if(board1[i][j]== 0){
										if(i>=10){
												printf(" ");
										}
								setTextColor(9,0);
								printf("~ ");
								}
								else if(board1[i][j]==254){
										setTextColor(7,0);
										printf("%c ", board1[i][j]);
								}
								else{
										setTextColor(7,0);
										printf("%d ", board1[i][j]);
								}
						}
						else{
								printf("  ");
						}

				}
		//Seperate board2 from board1
				printf("          ");

				for(i=0 ; i<input+1 ; i++){
						if((i==1) && (j<10)){
								printf(" ");
						}
						if((i != 0)||(j != 0)){
								if(board2[i][j]== 0){
										if(i>=10){
												printf(" ");
										}
										setTextColor(9,0);
										printf("~ ");
								}
								else if(board2[i][j]==254){
										setTextColor(7,0);
										printf("%c ", board2[i][j]);
								}
								else{
										setTextColor(7,0);
										printf("%d ", board2[i][j]);
								}
						}
						else{
								printf("  ");
						}

				}
		printf("\n");
		}

}

struct ship{
int y;
int x;
char d;

};

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
    int cp1,cp2;
    cp1=0;cp2=0;
    int n1,n2;
    n1=0,n2=0;
    char direction;
    int sw=0;
    char temp1[100];
    struct ship p1[100],p2[100];

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
        p1[cp1].x=xBattle;
        p1[cp1].y=yBattle;
        p1[cp1].d=direction;
        cp1++;


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
        p2[cp2].x=xBattle;
        p2[cp2].y=yBattle;
        p2[cp2].d=direction;
        cp2++;
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

           // counting ships of player1
for(i=0;i<cp1;i++){
    switch(p1[i].d){
case 'h':
    if((board1[p1[i].x][p1[i].y]==42)&&(board1[p1[i].x+1][p1[i].y]==42)&&(board1[p1[i].x-1][p1[i].y]==42)){
                n1++;

    }
    break;
case 'v':
    if((board1[p1[i].x][p1[i].y]==42)&&(board1[p1[i].x][p1[i].y+1]==42)&&(board1[p1[i].x][p1[i].y-1]==42)){
                n1++;

    }

        break;



    }


}
 // counting ships of player2
for(i=0;i<cp2;i++){
    switch(p2[i].d){
case 'h':
    if((board2[p2[i].x][p2[i].y]==42)&&(board2[p2[i].x+1][p2[i].y]==42)&&(board2[p2[i].x-1][p2[i].y]==42)){
                n2++;

    }
    break;
case 'v':
    if((board2[p2[i].x][p2[i].y]==42)&&(board2[p2[i].x][p2[i].y+1]==42)&&(board2[p2[i].x][p2[i].y-1]==42)){
                n2++;

    }

        break;



    }


}
    return 0;
}
