// Philip Bale

#include "mylib.h"
#include "text.h"
#include <stdio.h>
#include <stdlib.h>
#include "welcome.h"
#include "gameOver.h"
#include "buzz.h"

#define BORDER_TOP 8
#define DEBUG 0

const int winScore = 100;
const int buzzHeight = 30;
const int buzzWidth = 30;
const int buzzPressUpDY = -1;
const int gravityDY = 1; 
const int pipeWidth = 20;
const int pipeDX = -1;
const int showNewPipeX = 50;
char c[50];
volatile int delayCount;
int score;
int textColorIndex;
int flamesIndex;

typedef struct {
	int x;
	int y;
} BUZZ;

typedef struct {
	int showing;
	int x;
	int topHeight;
	int gapHeight;
} PIPE;

void fillBothScreens(int index);
void applyGravity(BUZZ *buzz);
void moveUp(BUZZ *buzz);
void reset(BUZZ *buzz, PIPE *pipe1, PIPE *pipe2);
void generatePipeHeights(PIPE *pipe);
void drawPipe(PIPE *pipe, int index);
void handlePipes(PIPE *pipe1, PIPE *pipe2, int index);
void enablePipe(PIPE *pipe);
int checkCollision(BUZZ *buzz, PIPE *pipe1, PIPE *pipe2);

int main(void)
{
	REG_DISPCTL = MODE4 | BG2_ENABLE | BACKBUFFER;

	palette[0] = RED;
	palette[1] = BLUE;
	loadPalette(welcome_palette, WELCOME_PALETTE_SIZE, 0);

	int randomSeed = 0;

	while(!KEY_DOWN_NOW(BUTTON_A)) {
		drawImage4(0, 0, HOME_WIDTH, HOME_HEIGHT, home);
		flipPage();
		randomSeed++;
	} 

	srand(randomSeed);
	palette[0] = BLACK;
	fillBothScreens(0);	
	textColorIndex = 100;

	loadPalette(buzz_palette, BUZZ_PALETTE_SIZE, 0);

	BUZZ ourBuzz;
	PIPE pipe1;
	PIPE pipe2;
	reset(&ourBuzz, &pipe1, &pipe2);

	delayCount = 0;
	while(1) {
		/*fillScreen4(1);*/
		delay(1);
		if (checkCollision(&ourBuzz, &pipe1, &pipe2)) {
			loadPalette(gameOver_palette, GAMEOVER_PALETTE_SIZE, 0);
			delay(15);
			while(!KEY_DOWN_NOW(BUTTON_SELECT)) {
				drawImage4(0, 0, GAMEOVER_WIDTH, GAMEOVER_HEIGHT, gameOver);
				delay(1);
				flipPage();
			}

			loadPalette(buzz_palette, BUZZ_PALETTE_SIZE, 0);
			reset(&ourBuzz, &pipe1, &pipe2);
		}

		if (score == winScore) {
			while(!KEY_DOWN_NOW(BUTTON_SELECT)) {
				drawString(SCREEN_WIDTH / 2 - 40, SCREEN_HEIGHT / 2 - 20, "YOU WON!!!", textColorIndex);
				drawString(SCREEN_WIDTH / 2 - 70, SCREEN_HEIGHT / 2, "Press SELECT to replay", textColorIndex);
				delay(1);
				flipPage();
			}
		}

		fillScreen4(0);
		drawString(0, 0, c, textColorIndex);

		if (KEY_DOWN_NOW(BUTTON_A)) {
			moveUp(&ourBuzz);
		} else if (KEY_DOWN_NOW(BUTTON_SELECT)) {
			reset(&ourBuzz, &pipe1, &pipe2);
		} else {
			applyGravity(&ourBuzz);
		}

		handlePipes(&pipe1, &pipe2, textColorIndex);

		drawImage4(ourBuzz.x, ourBuzz.y, BUZZ_WIDTH, BUZZ_HEIGHT, buzz);
		//drawImage4(ourBuzz.x - 50, ourBuzz.y, FLAMES_WIDTH, FLAMES_HEIGHT, flames);
		drawImage4Offset(ourBuzz.x - 10, ourBuzz.y + 10, 10, 10,flamesIndex / 4, FLAMES_WIDTH, flames);
		delay(1);
		flipPage();
		delayCount++;
		flamesIndex--;
		if (flamesIndex == -1) {
			flamesIndex = 15;
		}
	}
}

