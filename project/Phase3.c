#include <stdio.h>
#include <stdlib.h>
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

int main()
{
    //Part1 (Difining variables)
    int input,temp=1;
    int i,j,x,y;
    int battlesNumber = 0;
    int counterBattlesRemaining1 = 0;
    int counterBattlesRemaining2 = 0;
    int xBattle , yBattle;
    int xAttack , yAttack;
    char direction;

		setTextColor(7,0);
    printf("\n                                  Hello\n");
    printf("                                 Welcome \n");
    printf("                            Enter a number : ");

    scanf("%d",&input);
    printf("\n");

    //Part 2(Making 2 board with input+1 row & input+1 col)
    int board1[input+1][input+1];
    int board2[input+1][input+1];


    //Part 3(Putting row number)
    for(i=1 ; i<input+1 ; i++){
        board1[i][0] = temp;
        board2[i][0] = temp;
        temp++ ;
    }

    //Part 4(Putting col number)
    temp = 1;

    for(i=1 ; i<input+1 ; i++){
        board1[0][i] = temp ;
        board2[0][i] = temp ;
        temp++ ;
    }

    //Part 5(Making base boards)
    for(i=1 ; i<input+1 ; i++){
        for(j=1 ; j<input+1 ; j++){
            board1[i][j] = 0;
            board2[i][j] = 0;
        }
    }

		clearScreen();
		//Part 7(Getting number of battles)
		clearScreen();
		setTextColor(7,0);

    //Part 7(Getting number of battles)
    printf("\n                        Input number of battles: ");
    scanf("%d" , &battlesNumber);
    counterBattlesRemaining1= battlesNumber*3;
    counterBattlesRemaining2= battlesNumber*3;

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
        if ((battlesNumber-i) != 0){
					  setTextColor(7,0);
						printf("\n\n                             Remaining battle : %d\n",(battlesNumber-i) );
						printf("\n                 Input coordinates & direction of your battles:");
        }
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
        if ((battlesNumber-i) != 0){
					printf("\n\n                             Remaining battle : %d\n",(battlesNumber-i) );
					printf("\n                 Input coordinates & direction of your battles:");
        }
    }
		clearScreen();

		printf("\n");
    printf("                   Player1                        Player2\n\n");
		//Part 6(Printing 2 boards)
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
		sleep(3);
		    clearScreen();

		    //Start attacking
		    do {
		        if (counterBattlesRemaining1 != 0 && counterBattlesRemaining2 != 0){
						clearScreen();
		        //Attacking player 1
						setTextColor(7,0);
		        printf("\n                            Player1 | Try your luck\n");
						printf("\n                                     ");
		        scanf("%d %d",&yAttack , &xAttack);
		        printf("\n");

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
		            counterBattlesRemaining2--;
								setTextColor(7,0);
								if (counterBattlesRemaining2%3==0 && counterBattlesRemaining2!=0)
								    printf("\nOne of Player2's battle drowned\n");
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


		      //Attacking player 2
		      if (counterBattlesRemaining2 != 0 && counterBattlesRemaining1 != 0){
					sleep(5);
					clearScreen();
					setTextColor(7,0);
					printf("\n                            Player2 | Try your luck\n");
					printf("\n                                     ");
					scanf("%d %d",&yAttack , &xAttack);
					printf("\n");

		      if (board1[xAttack][yAttack]==254){
		          board1[xAttack][yAttack]=42;
		          for(j=0 ; j<input+1 ; j++){
								  printf("                             ");
		              for(i=0 ; i<input+1 ; i++){
		                  if((i==1) && (j<10)){
		                      printf(" ");
		                  }
		                  if((i != 0)||(j != 0)){
		                      if(board1[i][j]== 0 || board1[i][j]==254 ){
		                          if(i>=10){
		                              printf(" ");
		                          }
															setTextColor(9,0);
		                          printf("~ ");
		                      }
		                      else if(board1[i][j]==42){
														  setTextColor(12,0);
		                          printf("%c ",board1[i][j]);
		                      }
		                      else {
														  setTextColor(7,0);
		                          printf("%d ", board1[i][j]);
		                      }
		                  }
		                  else{
		                      printf("  ");
		                  }
		              }
		              printf("\n");
		          }
		          counterBattlesRemaining1--;
							setTextColor(7,0);
							if (counterBattlesRemaining1%3==0 && counterBattlesRemaining1!=0)
									printf("\nOne of Player1's battle drowned\n");
		      }
		      else{
		          board1[xAttack][yAttack]=111;
		          for(j=0 ; j<input+1 ; j++){
								  printf("                             ");
		              for(i=0 ; i<input+1 ; i++){
		                  if((i==1) && (j<10)){
		                      printf(" ");
		                  }
		                  if((i != 0)||(j != 0)){
		                      if(board1[i][j]== 0 || board1[i][j]==254 ){
		                          if(i>=10){
		                              printf(" ");
		                          }
															setTextColor(9,0);
		                          printf("~ ");
		                      }
		                      else if(board1[i][j]==42){
														  setTextColor(12,0);
		                          printf("%c ",board1[i][j]);
		                      }
		                      else if(board1[i][j]==111){
														  setTextColor(7,0);
		                          printf("%c ",board1[i][j]);
		                      }
		                      else {
														  setTextColor(7,0);
		                          printf("%d ", board1[i][j]);
		                      }
		                  }
		                  else{
		                      printf("  ");
		                  }
		            }
		            printf("\n");
		        }
		        board1[xAttack][yAttack]=0;
		    }
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
