#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "battleship.h"

//These structs helps to find destroyed battle
struct xy{
	int x;
	int y;
	int a;
};
struct battle{
	struct xy n[3];
};

//
int sear(int x,int y,struct battle a[],int co){
	int i,k;
	for(i=0;i<co;i++){
    	for(k=0;k<3;k++){
        	if((a[i].n[k].x==x)&&(a[i].n[k].y==y)){
				return i;
			}
    	}
	}
}


int main()
{
    srand(time(0));
    //Defining variables
    int input,temp=1;
    int i,j,x,y,n,menu,ran,co1,co2,co3,co4,ch,h,k,o,xx,yy;
    co1=0;
    co2=0;
    co3=0;
    co4=0;
    ch=0;
    int numberofdestroyedbattles1,numberofdestroyedbattles2,counterofdestroyedbattles;
    numberofdestroyedbattles1=0;
    numberofdestroyedbattles2=0;
    int battlesNumber = 0;
    int counterBattlesRemaining1 = 0;
    int counterBattlesRemaining2 = 0;
    int xBattle , yBattle;
    int xAttack , yAttack;
    char direction;
    int chartemp;
    int chartemp1;
    int tmpChar1;
    int repair;
    int repairPlayer2;
    int repairPlayer1;
    struct battle b[100];
    struct battle a[100];


	//Defining 2 board
    int board1[40][40];
    int board2[40][40];

  	printf("WELCOME TO BATTLESHIP\n");
  	printf("~~~~~~~~~~~~~~~~~~~~~~");
  	
  	printf("\nDo you want to play your last saved games?(1 to accept \ 0 to deny)\n");
  	scanf("%d" , &chartemp);
  	
	clearScreen();
  	
	if (chartemp==1){
		//Opening file to read the last save
  	    FILE* info;
        info = fopen("info.dat" ,"rb" );

        fread(&input,sizeof(int),1,info);

        fread(&menu,sizeof(int),1,info);

        fread(&battlesNumber,sizeof(int),1,info);

        if (menu==1){
            fread(&repairPlayer1,sizeof(int),1,info);
            fread(&repairPlayer2,sizeof(int),1,info);
        }

        fread(&a,sizeof(struct battle),1,info);
        fread(&b,sizeof(struct battle),1,info);

        fread(&co1,sizeof(int) , 1 , info);
        fread(&co3,sizeof(int) , 1 , info);

        fread(board1 , sizeof(int) , 1600,info);

        fread(board2 , sizeof(int) , 1600,info);

        fclose(info);
        
		//Putting row number
        putrownumber(board1,board2,input);

        //Putting col number
        putcolnumber(board1,board2,input);

        clearScreen();
		
		//Counter the remaining battles
        for(i = 0 ; i<=input ; i++){
            for (j = 0 ; j<=input ; j++){
                if (board1[i][j]==254){
                    counterBattlesRemaining1++;
                }
            }
        }
        for(i = 0 ; i<=input ; i++){
            for (j = 0 ; j<=input ; j++){
                if (board2[i][j]==254){
                    counterBattlesRemaining2++;
                }
            }
        }
        
		clearScreen();


		//Start attacking
		do {
			//Attacking player1
		    if (counterBattlesRemaining1 != 0 && counterBattlesRemaining2 != 0){
				
				clearScreen();
				setTextColor(7,0);
                
				if (menu==1){
                    printf("\nPlayer1 | Try your luck\n");
                    printf("\nDo you want to repair your battle?(1 to accept /0 to deny)");
                    scanf("%d" , &tmpChar1);
                    if (tmpChar1 == 1){
                        if (repairPlayer1 == 0){
                            printf("\nYou have done all your allowed repair");
                            sleep(5);
                            clearScreen();
                            printf("\nAttack player2\n");
                            printf("\n");
                            scanf("%d %d",&yAttack , &xAttack);
		                    if ((xAttack<=input) && (yAttack<=input) && (xAttack>0) && (yAttack>0)){
                    			printf("\n");
                    			attack(board2,xAttack,yAttack,input,&counterBattlesRemaining2);
		        			}
		        			else{
                    			printf("\nOut of range\n");
		        			}
                            sleep(5);
                        }
                        else{
                            printf("Repair your battle:");
                            scanf("%d %d",&yAttack , &xAttack);
                            board1[xAttack][yAttack] = 254;
                            repairPlayer1--;
                        }
                    }
                    else if (tmpChar1 == 0){
                        printf("\nAttack player2\n");
                        printf("\n");
                        scanf("%d %d",&yAttack , &xAttack);
		                if ((xAttack<=input) && (yAttack<=input) && (xAttack>0) && (yAttack>0)){
                    		printf("\n");
                    		attack(board2,xAttack,yAttack,input,&counterBattlesRemaining2);
		        		}
		        		else{
                    		printf("\nOut of range\n");
		        		}
                        sleep(5);
                    }
            	}
                else{
                    printf("\nAttack player2\n");
                    printf("\n");
                    scanf("%d %d",&yAttack , &xAttack);
		            if ((xAttack<=input) && (yAttack<=input) && (xAttack>0) && (yAttack>0)){
                    	printf("\n");
                    	attack(board2,xAttack,yAttack,input,&counterBattlesRemaining2);
		        	}

		        	else{
                    	printf("\nOut of range\n");
		        	}
                }
			}
            setTextColor(7,0);
		    


		    //Attacking player 2
		    if (counterBattlesRemaining2 != 0 && counterBattlesRemaining1 != 0){
				sleep(5);
				clearScreen();
				setTextColor(7,0);
		      	printf("\nPlayer2 | Try your luck\n\n");
		      	switch(menu){
        			case 1:
            			if (menu==1){
                        	//printf("\nPlayer2 | Try your luck\n");
                    		printf("\nDo you want to repair your battle?(1 to accept /0 to deny)\n");
                    		scanf("%d" , &tmpChar1);
                    		if (tmpChar1 == 1){
                        		if (repairPlayer2 == 0){
                            	printf("\nYou have done all your allowed repair");
                            	sleep(5);
                            	clearScreen();
                            	printf("\nAttack player1\n");
                            	printf("\n");
                            	scanf("%d %d",&yAttack , &xAttack);
                            	if ((xAttack<=input) && (yAttack<=input) && (xAttack>0) && (yAttack>0)){
                    				printf("\n");
                    				attack(board1,xAttack,yAttack,input,&counterBattlesRemaining1);
		        				}
		        				else{
                    			printf("\nOut of range\n");
		        				}
                            	sleep(5);
                        	}
                        		else{
                            		printf("Repair your battle:");
                            		scanf("%d %d",&yAttack , &xAttack);
                            		board2[xAttack][yAttack] = 254;
                            		repairPlayer2--;
                        		}
                    		}
                    		else if (tmpChar1 == 0){
                        		printf("\nAttack player1\n");
                        		printf("\n");
                        		scanf("%d %d",&yAttack , &xAttack);
		                		printf("\n");
                        		if ((xAttack<=input) && (yAttack<=input) && (xAttack>0) && (yAttack>0)){
                    				printf("\n");
                    				attack(board1,xAttack,yAttack,input,&counterBattlesRemaining1);
		        				}

		        				else{
                    				printf("\nOut of range\n");
		        				}
                        		sleep(5);
                    		}
                    	}
        			case 2:
            			ran=rand();
            			xAttack=ran%input+1;
            			ran=rand();
            			yAttack=ran%input+1;
            			attack(board1,xAttack,yAttack,input,&counterBattlesRemaining1);
            break;
        case 3:
            if(ch==0){
                ran=rand();
            	xAttack=ran%input+1;
            	ran=rand();
            	yAttack=ran%input+1;
            	if(board1[xAttack][yAttack]==254){
					ch=2;
					h=sear(xAttack,yAttack,b,co1);
            		for(o=0;o<3;o++){ 
						if(b[h].n[o].x==xAttack && b[h].n[o].y==yAttack){
							b[h].n[o].a=1;
						}	 
					}
            	}
            }
			else{
                k=0;
                while(1){
                    if(b[h].n[k].a==0){
						xAttack=b[h].n[k].x;
						yAttack=b[h].n[k].y;
						b[h].n[k].a=1;
						break;
					}
					else{
                        k++;
					}
                    if(k>2){
                    	break;
					}
                }
                ch--;
            }
            attack(board1,xAttack,yAttack,input,&counterBattlesRemaining1);
            break;
        case 4:
            if(ch==0){
            	ran=rand();
            	xAttack=ran%input+1;
            	ran=rand();
            	yAttack=ran%input+1;
            	if(board1[xAttack][yAttack]==254){
					ch=8;
					xx=xAttack;
					yy=yAttack;
				}
            }
			else{
                if(ch==5){xAttack=xx-1;yAttack=yy;ch--;if(xAttack>=input+1||xAttack<=0||yAttack>=input+1||yAttack<=0){ran=rand();xAttack=ran%(input)+1;ran=rand();yAttack=ran%(input)+1;} }
                if(ch==6){xAttack=xx;yAttack=yy-1;ch--;if(xAttack>=input+1||xAttack<=0||yAttack>=input+1||yAttack<=0){ran=rand();xAttack=ran%(input)+1;ran=rand();yAttack=ran%(input)+1;} }
                if(ch==7){xAttack=xx;yAttack=yy+1;ch--;if(xAttack>=input+1||xAttack<=0||yAttack>=input+1||yAttack<=0){ran=rand();xAttack=ran%(input)+1;ran=rand();yAttack=ran%(input)+1;} }
                if(ch==8){xAttack=xx+1;yAttack=yy;ch--;if(xAttack>=input+1||xAttack<=0||yAttack>=input+1||yAttack<=0){ran=rand();xAttack=ran%(input)+1;ran=rand();yAttack=ran%(input)+1;} }
                if(ch==1){xAttack=xx-2;yAttack=yy;ch--;if(xAttack>=input+1||xAttack<=0||yAttack>=input+1||yAttack<=0){ran=rand();xAttack=ran%(input)+1;ran=rand();yAttack=ran%(input)+1;} }
                if(ch==2){xAttack=xx;yAttack=yy-2;ch--;if(xAttack>=input+1||xAttack<=0||yAttack>=input+1||yAttack<=0){ran=rand();xAttack=ran%(input)+1;ran=rand();yAttack=ran%(input)+1;} }
                if(ch==3){xAttack=xx;yAttack=yy+2;ch--;if(xAttack>=input+1||xAttack<=0||yAttack>=input+1||yAttack<=0){ran=rand();xAttack=ran%(input)+1;ran=rand();yAttack=ran%(input)+1;} }
                if(ch==4){xAttack=xx+2;yAttack=yy;ch--;if(xAttack>=input+1||xAttack<=0||yAttack>=input+1||yAttack<=0){ran=rand();xAttack=ran%(input)+1;ran=rand();yAttack=ran%(input)+1;} }


            }
            attack(board1,xAttack,yAttack,input,&counterBattlesRemaining1);
            break;
		      	}
		      	printf("\n");
                
				
				printf("\n");
				sleep(5);
				
				printf("Do you want to save your game?(1 to accept , 0 to deny)");
            	scanf("%d" , &chartemp1);
            	if (chartemp1== 1){
                    info = fopen("info.dat" ,"wb" );
                	fwrite(&input,sizeof(int),1,info);
                	fwrite(&menu,sizeof(int),1,info);
                	fwrite(&battlesNumber,sizeof(int),1,info);
                	if (menu==1){
                   		fwrite(&repairPlayer1,sizeof(int),1,info);
                   		fwrite(&repairPlayer2,sizeof(int),1,info);
                	}
                	fwrite(&a,sizeof(struct battle),1,info);
                	fwrite(&b,sizeof(struct battle),1,info);
                	fwrite(board1,sizeof(int),1600,info);
                	fwrite(board2,sizeof(int),1600,info);
            	}

            sleep(5);
		    }
		} while(counterBattlesRemaining1 != 0 && counterBattlesRemaining2 != 0);
		    setTextColor(7,0);
		    if (counterBattlesRemaining1==0)
		        printf("\nPlayer2 won\n");
		    if (counterBattlesRemaining2==0)
		        printf("\nPlayer1 won\n");

            fclose(info);
  	}
  	else if (chartemp==0){
        FILE* info;
        info = fopen("info.dat" ,"wb" );
        clearScreen();
        printf("Enter district of your table:");
        scanf("%d",&input);
        printf("\n");
        if(input<=2)
            input=3;
        n=input;

        printf("Choose your opponent\n");
        printf("1-Your friend\n");
        printf("2-Computer(easy)\n");
        printf("3-Computer(hard)\n");
        printf("4-Computer(medium)\n\n");

        scanf("%d",&menu);
        //Defining 2 board
        int board1[40][40];
        int board2[40][40];


        //Putting row number
        putrownumber(board1,board2,input);

        //Putting col number
        putcolnumber(board1,board2,input);

        //Making base boards
        makebaseboards(board1,board2,input);

        printf("\n");
	
		clearScreen();
		setTextColor(7,0);

    	//Part 7(Getting number of battles)
    	printf("\nInput number of battles: ");
    	scanf("%d" , &battlesNumber);
    	counterBattlesRemaining1= battlesNumber*3;
    	counterBattlesRemaining2= battlesNumber*3;

		clearScreen();
		if (menu==1){
        	printf("Times of repair:");
        	scanf("%d" , &repair);
        	repairPlayer2 = repair;
        	repairPlayer1 = repair;
		}
    //Getting coordinates & direction of player1 battles
    printf("\nTurn of Player1\n");
    printf("\nInput coordinates & direction of your battles:\n");

    printf("\n");

    for (i = 1 ; i<=battlesNumber ; i++){
        scanf("%d %d %c", &yBattle , &xBattle , &direction );
        if (((xBattle<=input) && (yBattle<=input) && (xBattle>0) && (yBattle>0)) && ((direction=='h') || (direction=='v'))){
            if((yBattle<=1)&&(direction=='v')){yBattle=2;}
        	if((yBattle>=n)&&(direction=='v')){yBattle=n-1;}
        	if((xBattle<=1)&&(direction=='h')){xBattle=2;}
        	if((xBattle>=n)&&(direction=='h')){xBattle=n-1;}
        	battle(board1,xBattle,yBattle,direction,i,&counterBattlesRemaining1,battlesNumber);
        	b[co1].n[co2].x=xBattle;
        	b[co1].n[co2].y=yBattle;
        	b[co1].n[co2].a=0;
        	if(direction=='v'){
            	co2++;
        		b[co1].n[co2].x=xBattle;
        		b[co1].n[co2].y=yBattle+1;
        		b[co1].n[co2].a=0;
           		co2++;
        		b[co1].n[co2].x=xBattle;
        		b[co1].n[co2].y=yBattle-1;
        		b[co1].n[co2].a=0;
        	}
        	if(direction=='h'){
            	co2++;
        		b[co1].n[co2].x=xBattle+1;
        		b[co1].n[co2].y=yBattle;
        		b[co1].n[co2].a=0;
           		co2++;
        		b[co1].n[co2].x=xBattle-1;
        		b[co1].n[co2].y=yBattle;
        		b[co1].n[co2].a=0;
        	}
    		co2=0;
    		co1++;
    	}
    	else{
            printf("Invalid input.Try again\n");
            i--;
        }
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
            xBattle=ran%input+1;
            ran=rand();
            yBattle=ran%input+1;
            ran=rand();
            if((ran%2)==0){direction='v';}else{direction='h';}
        if((yBattle<=1)&&(direction=='v')){yBattle=2;}
        if((yBattle>=n)&&(direction=='v')){yBattle=n-1;}
        if((xBattle<=1)&&(direction=='h')){xBattle=2;}
        if((xBattle>=n)&&(direction=='h')){xBattle=n-1;}
        battle(board2,xBattle,yBattle,direction,i,&counterBattlesRemaining2,battlesNumber);


                break;
            case 3:
            case 4:
                 ran=rand();
            xBattle=ran%input+1;
            ran=rand();
            yBattle=ran%input+1;
            ran=rand();
            if((ran%2)==0){direction='v';}else{direction='h';}
            if((yBattle<=1)&&(direction=='v')){yBattle=2;}
        if((yBattle>=n)&&(direction=='v')){yBattle=n-1;}
        if((xBattle<=1)&&(direction=='h')){xBattle=2;}
        if((xBattle>=n)&&(direction=='h')){xBattle=n-1;}
        battle(board2,xBattle,yBattle,direction,i,&counterBattlesRemaining2,battlesNumber);

                break;

            }
        a[co3].n[co4].x=xBattle;
        a[co3].n[co4].y=yBattle;
        a[co3].n[co4].a=0;
        if(direction=='v'){
            co4++;
        a[co3].n[co4].x=xBattle;
        a[co3].n[co4].y=yBattle+1;
        a[co3].n[co4].a=0;
           co4++;
        a[co3].n[co4].x=xBattle;
        a[co3].n[co4].y=yBattle-1;
        a[co3].n[co4].a=0;
        }
        if(direction=='h'){
            co4++;
        a[co3].n[co4].x=xBattle+1;
        a[co3].n[co4].y=yBattle;
        a[co3].n[co4].a=0;
           co4++;
        a[co3].n[co4].x=xBattle-1;
        a[co3].n[co4].y=yBattle;
        a[co3].n[co4].a=0;
        }
    co4=0;
    co3++;

    }
		clearScreen();

		printf("\n");

		//Part 6(Printing 2 boards)
		//printtwoboards(board1,board2,input);
		//sleep(10);
		    clearScreen();

		    //Start attacking
		    do {
		        if (counterBattlesRemaining1 != 0 && counterBattlesRemaining2 != 0){
					clearScreen();
					setTextColor(7,0);
                    if (menu==1){
                        printf("\nPlayer1 | Try your luck\n");
                    printf("\nDo you want to repair your battle?(1 to accept /0 to deny)\n");
                    scanf("%d" , &tmpChar1);
                    if (tmpChar1 == 1){
                        if (repairPlayer1 == 0){
                            printf("\nYou have done all your allowed repair");
                            sleep(5);
                            clearScreen();
                            printf("\nAttack player2\n");
                            printf("\n");
                            scanf("%d %d",&yAttack , &xAttack);
		                    if ((xAttack<=input) && (yAttack<=input) && (xAttack>0) && (yAttack>0)){
                    printf("\n");
                    attack(board2,xAttack,yAttack,input,&counterBattlesRemaining2);
		        }

		        else{
                    printf("\nOut of range\n");
		        }
                            //sleep(5);
                        }
                        else{
                            printf("Repair your battle:");
                            scanf("%d %d",&yAttack , &xAttack);
                            board1[xAttack][yAttack] = 254;
                            repairPlayer1--;
                        }
                    }
                    else if (tmpChar1 == 0){
                        printf("\nAttack player2\n");
                        printf("\n");
                        scanf("%d %d",&yAttack , &xAttack);
		                if ((xAttack<=input) && (yAttack<=input) && (xAttack>0) && (yAttack>0)){
                    printf("\n");
                    attack(board2,xAttack,yAttack,input,&counterBattlesRemaining2);
		        }

		        else{
                    printf("\nOut of range\n");
		        }
                        //sleep(5);
                    }
                    }
                    else{
                       printf("\nAttack player2\n");
                        printf("\n");
                        scanf("%d %d",&yAttack , &xAttack);
		                if ((xAttack<=input) && (yAttack<=input) && (xAttack>0) && (yAttack>0)){
                    printf("\n");
                    attack(board2,xAttack,yAttack,input,&counterBattlesRemaining2);
		        }

		        else{
                    printf("\nOut of range\n");
		        }
                        //sleep(5);
                    }

                //    if (sw22==0)
                 //       sw2 = 1;
                 //   sw22 = 0;
		}
                printf("\n");
		      counterofdestroyedbattles=0;
		      setTextColor(7,0);
		      for(i=0;i<co1;i++){
                if(board2[a[i].n[0].x][a[i].n[0].y]==42&&board2[a[i].n[1].x][a[i].n[1].y]==42&&board2[a[i].n[2].x][a[i].n[2].y]==42) {counterofdestroyedbattles++; }

		      }
		      if(counterofdestroyedbattles>numberofdestroyedbattles1){printf("\nA battle destroyed!\n");numberofdestroyedbattles1++;
		      }
		      printf("\n");
		       printf("Number of destroyed battles:%d\n",numberofdestroyedbattles1);







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
            if (menu==1){
                        //printf("\n                            Player2 | Try your luck\n");
                    printf("\nDo you want to repair your battle?(1 to accept /0 to deny)\n");
                    scanf("%d" , &tmpChar1);
                    if (tmpChar1 == 1){
                        if (repairPlayer2 == 0){
                            printf("\nYou have done all your allowed repair");
                            sleep(5);
                            clearScreen();
                            printf("\nAttack player1\n");
                            printf("\n");
                            scanf("%d %d",&yAttack , &xAttack);
		                    if ((xAttack<=input) && (yAttack<=input) && (xAttack>0) && (yAttack>0)){
                    printf("\n");
                    attack(board1,xAttack,yAttack,input,&counterBattlesRemaining1);
		        }

		        else{
                    printf("\nOut of range\n");
		        }
                            sleep(5);
                        }
                        else{
                            printf("Repair your battle:");
                            scanf("%d %d",&yAttack , &xAttack);
                            board2[xAttack][yAttack] = 254;
                            repairPlayer2--;
                        }
                    }
                    else if (tmpChar1 == 0){
                        printf("\nAttack player1\n");
                        printf("\n");
                        scanf("%d %d",&yAttack , &xAttack);
		                if ((xAttack<=input) && (yAttack<=input) && (xAttack>0) && (yAttack>0)){
                    printf("\n");
                    attack(board1,xAttack,yAttack,input,&counterBattlesRemaining1);
		        }

		        else{
                    printf("\nOut of range\n");
		        }
                        sleep(5);
                    }
                    }
                    else{
                       printf("\nAttack player2\n");
                        printf("\n");
                        scanf("%d %d",&yAttack , &xAttack);
		                if ((xAttack<=input) && (yAttack<=input) && (xAttack>0) && (yAttack>0)){
                    printf("\n");
                    attack(board1,xAttack,yAttack,input,&counterBattlesRemaining1);
		        }

		        else{
                    printf("\nOut of range\n");
		        }
                        sleep(5);
                    }
            break;
        case 2:
            ran=rand();
            xAttack=ran%input+1;
            ran=rand();
            yAttack=ran%input+1;
            attack(board1,xAttack,yAttack,input,&counterBattlesRemaining1);
            break;
        case 3:
            if(ch==0){
                ran=rand();
            xAttack=ran%input+1;
            ran=rand();
            yAttack=ran%input+1;
            if(board1[xAttack][yAttack]==254){ch=2;h=sear(xAttack,yAttack,b,co1);
            for(o=0;o<3;o++){ if(b[h].n[o].x==xAttack && b[h].n[o].y==yAttack){  b[h].n[o].a=1;  } }
            }
            }else{
                k=0;
                while(1){
                    if(b[h].n[k].a==0){ xAttack=b[h].n[k].x;yAttack=b[h].n[k].y;b[h].n[k].a=1;break; }else{
                        k++;}

                    if(k>2){
                    break;}
                }


                ch--;
            }
            attack(board1,xAttack,yAttack,input,&counterBattlesRemaining1);
            break;
        case 4:
            if(ch==0){
            ran=rand();
            xAttack=ran%(input)+1;
            ran=rand();
            yAttack=ran%(input)+1;
            if(board1[xAttack][yAttack]==254){ch=4;xx=xAttack;yy=yAttack;}
            }else{

            }
            attack(board1,xAttack,yAttack,input,&counterBattlesRemaining1);
            break;
		      }


					printf("\n");
            //attack(board1,xAttack,yAttack,input,&counterBattlesRemaining1);
            counterofdestroyedbattles=0;
            setTextColor(7,0);
		      for(i=0;i<co3;i++){
                if(board1[b[i].n[0].x][b[i].n[0].y]==42&&board1[b[i].n[1].x][b[i].n[1].y]==42&&board1[b[i].n[2].x][b[i].n[2].y]==42) {counterofdestroyedbattles++; }

		      }
		      if(counterofdestroyedbattles>numberofdestroyedbattles2){printf("\nA battle destroyed!\n");numberofdestroyedbattles2++;
		      }
		      printf("\n");
		       printf("Number of destroyed battles:%d \n",numberofdestroyedbattles2);
		       printf("\n");
            printf("Do you want to save your game?(1 to accept , 0 to deny)");
            scanf("%d" , &chartemp1);
            if (chartemp1== 1){
                //printf("yes");
                fwrite(&input,sizeof(int),1,info);
                //printf("yes");
                fwrite(&menu,sizeof(int),1,info);
                //printf("yes");
                fwrite(&battlesNumber,sizeof(int),1,info);
                if (menu==1){
                   fwrite(&repairPlayer1,sizeof(int),1,info);
                   fwrite(&repairPlayer2,sizeof(int),1,info);
                }
                fwrite(&a,sizeof(struct battle),1,info);
                fwrite(&b,sizeof(struct battle),1,info);
                fwrite(&co1,sizeof(int) , 1 , info);
                fwrite(&co3,sizeof(int) , 1 , info);
                fwrite(board1,sizeof(int),1600,info);
                //printf("yes");
                fwrite(board2,sizeof(int),1600,info);
                //printf("yes");
                //sleep(5);
            }

            //sleep(5);
		    }
		  } while(counterBattlesRemaining1 != 0 && counterBattlesRemaining2 != 0);
		    setTextColor(7,0);
		    if (counterBattlesRemaining1==0)
		        printf("\nPlayer2 won\n");
		    if (counterBattlesRemaining2==0)
		        printf("\nPlayer1 won\n");
            fclose(info);

  	}

    return 0;
}
