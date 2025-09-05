#include<stdio.h>
#include<windows.h>

void close(void);
void emptyBuffer(void);
void menu(void);

int main(void)
{
	close();
	return 0;
}

void close(void)
{
	char input;
	system("cls");
	while(input != 'y')
	{
		printf("Are you sure you want to exit?\n [y/n]: ");
/***********************************************************************
	        scanf("%c", &input);
	        Try the following
***********************************************************************/
		while((scanf("%c", &input) == 1) && input != 'y'
                                   && input !='n') { }
		emptyBuffer();
		if(input == 'n')
		{
			menu();
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
void menu(void)
{
	close();
}
