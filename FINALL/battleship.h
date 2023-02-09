//Work of this function : Making screen clear
void clearScreen() {
 	system("cls");
}

//Work of this function : Color the texts
void setTextColor(int textColor, int backColor) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    int colorAttribute = backColor << 4 | textColor;
    SetConsoleTextAttribute(consoleHandle, colorAttribute);
}

//Work of this function : Printing starting text at first
void start(){
setTextColor(7,0);
    printf("Hello\n");
    printf("Welcome \n");
    printf("Enter a number : ");
}

//Work of this function : Put number of row
void putrownumber(int board1[][40],int board2[][40],int input){
    int i,temp;
    temp=1;
	for(i=1 ; i<input+1 ; i++){
        board1[i][0] = temp;
        board2[i][0] = temp;
        temp++ ;
    }
}

//Work of this function : Put number of column
void putcolnumber(int board1[][40],int board2[][40],int input){
	int i,temp;
	temp = 1;
    for(i=1 ; i<input+1 ; i++){
        board1[0][i] = temp ;
        board2[0][i] = temp ;
        temp++ ;
    }
}

//Work of this function : Making all of Board's element empty
void makebaseboards(int board1[][40],int board2[][40],int input){
    int i,j;
	for(i=1 ; i<input+1 ; i++){
        for(j=1 ; j<input+1 ; j++){
            board1[i][j] = 0;
            board2[i][j] = 0;
        }
    }
}

//Work of this function : Put battle in board of player1 according to numbers which are given
void battle(int board1[][40],int xBattle,int yBattle,char direction,int i,int *counterBattlesRemaining1,int battlesNumber){
	if (direction=='h'){                      //These Ifs are for checking that batlles not be on baseboard
        if ((xBattle != 0) && (yBattle != 0))
            board1[xBattle][yBattle]=254;
    	else
            (*counterBattlesRemaining1)--;
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
        printf("\nPlayer1 | remaining battle : %d\n",(battlesNumber-i) );
        printf("\n");
    }
}

//Work of this function : Attacking another player's board to destroy battle
void attack(int board2[][40],int xAttack,int yAttack,int input,int *counterBattlesRemaining2){
	int i,j;
	if (board2[xAttack][yAttack]==254||board2[xAttack][yAttack]==42){
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
		(*counterBattlesRemaining2)--;
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
						setTextColor(9,0);
		                printf("~ ");
		            }
		            else if(board2[i][j]==42){
						setTextColor(12,0);
		                printf("%c ",board2[i][j]);
		            }
		            else if(board2[i][j]==158){
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

//Work of this function : Print two boards together
void printtwoboards(int board1[][40],int board2[][40],int input){
	int i,j;
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
					setTextColor(9,0);
					printf("~ ");
				}
				else if(board1[i][j]==254){
					setTextColor(9,0);
					printf("%c ", board1[i][j]);
				}
				else if(board1[i][j]==42){
                    setTextColor(12,0);
		            printf("%c ",board1[i][j]);
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
					setTextColor(9,0);
					printf("%c ", board2[i][j]);
				}
				else if(board2[i][j]==42){
                    setTextColor(12,0);
		            printf("%c ",board2[i][j]);
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

