/*
 * Exported with brandontools v1.0
 * Invocation command was brandontools -mode4 -start=0 -weights=25,25,25,25 -dither=1 -dither_level=80 /home/philip/dev/cs2110/hw11/welcome /home/philip/dev/cs2110/hw11/art/home.png 
 * Time-stamp: Tuesday 11/11/2014, 17:08:55
 * 
 * Image Information
 * -----------------
 * /home/philip/dev/cs2110/hw11/art/home.png 240@160
 * 
 * Quote/Fortune of the Day!
 * -------------------------
 * To err is human... to really foul up requires the root password.
 * 
 * Wish you happiness.
 * 
 * All bug reports / feature requests are to be sent to Brandon (brandon.whitehead@gatech.edu)
 */

#ifndef WELCOME_BITMAP_H
#define WELCOME_BITMAP_H

extern const unsigned short welcome_palette[256];
#define WELCOME_PALETTE_SIZE 256

extern const unsigned short home[19200];
#define HOME_SIZE 19200
#define HOME_WIDTH 240
#define HOME_HEIGHT 160

#endif

