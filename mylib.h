#ifndef MYLIB_H
#define MYLIB_H

// Philip Bale

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned int u8;

#define OFFSET(x,y) ((x)+(y)*240) 
#define OFFSET2(x,y, height)  ((x) + (y)*(height))
#define OFFSET4(x,y) (((x) + (y)*240)>>1)
#define REG_DISPCTL *(u16 *)0x4000000
#define MODE3 3
#define MODE4 4
#define BG2_ENABLE (1<<10)
#define BACKBUFFER (1<<4)

#define SETMODE(mode,bg) REG_DISPCNT=mode|bg

#define SCANLINECOUNTER *(volatile unsigned short*) 0x4000006

// Buttons
#define BUTTON_A (1<<0)
#define BUTTON_B (1<<1)
#define BUTTON_SELECT (1<<2)
#define BUTTON_START (1<<3)
#define BUTTON_RIGHT (1<<4)
#define BUTTON_LEFT (1<<5)
#define BUTTON_UP (1<<6)
#define BUTTON_DOWN (1<<7)
#define BUTTON_R (1<<8)
#define BUTTON_L (1<<9)

#define BUTTONS *(volatile unsigned int *)0x4000130
#define KEY_DOWN_NOW(key)  (~(BUTTONS) & key)

// Pixel Stuff
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 160
#define NUM_PIXELS SCREEN_WIDTH * SCREEN_HEIGHT
#define RGB(r, g, b) ((r) | (g) << 5 | (b) << 10)

#define BLACK RGB(0,0,0)
#define WHITE RGB(31, 31, 31)
#define RED RGB(31,0,0)
#define GREEN RGB(0, 31, 0)
#define BLUE RGB(0,0,31)
#define YELLOW RGB(31,31,0)
#define CYAN RGB(0,31,31)
#define MAGENTA RGB(31,0,31)
#define GRAY RGB(25, 25, 25)

/* DMA */

#define REG_DMA0SAD         *(const volatile u32*)0x40000B0 // source address
#define REG_DMA0DAD         *(volatile u32*)0x40000B4       // destination address
#define REG_DMA0CNT         *(volatile u32*)0x40000B8       // control register

// DMA channel 1 register definitions
#define REG_DMA1SAD         *(const volatile u32*)0x40000BC // source address
#define REG_DMA1DAD         *(volatile u32*)0x40000C0       // destination address
#define REG_DMA1CNT         *(volatile u32*)0x40000C4       // control register

// DMA channel 2 register definitions
#define REG_DMA2SAD         *(const volatile u32*)0x40000C8 // source address
#define REG_DMA2DAD         *(volatile u32*)0x40000CC       // destination address
#define REG_DMA2CNT         *(volatile u32*)0x40000D0       // control register

// DMA channel 3 register definitions
#define REG_DMA3SAD         *(const volatile u32*)0x40000D4 // source address
#define REG_DMA3DAD         *(volatile u32*)0x40000D8       // destination address
#define REG_DMA3CNT         *(volatile u32*)0x40000DC       // control register

typedef struct
{
	const volatile void *src;
	const volatile void *dst;
	unsigned int cnt;
} DMA_CONTROLLER;

#define DMA ((volatile DMA_CONTROLLER *) 0x040000B0)

// Defines
#define DMA_CHANNEL_0 0
#define DMA_CHANNEL_1 1
#define DMA_CHANNEL_2 2
#define DMA_CHANNEL_3 3

#define DMA_DESTINATION_INCREMENT (0 << 21)
#define DMA_DESTINATION_DECREMENT (1 << 21)
#define DMA_DESTINATION_FIXED (2 << 21)
#define DMA_DESTINATION_RESET (3 << 21)

#define DMA_SOURCE_INCREMENT (0 << 23)
#define DMA_SOURCE_DECREMENT (1 << 23)
#define DMA_SOURCE_FIXED (2 << 23)

#define DMA_REPEAT (1 << 25)

#define DMA_16 (0 << 26)
#define DMA_32 (1 << 26)

#define DMA_NOW (0 << 28)
#define DMA_AT_VBLANK (1 << 28)
#define DMA_AT_HBLANK (2 << 28)
#define DMA_AT_REFRESH (3 << 28)

#define DMA_IRQ (1 << 30)
#define DMA_ON (1 << 31)

extern u16 *videoBuffer;
extern u16 *buffer0;
extern u16 *buffer1;
extern u16 *palette;

void setPixel(int x, int y, u16 color);
void drawRect(int x, int y, int w, int h, u16 color);
void drawHollowRect(int x, int y, int w, int h, u16 color);
void plotLine(int x0, int y0, int x1, int y1, u16 color);
void waitForVBlank();
int abs(int i);
void delay(int someInt);
void fillScreen(volatile unsigned short color);
void drawImage3(int x, int y, int w, int h, const u16* image);
void setPixel4(int x, int y, u8 index);
void drawRect4(int x, int y, int h, int w, u8 index);
void drawRectDMA4(int x, int y, int h, int w, u8 index);
void fillScreen4(u8 index);
void drawImage4(int x, int y, int w, int h, const u16* image);
void drawImage4Offset(int x, int y, int w, int h, int offsetX, int wholeWidth, const u16* image);
void flipPage(void);
void loadPalette(const unsigned short * toLoad, int size, int offset);

#endif