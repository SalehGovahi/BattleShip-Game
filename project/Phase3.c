#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Part1 (Difining variables)
    int input,temp=1;
    int i,j,x,y;
    int battlesNumber = 0;
    int counterBattlesRemaining = 0;
    int xBattle , yBattle;
    int xAttack , yAttack;
    char direction;

    printf("Hello\n");
    printf("Welcome \n");
    printf("Enter a number : ");

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

    //Part 6(Printing 2 boards)
    for(j=0 ; j<input+1 ; j++){
        for(i=0 ; i<input+1 ; i++){
            if((i==1) && (j<10)){
                printf(" ");
            }
            if((i != 0)||(j != 0)){
                if(board1[i][j]== 0){
                    if(i>=10){
                        printf(" ");
                    }
                    printf("~ ");
                }
                else{
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
                    printf("~ ");
                }
                else{
                    printf("%d ", board2[i][j]);
                }
            }
            else{
              printf("  ");
            }

        }
        printf("\n");
}
    //Part 7(Getting number of battles)
    printf("\nInput number of battles: ");
    scanf("%d" , &battlesNumber);
    counterBattlesRemaining= battlesNumber*3;

    //Part 8(Getting coordinates & direction of player1 battles)
    printf("\nTurn of Player1\n");
    printf("\nInput coordinates & direction of your battles:\n");

    printf("\n");

    for (i = 1 ; i<=battlesNumber ; i++){
        scanf("%d %d %c", &xBattle , &yBattle , &direction );
        if (direction=='h'){
            board1[xBattle][yBattle]=254;
            board1[xBattle+1][yBattle]=254;
            board1[xBattle-1][yBattle]=254;
        }
        if (direction=='v'){
            board1[xBattle][yBattle]=254;
            board1[xBattle][yBattle-1]=254;
            board1[xBattle][yBattle+1]=254;
        }
        if ((battlesNumber-i) != 0){
            printf("\nPlayer1 | remaining battle : %d\n",(battlesNumber-i) );
            printf("\n");
        }
    }

    printf("\n-------------------------------------------------\n");

    //Part 9(Getting coordinates & direction of player2 battles)
    printf("\nTurn of Player2\n");
    printf("\nInput coordinates & direction of your battles:\n");
    printf("\n");

    for (i = 1 ; i<=battlesNumber ; i++){
        scanf("%d %d %c", &xBattle , &yBattle , &direction );
        if (direction=='h'){
            board2[xBattle][yBattle]=254;
            board2[xBattle+1][yBattle]=254;
            board2[xBattle-1][yBattle]=254;
        }
        if (direction=='v'){
            board2[xBattle][yBattle]=254;
            board2[xBattle][yBattle-1]=254;
            board2[xBattle][yBattle+1]=254;
        }
        if ((battlesNumber-i) != 0){
            printf("\nPlayer2 | remaining battle : %d\n",(battlesNumber-i) );
            printf("\n");
        }
    }

    printf("\n-------------------------------------------------\n");

    do {
        if (counterBattlesRemaining != 0){
        //Attacking player 1
        printf("\nPlayer1 | Try your luck\n\n");
        scanf("%d %d",&yAttack , &xAttack);
        printf("\n");

        if (board2[xAttack][yAttack]==254){
            board2[xAttack][yAttack]=42;
            for(j=0 ; j<input+1 ; j++){
                for(i=0 ; i<input+1 ; i++){
                    if((i==1) && (j<10)){
                        printf(" ");
                    }
                    if((i != 0)||(j != 0)){
                        if(board2[i][j]== 0 || board2[i][j]==254 ){
                            if(i>=10){
                                printf(" ");
                            }
                            printf("~ ");
                        }
                        else if(board2[i][j]==42){
                            printf("%c ",board2[i][j]);
                        }
                        else {
                            printf("%d ", board2[i][j]);
                        }
                    }
                    else{
                        printf("  ");
                    }
                }
                printf("\n");
            }
            counterBattlesRemaining--;
        }
        else{
            board2[xAttack][yAttack]=158;
            for(j=0 ; j<input+1 ; j++){
                for(i=0 ; i<input+1 ; i++){
                    if((i==1) && (j<10)){
                        printf(" ");
                    }
                    if((i != 0)||(j != 0)){
                        if(board2[i][j]== 0 || board2[i][j]==254 ){
                            if(i>=10){
                                printf(" ");
                            }
                            printf("~ ");
                        }
                        else if(board2[i][j]==158){
                            printf("%c ",board2[i][j]);
                        }
                        else {
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
      if (counterBattlesRemaining != 0){
      printf("\nPlayer2 | Try your luck\n\n");
      scanf("%d %d",&yAttack , &xAttack);
      printf("\n");

      if (board1[xAttack][yAttack]==254){
          board1[xAttack][yAttack]=42;
          for(j=0 ; j<input+1 ; j++){
              for(i=0 ; i<input+1 ; i++){
                  if((i==1) && (j<10)){
                      printf(" ");
                  }
                  if((i != 0)||(j != 0)){
                      if(board1[i][j]== 0 || board1[i][j]==254 ){
                          if(i>=10){
                              printf(" ");
                          }
                          printf("~ ");
                      }
                      else if(board1[i][j]==42){
                          printf("%c ",board1[i][j]);
                      }
                      else {
                          printf("%d ", board1[i][j]);
                      }
                  }
                  else{
                      printf("  ");
                  }
              }
              printf("\n");
          }
          counterBattlesRemaining--;
      }
      else{
          board1[xAttack][yAttack]=158;
          for(j=0 ; j<input+1 ; j++){
              for(i=0 ; i<input+1 ; i++){
                  if((i==1) && (j<10)){
                      printf(" ");
                  }
                  if((i != 0)||(j != 0)){
                      if(board1[i][j]== 0 || board1[i][j]==254 ){
                          if(i>=10){
                              printf(" ");
                          }
                          printf("~ ");
                      }
                      else if(board1[i][j]==158){
                          printf("%c ",board1[i][j]);
                      }
                      else {
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
    }
    } while(counterBattlesRemaining != 0);

    return 0;
}
