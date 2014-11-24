/*
 * Exported with brandontools v1.0
 * Invocation command was brandontools -mode4 -start=0 -weights=25,25,25,25 -dither=1 -dither_level=80 /home/philip/dev/cs2110/hw11/gameOver /home/philip/dev/cs2110/hw11/art/gameOver.png 
 * Time-stamp: Tuesday 11/11/2014, 17:08:20
 * 
 * Image Information
 * -----------------
 * /home/philip/dev/cs2110/hw11/art/gameOver.png 240@160
 * 
 * Quote/Fortune of the Day!
 * -------------------------
 * To err is human... to really foul up requires the root password.
 * 
 * How you look depends on where you go.
 * 
 * All bug reports / feature requests are to be sent to Brandon (brandon.whitehead@gatech.edu)
 */

#ifndef GAMEOVER_BITMAP_H
#define GAMEOVER_BITMAP_H

extern const unsigned short gameOver_palette[256];
#define GAMEOVER_PALETTE_SIZE 256

extern const unsigned short gameOver[19200];
#define GAMEOVER_SIZE 19200
#define GAMEOVER_WIDTH 240
#define GAMEOVER_HEIGHT 160

#endif

