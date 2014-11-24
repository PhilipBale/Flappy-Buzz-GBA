// Philip Bale
#include "mylib.h"

u16 *videoBuffer = (u16 *)0x6000000;
u16 *buffer0 = (u16 *) 0x6000000;
u16 *buffer1 = (u16 *) 0x600A000;
u16 *palette =  (u16 *) 0x5000000;

// A function to set pixel (x, y) to the color passed in.
void setPixel(int x, int y, u16 color)
{
	*(videoBuffer + OFFSET(x, y)) = color;
}

// A function to draw a FILLED rectangel starting at (x, y)
void drawRect(int x, int y, int w, int h, u16 color)
{
	int y2;
	for(y2=0; y2<h; y2++)
	{
		DMA[3].src = &color;
		DMA[3].dst = &videoBuffer[OFFSET2(x, y + y2, 240)];
		DMA[3].cnt = w | DMA_ON | DMA_SOURCE_FIXED;
	}
}

// A function to draw a HOLLOW rectangel starting at (x, y)
// NOTE: It has to run in O(w+h) time
void drawHollowRect(int x, int y, int w, int h, u16 color)
{
	for (int i = x; i < (w + x); i++) 
	{
		setPixel(i, y, color);
		setPixel(i, y + h - 1, color);
	}

	for (int j = (y + 1); j < (h + y - 1); j++)
	{
		setPixel(x, j, color);
		setPixel(x + w - 1, j, color);
	}
}

// A function to draw a line using Bresenham's algorithm
void plotLine(int x0, int y0, int x1, int y1, u16 color)
{
	// Swap so we are going left to right
	if (x0 > x1) {
		int temp = x0;
		x0 = x1;
		x1 = temp;
		temp = y0;
		y0 = y1;
		y1 = temp;
	} 

	int dx = abs(x1 - x0); // Change x
	int sx = x0 < x1 ? 1 : -1; // Sign x

	int dy = -abs(y1 - y0); // Change y
	int sy = y0 < y1 ? 1 : -1; // Sign y

	int error1 = dx+dy; // Calc total change
	int error2 = error1 << 1; // Mult by 2

	while(1)
	{
		setPixel(x0, y0, color);
		if (x0 == x1 && y0 == y1) {
			break;
		}

		error2 = error1 << 1;
		if (error2 >= dy)
		{
			error1 += dy;
			x0 += sx;
		}

		if (error2 <= dx) {
			error1 += dx;
			y0 += sy;
		}
	}
}

int abs(int x) {
	return x >= 0 ? x : -x;
}

void waitForVBlank()
{
	while(SCANLINECOUNTER>160);
	while(SCANLINECOUNTER<160);
}

void delay(int someInt) {
	volatile int n = 0;
	while (n < someInt) {
		waitForVBlank();
		n++;
	}
}

void fillScreen(volatile unsigned short color)
{
	DMA[3].src = &color;
	DMA[3].dst = videoBuffer;
	DMA[3].cnt = 38400 | DMA_ON | DMA_SOURCE_FIXED; 
}

/* drawimage3
 * A function that will draw an arbitrary sized image
 * onto the screen (with DMA).
 * @param r row to draw the image
 * @param c column to draw the image
 * @param width width of the image
 * @param height height of the image
 * @param image Pointer to the first element of the image. 
 */
void drawImage3(int x, int y, int w, int h, const u16* image) {
	for (int i = 0; i < h; i++) {
		DMA[3].src = image + OFFSET(0, i);
		DMA[3].dst = videoBuffer + OFFSET(x, y+i);
		DMA[3].cnt = DMA_ON | w;
	}
}


void setPixel4(int x, int y, u8 index)
{
	u16 ourPixel = OFFSET4(x,y);
   	u16 ourShort = videoBuffer[ourPixel];
	if (x&1) {
		videoBuffer[ourPixel] = (ourShort & 0x00FF) | (index << 8);
	} else {
		videoBuffer[ourPixel] = (ourShort & 0xFF00) | index;
	}	
}

void drawRect4(int x, int y, int h, int w, u8 index)
{
	int i, j;
	for (i = x; i < x + w; i++) 
	{
		for (j = y; j < y + h; j++) 
		{
		        setPixel4(i,j,index);
		}
	}
}

void drawRectDMA4(int x, int y, int h, int w, u8 index)
{
	
	volatile u16 color = (index << 8) | index;
	int r;
	for(r = 0; r < h; r++)
	{
		DMA[3].src = &color;
		DMA[3].dst = videoBuffer + OFFSET4(x,y + r);  
		DMA[3].cnt = (w >> 1) | DMA_ON | DMA_SOURCE_FIXED;
	}
}

void fillScreen4(u8 index) {
	volatile u16 color = (index << 8) | index;
	DMA[3].src = &color;
	DMA[3].dst = videoBuffer;  
	DMA[3].cnt = ((SCREEN_WIDTH * SCREEN_HEIGHT) >> 1) | DMA_ON | DMA_SOURCE_FIXED;
}

void drawImage4(int x, int y, int w, int h, const u16* image) {
	w = w >> 1;
	for (int r = 0; r < h; r++) {
		DMA[3].src = image + (w * r);
		DMA[3].dst = videoBuffer + (OFFSET2(x,y+r, 240) >> 1);  
		DMA[3].cnt = w | DMA_ON;
	}
}

void drawImage4Offset(int x, int y, int w, int h, int offsetX, int wholeWidth, const u16* image) {
	w = w >> 1;
	for (int r = 0; r < h; r++) {
		DMA[3].src = image + OFFSET2(offsetX * (w << 1) + 1, r, (wholeWidth >> 1));
		DMA[3].dst = videoBuffer + (OFFSET2(x,y+r, 240) >> 1);  
		DMA[3].cnt = w | DMA_ON;
	}
}

void flipPage(void)
{
	if (REG_DISPCTL & BACKBUFFER) {
		REG_DISPCTL &= ~BACKBUFFER;
		videoBuffer = buffer1;
	} else {
		REG_DISPCTL |= BACKBUFFER;
		videoBuffer = buffer0;
	}
}

void loadPalette(const unsigned short * toLoad, int size, int offset) {
	for (int i = offset; i < (size + offset); i++) {
		palette[i] = toLoad[i];
	}
}