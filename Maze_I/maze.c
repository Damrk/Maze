/***********************************************************************
 * maze.c
 * A simple ascci maze game
 * Youssef Derouiche
 * Version 3
 * ********************************************************************/

#include <stdio.h>
#include <conio.h>

void draw(int w, int h, int xpos, int ypos, char player);
void title(void);
void playerInf(int, int, int);
void win(void);
void pause(void);

char trrain(int w,int h);

/* const */
char roco[7][7] = {{178,178,178,178,178,178,178}
				  ,{178,177,178,177,177,177,178}
				  ,{178,177,177,177,178,177,178}
				  ,{178,177,178,177,178,177,178}
			      ,{178,177,177,177,178,177,178}
				  ,{178,177,177,177,178,176,178}
				  ,{178,178,178,178,178,178,178}};

int main(void)
{
	
	
	/* Positions */
	int y = 1;
	int x = 1;
	
	/* Input Value */
	int a;
	
	title();
	
	/* controls */
	while(x != 5 || y != 5)
	{
		a = getch();
		switch(a)
		{
			case 87:
			case 119:
				if (y > 0 && roco[y-1][x] != -78)
				{
					y--; /* up */	
				}
				break;
			case 97:
			case 65:
				if (x > 0 && roco[y][x-1] != -78)
				{
					x--; /* left */	
				}
				break;
			case 115:
			case 83:
				if (y < 6 && roco[y+1][x] != -78)
				{
					y++; /* down */	
				}
				break;
			case 100:
			case 68:
				if (x < 6 && roco[y][x+1] != -78)
				{
					x++; /* right */	
				}
				break;
			case 27:
				return 0;
				break;
			default:
				break;
		}
		draw(7,7,x,y,'@');
		playerInf(x,y,a);
	}
	draw(7,7,x,y,'*');
	sleep(1);
	win();
	pause();
	
	return 0;
}
/* Outputs Title */
void title(void)
{
	/* Maze Seeker prototype*/
	printf("..... ... ... ...\n");
	printf(". . . . .   . .  \n");
	printf(". . . ...  .  ...\n");
	printf(". . . . . .   .  \n");
	printf(". . . . . ... ...\n\n");
	printf("Coded By Youssef Derouiche\n\n");
	printf("Press any key to start");
}

/* Player information*/
void playerInf(int x,int y, int a)
{
	printf("x:%d y:%d\n\n",x,y);
	printf("w = up\na = left\nd = right\ns = down");
	printf("\nplayer: %d",roco[y][x]);
	printf("\nTop:    %c",roco[y-1][x]);
	printf("\nRight:  %c",roco[y][x+1]);
	printf("\nLeft:   %c",roco[y][x-1]);
	printf("\nBelow:  %c",roco[y+1][x]);
	printf("\nInput:  %d",a);
}

/* winning screen */
void win(void)
{
	system("cls");
	printf("You Win! :^)\n");
	sleep(2);
}

void draw(int w, int h,int xpos, int ypos, char player)
{
	system("cls");
	
	roco[ypos][xpos] = player;
	
	for(int i = 0; i < w; i++)
	{
		for(int x = 0; x < h; x++)
		{
			printf("%c", roco[i][x]);
		}
		printf("\n");
	}
	
	roco[ypos][xpos] = 177;
}

void pause(void)
{
	
}
