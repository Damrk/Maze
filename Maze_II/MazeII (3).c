/***********************************************************************
 * MazeII.c
 * Second addition of Maze - With Levels
 * Youssef Derouiche
 * VERSION 1
 * ********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define HIG 11
#define WID 11

void title(void);
void draw( int xpos,int ypos, int level, char L1[][WID], char L2[][WID]
			, char L3[][WID]);
void pause(void);
void emptybuffer(void);
void loop(int level, int *xpos, int *ypos, char L1[][WID], char L2[][WID], char L3[][WID]);


int main(void)
{
	/* variables */
	char level_1[HIG][WID] ={{178,178,178,178,178,178,178,178,178,178}
				  			,{178,177,178,177,177,177,177,177,177,178}
				  			,{178,177,178,177,178,178,178,178,177,178}
				  			,{178,177,178,177,178,177,177,177,177,178}
			      			,{178,177,178,177,178,177,177,178,178,178}
				  			,{178,177,178,177,178,177,177,177,177,178}
				  			,{178,177,178,177,178,177,178,177,177,178}
				  			,{178,177,178,177,178,177,178,178,177,178}
				  			,{178,177,177,177,178,177,177,177,176,178}
				  			,{178,178,178,178,178,178,178,178,178,178}};
				  			
				  			
	char level_2[HIG][WID] ={{178,178,178,178,178,178,178,178,178,178}
				  			,{178,177,177,177,177,177,177,177,177,178}
				  			,{178,177,177,177,177,177,177,177,177,178}
				  			,{178,177,177,177,177,177,177,177,177,178}
			      			,{178,177,177,177,177,177,177,177,177,178}
				  			,{178,177,177,177,177,177,177,177,177,178}
				  			,{178,177,177,177,177,177,177,177,177,178}
				  			,{178,177,178,178,178,178,178,178,178,178}
				  			,{178,177,177,177,177,177,177,177,176,178}
				  			,{178,178,178,178,178,178,178,178,178,178}};
	
	
	char level_3[HIG][WID] ={{178,178,178,178,178,178,178,178,178,178}
				  			,{178,177,177,177,177,177,177,177,177,178}
				  			,{178,177,177,177,177,177,177,177,177,178}
				  			,{178,177,177,177,177,177,177,177,177,178}
			      			,{178,177,177,177,177,177,177,177,177,178}
				  			,{178,177,177,177,177,177,177,177,177,178}
				  			,{178,177,177,177,177,177,177,177,177,178}
				  			,{178,177,177,177,177,177,177,177,177,178}
				  			,{178,177,177,177,177,177,177,177,176,178}
				  			,{178,178,178,178,178,178,178,178,178,178}};
	
	int level = 1;
	int xpos, ypos;
	
	/* Title */
	title();
	
	pause();
	
	/* Loop */
	loop(level, xpos, ypos, level_1, level_2, level_3);
	
	/* End */
	
	return 0;
}


void loop(int level, int *xpos, int *ypos, char L1[][WID], char L2[][WID]
			, char L3[][WID])
{
	*xpos = 1;
	*ypos = 1;
	int input;
	_Bool win = 1;
	
	while(win)
	{
		input = getch();
		switch(input)
		{
			case 87:
			case 119:
				if(level == 1)
				{
					if (L1[*ypos-1][*xpos] != -78)
						{
							ypos--; /* up */	
						}	
				}
				else if(level == 2)
				{
					if (L2[*ypos-1][*xpos] != -78)
						{
							ypos--; /* up */	
						}	
				}
				else if(level == 3)
				{
					if (L3[*ypos-1][*xpos] != -78)
						{
							ypos--; /* up */	
						}	
				}
				break;
			case 97:
			case 65:
				if(level == 1)
				{
					if (L1[*ypos][*xpos-1] != -78)
						{
							xpos--; /* left */	
						}	
				}
				else if(level == 2)
				{
					if (L2[*ypos][*xpos-1] != -78)
						{
							xpos--; /* left */	
						}	
				}
				else if(level == 3)
				{
					if (L3[*ypos][*xpos-1] != -78)
						{
							xpos--; /* left */	
						}	
				}
				break;
			case 115:
			case 83:
				if(level == 1)
				{
					if (L1[*ypos+1][*xpos] != -78)
					{
						ypos++; /* down */	
					}	
				}
				else if(level == 2)
				{
					if (L2[*ypos+1][*xpos] != -78)
					{
						ypos++; /* down */	
					}	
				}
				else if(level == 3)
				{
					if (L3[*ypos+1][*xpos] != -78)
					{
						ypos++; /* down */	
					}	
				}
				break;
			case 100:
			case 68:
				if(level == 1)
				{
					if (L1[*ypos][*xpos+1] != -78)
					{
						xpos++; /* right */	
					}
				}
				else if(level == 2)
				{
					if (L2[*ypos][*xpos+1] != -78)
					{
						xpos++; /* right */	
					}
				}
				else if(level == 3)
				{
					if (L3[*ypos][*xpos+1] != -78)
					{
						xpos++; /* right */	
					}
				}
				break;
			default:
				break;
		}
		if (*xpos == 8 && *ypos == 8)
		{
			*xpos = 1;
			*ypos = 1;
			level++;
		}
		if(level == 4)
			{
				win = 0;
			}
		draw( xpos, ypos, level, L1, L2, L3);
	}
	system("cls");
	printf("You win!!! :^)");
	pause();
}

void draw( int xpos,int ypos, int level, char L1[][WID], char L2[][WID], char L3[][WID])
{
	system("cls");
	emptybuffer();                                                    
	L1[ypos][xpos] = '@';
	L2[ypos][xpos] = '@';
	L3[ypos][xpos] = '@';
	for(int y = 0; y < HIG-1;y++)
	{
		for(int x = 0; x < WID-1; x++)
		{
			if(level == 1)
			{
				printf("%c", L1[y][x]);	
			}
			else if(level == 2)
			{
				printf("%c", L2[y][x]);	
			}
			else if(level == 3)
			{
				printf("%c", L3[y][x]);	
			}
		}
			printf("\n");
	}
	L1[ypos][xpos] = 177;
	L2[ypos][xpos] = 177;
	L3[ypos][xpos] = 177;
	
	printf("y: %d\nx: %d\nlevel: %d",ypos,xpos,level);
	
}

void pause(void)
{
	
}
void emptybuffer(void)
{
	while(getchar() == '\n')
	{
		;
	}
}

void title(void)
{
	printf("..... ... ... ...  ... ...\n");
	printf(". . . . .   . .     .   . \n");
	printf(". . . ...  .  ...   .   . \n");
	printf(". . . . . .   .     .   . \n");
	printf(". . . . . ... ...  ... ...\n\n");
	printf("Coded By Youssef Derouiche\n\n");
	printf("Press any key to start");
}
