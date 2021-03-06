#include "mylib.h"
#include "text.h"


void drawChar(int x, int y, char ch, u8 index)
{
	int x1, y1;
	for(x1=0; x1<6; x1++)
	{
		for(y1=0; y1<8; y1++)
		{
			if(fontdata_6x8[OFFSET2(x1, y1, 6)+ch*48])
			{
				setPixel4(x+x1, y+y1, index);
			}
		}
	}
}

/*
 *
 * I didn't code this in class but I will go over it next lecture
 *
 * You can call it like this:
 *
 * drawString(10, 10, "Hello!", YELLOW);
 *
 * or like this:
 * 
 * char *message = "This is a message.";
 * drawString(20, 5, message, RED);
 *
 * or like this:
 *
 * char buffer[41] = "This is a char array!";
 * drawString(30, 5, buffer, GREEN);
 * 
 */
void drawString(int x, int y, char *str, u8 index)
{
	while(*str)
	{
		drawChar(x, y, *str++, index);
		x +=6;

	}
}