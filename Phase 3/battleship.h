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
