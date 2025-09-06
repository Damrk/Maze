/***********************************************************************
 * CPAssigmentMay.c
 * A maze game
 * 231001
 * Version 1
 * ********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#include "Maze.h"




int main(void)
{
	struct Quo Quo = {50, 50};
	/* Menu */
	menu(&Quo);
	return 0;
}

/* Menu */
void menu(struct Quo *Q)
{
	char option[5] = {'>',' ',' ',' ',' '};
	int input = 0;
	while(input != 13)
	{
		system("cls");
		title();
		printf("\t%c New Game\n"
			   "\t%c Load Save\n"
			   "\t%c How to Play\n"
			   "\t%c Exit\n",option[0] ,option[1], option[2], 
			        option[3]);
		input = getch();
		selecting(input, option);
	}
	
	if(option[0] == '>')
	{
		/* Introduction */
		intro("\n\tIn the lands you live, there is a grave danger.\n\t"
		"Collect the four stars [*] and save your home...");
		/* Game */
		game(Q);
	}
	else if(option[1] == '>')
	{
		system("cls");
		printf("Nothing here :<");
	}
	else if(option[2] == '>')
	{
		tutor();
		menu(Q);
	}
	else if(option[3] == '>')
	{
		close(Q);
	}
}
void tutor(void)
{
	system("cls");
	printf("WASD to control character\nAim is to collect stars '*'");
	getch();
}

void selecting(int input, char option[])
{
	if(input == 119 || input == 87)
		{
			option[4] = option[0];
			option[0] = option[1];
			option[1] = option[2];
			option[2] = option[3];
			option[3] = option[4];
			Beep(400,10);
		}
	if(input == 115 || input == 83)
		{
			option[4] = option[3];
			option[3] = option[2];
			option[2] = option[1];
			option[1] = option[0];
			option[0] = option[4];
			Beep(400,10);
		}
}

/* Menu Title Text */
void title(void)
{
	printf("\n %c%c%c%c%c %c%c%c %c%c%c %c%c%c  %c%c%c %c%c%c %c%c%c\n"
	       " %c %c %c %c %c   %c %c     %c   %c   %c \n"
	       " %c %c %c %c%c%c  %c  %c%c%c   %c   %c   %c \n"
	       " %c %c %c %c %c %c   %c     %c   %c   %c \n"
	       " %c %c %c %c %c %c%c%c %c%c%c  %c%c%c %c%c%c %c%c%c\n\n"
		   ,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED
		   ,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED
		   ,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED
		   ,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED
		   ,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED,MED
		   ,MED);
}

/* Introduction */
void intro(char Text[])
{
	system("cls");
	scrollText(Text);
	printf("\n\nPress Any Key to Start");
	emptyBuffer();
}

void scrollText(char Text[])
{
	for(int i = 0; Text[i] != '\0'; i++)
	{
		printf("%c", Text[i]);
		Beep(400,100);
	}
}

/* Game */
void game(struct Quo *Q)
{
	char overWorld[OHIGHT][OWIDTH];
	
	overInital(overWorld);
	int input = 0;
	while(input != 27)
	{
		input = getch();
		switch(input)
		{
			case 87:
			case 119:
				if (Q->y > 0)
				{
					Q->y--; /* up */	
				}
				break;
			case 97:
			case 65:
				if (Q->x > 0)
				{
					Q->x--; /* left */	
				}
				break;
			case 115:
			case 83:
				if (Q->y < 89)
				{
					Q->y++; /* down */	
				}
				break;
			case 100:
			case 68:
				if (Q->x < 89)
				{
					Q->x++; /* right */	
				}
				break;
			default:
				break;
		}
		drawOW(overWorld, Q, 5);
	}
	
}

