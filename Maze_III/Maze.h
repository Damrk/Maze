#include <stdio.h>

#ifndef MAZE_H
#define MAZE_H

#define OHIGHT 100
#define OWIDTH 100

#define BLA 176
#define MED 177
#define LIG 178
#define WHI 219

struct Quo {
	unsigned int x;
	unsigned int y;
};

/*void close(void);*/
void menu(struct Quo *Q);
void selecting(int input, char option[]);
void title(void);
void tutor(void);
void intro(char Text[]);
void scrollText(char Text[]);
void game(struct Quo *Q);
void drawOW(char overWorld[][OHIGHT], struct Quo *Q, int star);
void overInital(char overWorld[][OHIGHT]);
void ending(void);
void emptyBuffer(void);
void close(struct Quo *Q);


#endif
