#include<stdio.h>

struct Hamming {
	int x;
	int y;
};

void slamp(struct Hamming *Ham);

int main(void)
{
	struct Hamming Ham = { 10, 10};
	
	printf("%d %d\n",Ham.x, Ham.y);
	
	slamp(&Ham);
	
	printf("%d %d\n",Ham.x, Ham.y);
	
	return 0;
}

void slamp(struct Hamming *Ham)
{
	Ham->x += 10;
	Ham->y += 10;
}