void drawOW(char overWorld[][OHIGHT], struct Quo *Q, int star)
{	
	system("cls");
	int xend = Q->x + 11, yend = Q->y + 11;
	int temp = overWorld[xend-6][yend-6];
	overWorld[xend-6][yend-6] = '@';
	for(int ypos = Q->y; ypos != yend; ypos++)
	{
		for(int xpos = Q->x; xpos != xend; xpos++)
		{
			printf("%c", overWorld[xpos][ypos]);
		}
		printf("\n");
	}
	printf("Star Number: %d\n", star);
	printf("X: %d\tY: %d", Q->x, Q->y);
	overWorld[xend-6][yend-6] = temp;
	Beep(400,150);
}

void overInital(char overWorld[][OHIGHT])
{
	for(int i = 0; i != 15; i++)
	{
		for(int n = 0; n != 15; n++)
		{
			overWorld[i][n] = ' ';
		}
	}
	
	
	int MAP[OHIGHT / 5][OWIDTH / 5] = {{123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123},
						   			   {123, WHI, WHI, WHI, WHI, WHI, LIG, LIG, MED, BLA, BLA, BLA, BLA, BLA, MED, LIG, WHI, WHI, WHI, 123},
						               {123, WHI, WHI, WHI, WHI, LIG, MED, MED, BLA, BLA, BLA, BLA, BLA, BLA, BLA, MED, LIG, WHI, WHI, 123},
						               {123, WHI, WHI, WHI, LIG, MED, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, MED, LIG, WHI, 123},
						               {123, WHI, WHI, LIG, MED, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, MED, LIG, 123},
	            					   {123, WHI, LIG, MED, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, MED, 123},
			             			   {123, LIG, MED, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, 123},
									   {123, MED, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, 123},
									   {123, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, 123},
									   {123, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, 123},
									   {123, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, 123},
									   {123, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, MED, BLA, BLA, 123},
									   {123, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, MED, LIG, MED, BLA, 123},
									   {123, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, MED, LIG, WHI, LIG, MED, 123},
									   {123, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, MED, LIG, WHI, WHI, WHI, LIG, 123},
									   {123, WHI, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, MED, LIG, WHI, LIG, MED, 123},
									   {123, WHI, WHI, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, MED, LIG, LIG, LIG, MED, 123},
									   {123, WHI, WHI, WHI, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, BLA, MED, MED, MED, MED, MED, 123},
									   {123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123, 123}};
	

	int i = 0, ipos, iend = i + 5;
	int n = 0, npos, nend = n + 5;
	
	for(int y = 0; y < OHIGHT / 5; y++)
	{
		for(int x = 0; x < OWIDTH / 5; x++)
		{
			int tile = MAP[y][x];
			
			switch(tile)
			{
				case BLA:
					for(ipos = i; ipos != iend; ipos++)
					{
						for(npos = n; npos != nend; npos++)
						{
							overWorld[npos][ipos] = BLA;
						}
					}
					break;
				case MED:
					for(ipos = i; ipos != iend; ipos++)
					{
						for(npos = n; npos != nend; npos++)
						{
							overWorld[npos][ipos] = MED;
						}
					}
					break;
				case LIG:
					for(ipos = i; ipos != iend; ipos++)
					{
						for(npos = n; npos != nend; npos++)
						{
							overWorld[npos][ipos] = LIG;
						}
					}
					break;
				case WHI:
					for(ipos = i; ipos != iend; ipos++)
					{
						for(npos = n; npos != nend; npos++)
						{
							overWorld[npos][ipos] = WHI;
						}
					}
					break;
				default:
					break;
			}
			n += 5;
			if(n >= OWIDTH)
			{
				n = 0;
			}
			nend = n + 5;
		}
		i += 5;
		if(i >= OHIGHT)
		{
			i = 0;
		}
		iend = i + 5;
	}
}

/* End */
void ending(void)
{
	
}

void close(struct Quo *Q)
{
	char input;
	system("cls");
	while(input != 'y')
	{
		printf("Are you sure you want to exit?\n [y/n]: ");
		scanf("%c", &input);
		if(input == 'n')
		{
			menu(Q);
		}
	}
}
void emptyBuffer(void)
{
	while(getchar() != '\n')
	{
		;
	}
}