void reset(BUZZ *ourBuzz, PIPE *pipe1, PIPE *pipe2) {
	ourBuzz->x = SCREEN_WIDTH / 6;
	ourBuzz->y = SCREEN_HEIGHT / 2 - buzzHeight / 2;

	enablePipe(pipe1);
	pipe2->showing = 0; 
	score = 0;
	flamesIndex = 3;

	while(!KEY_DOWN_NOW(BUTTON_B)) {
		waitForVBlank();
		fillScreen4(0);
		sprintf(c, "Score:%d   Flappy Buzz | Philip Bale", score);
		drawString(0, 0, c, textColorIndex);
		drawImage4(ourBuzz->x, ourBuzz->y, BUZZ_WIDTH, BUZZ_HEIGHT, buzz);
		drawString(SCREEN_WIDTH / 2 - 70, SCREEN_HEIGHT / 2, "Press B to release ball", textColorIndex);
		flipPage();
	}
}

void enablePipe(PIPE *pipe) {
	pipe->showing = 1;
	pipe->x = SCREEN_WIDTH - pipeWidth - 1;
	generatePipeHeights(pipe);
}

void generatePipeHeights(PIPE *pipe) {
	int baseHeight = 20;
	pipe->gapHeight = (buzzHeight << 1)  + rand() % (buzzHeight << 1);
	pipe->topHeight = rand() % (SCREEN_HEIGHT - BORDER_TOP - pipe->gapHeight - baseHeight) + (baseHeight >> 1);
}

void fillBothScreens(int index) {
	fillScreen4(index);
	flipPage();
	fillScreen4(index);
}

void applyGravity(BUZZ *buzz) { 
	if (buzz->y + buzzHeight < SCREEN_HEIGHT - gravityDY) {
		buzz->y += gravityDY;
	}
}

void handlePipes(PIPE *pipe1, PIPE *pipe2, int index) {
	if (pipe1->showing) {
		drawPipe(pipe1, index);
		pipe1->x += pipeDX;

		if (pipe1->x < showNewPipeX && !pipe2->showing) {
			enablePipe(pipe2);
		}

		if (pipe1->x == 0) {
			score++;
			sprintf(c, "Score:%d   Flappy Buzz | Philip Bale", score);
			pipe1->showing = 0;
		}
	}

	if (pipe2->showing) {
		drawPipe(pipe2, index);
		pipe2->x += pipeDX;

		if (pipe2->x < showNewPipeX && !pipe1->showing) {
			enablePipe(pipe1);
		}

		if (pipe2->x == 0) {
			score++;
			sprintf(c, "Score:%d   Flappy Buzz | Philip Bale", score);
			pipe2->showing = 0;
		}
	}
}

void moveUp(BUZZ *buzz) {
	if (buzz->y > BORDER_TOP) {
		buzz->y += buzzPressUpDY;
	}
}

void drawPipe(PIPE *pipe, int index) {
	drawRectDMA4(pipe->x, BORDER_TOP, pipe->topHeight, pipeWidth, index);
	drawRectDMA4(pipe->x, BORDER_TOP + pipe->topHeight + pipe->gapHeight, SCREEN_HEIGHT - pipe->topHeight - pipe->gapHeight, pipeWidth, index);
}

int checkCollision(BUZZ *buzz, PIPE *pipe1, PIPE *pipe2) {
	int buzzX = buzz->x;
	int buzzY = buzz->y;

	PIPE pipe = { 0, 0, 0, 0};

	if (pipe1->showing && pipe1->x <= (buzzX + buzzWidth)) {
		pipe = *pipe1;
	} else if (pipe2->showing && pipe2->x <= (buzzX + buzzWidth)) {
		pipe = *pipe2;
	}

	if (pipe.showing) {
		int pipeX = pipe.x;

		int xHit = 0;
		if (pipeX >= buzzX && pipeX <= buzzX + buzzWidth) {
			xHit = 1;
		} else if ( pipeX + pipeWidth >= buzzX && pipeX + pipeWidth <= buzzX + buzzWidth) {
			xHit = 1;
		}

		if (xHit) {
			int topY = BORDER_TOP + pipe.topHeight;
			if (buzzY <= topY) {
				return 1;
			} else if (buzzY + buzzWidth >= topY + pipe.gapHeight) {
				return 1;
			}
		}
	}

	return 0;
}