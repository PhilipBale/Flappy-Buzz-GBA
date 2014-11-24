/*
 * Exported with brandontools v1.0
 * Invocation command was brandontools -mode4 buzz art/buzz.png art/flames.png 
 * Time-stamp: Tuesday 11/11/2014, 22:02:54
 * 
 * Image Information
 * -----------------
 * art/buzz.png 30@30
 * art/flames.png 40@10
 * 
 * Quote/Fortune of the Day!
 * -------------------------
 * A C program is like a fast dance on a newly waxed dance floor by people carrying razors. - Waldi Ravens.
 * 
 * Don't let the past and useless detail choke your existence.
 * 
 * All bug reports / feature requests are to be sent to Brandon (brandon.whitehead@gatech.edu)
 */

#ifndef BUZZ_BITMAP_H
#define BUZZ_BITMAP_H

extern const unsigned short buzz_palette[223];
#define BUZZ_PALETTE_SIZE 223

extern const unsigned short buzz[450];
#define BUZZ_SIZE 450
#define BUZZ_WIDTH 30
#define BUZZ_HEIGHT 30

extern const unsigned short flames[200];
#define FLAMES_SIZE 200
#define FLAMES_WIDTH 40
#define FLAMES_HEIGHT 10

#endif

