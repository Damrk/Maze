#include <stdio.h>
#include <windows.h>
#define BLA 176
#define MED 177
#define LIG 178
#define WHI 219

void ini(char Overworld[][15]);
void draw(char Overworld[][15], int x, int y);

int main(void) {
	
	char Overworld[15][15];
	
	ini(Overworld);
	
	draw(Overworld, 0, 0);
	
	int f = getch();
	
	printf("%d",f );
	
	return 0;
}

void ini(char Overworld[][15])
{
	int MAP[3][3] = {{WHI, WHI, BLA},
					 {MED, LIG, BLA},
				     {BLA, BLA, BLA}};
	
	for(int i = 0; i != 15; i++)
	{
		for(int n = 0; n != 15; n++)
		{
			Overworld[i][n] = ' ';
		}
	}

	int i = 0, ipos, iend = i + 5;
	int n = 0, npos, nend = n + 5;
	
	for(int y = 0; y < 3; y++)
	{
		for(int x = 0; x < 3; x++)
		{
			int tile = MAP[y][x];
			printf("%d\n", tile);
			
			switch(tile)
			{
				case BLA:
					for(ipos = i; ipos != iend; ipos++)
					{
						for(npos = n; npos != nend; npos++)
						{
							Overworld[npos][ipos] = BLA;
						}
					}
					break;
				case MED:
					for(ipos = i; ipos != iend; ipos++)
					{
						for(npos = n; npos != nend; npos++)
						{
							Overworld[npos][ipos] = MED;
						}
					}
					break;
				case LIG:
					for(ipos = i; ipos != iend; ipos++)
					{
						for(npos = n; npos != nend; npos++)
						{
							Overworld[npos][ipos] = LIG;
						}
					}
					break;
				case WHI:
					for(ipos = i; ipos != iend; ipos++)
					{
						for(npos = n; npos != nend; npos++)
						{
							Overworld[npos][ipos] = WHI;
						}
					}
					break;
				default:
					break;
			}
			n += 5;
			if(n >= 15)
			{
				n = 0;
			}
			nend = n + 5;
		}
		i += 5;
		if(i >= 15)
		{
			i = 0;
		}
		iend = i + 5;
	}
}

void draw(char Overworld[][15], int x, int y)
{
	int xend = x + 5, yend = y + 5;
	for(int ypos = y; ypos != yend; ypos++)
	{
		for(int xpos = x; xpos != xend; xpos++)
		{
			printf("%c", Overworld[xpos][ypos]);
		}
		printf("\n");
	}
}
