#ifndef GRAPHICS_H
#define GRAPHICS_H

#define cog_width  30
#define cog_height 30
static unsigned char bitmap_cog[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x03, 0x00,
   0x00, 0xf0, 0x03, 0x00, 0x80, 0xf0, 0x43, 0x00, 0xc0, 0xf1, 0xe3, 0x00,
   0xe0, 0xfb, 0xf7, 0x01, 0xf0, 0xff, 0xff, 0x03, 0xe0, 0xff, 0xff, 0x01,
   0xc0, 0xff, 0xff, 0x00, 0x80, 0xff, 0x7f, 0x00, 0xc0, 0x1f, 0xfe, 0x00,
   0xfc, 0x0f, 0xfc, 0x0f, 0xfc, 0x07, 0xf8, 0x0f, 0xfc, 0x07, 0xf8, 0x0f,
   0xfc, 0x07, 0xf8, 0x0f, 0xfc, 0x07, 0xf8, 0x0f, 0xfc, 0x0f, 0xfc, 0x0f,
   0xc0, 0x1f, 0xfe, 0x00, 0x80, 0xff, 0x7f, 0x00, 0xc0, 0xff, 0xff, 0x00,
   0xe0, 0xff, 0xff, 0x01, 0xf0, 0xff, 0xff, 0x03, 0xe0, 0xfb, 0xf7, 0x01,
   0xc0, 0xf1, 0xe3, 0x00, 0x80, 0xf0, 0x43, 0x00, 0x00, 0xf0, 0x03, 0x00,
   0x00, 0xf0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#define check_width  30
#define check_height 30
static unsigned char bitmap_check[] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
   0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0xc0, 0x07, 0x00, 0x00, 0xe0, 0x03,
   0x00, 0x00, 0xf0, 0x01, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x7c, 0x00,
   0x00, 0x00, 0x3e, 0x00, 0x38, 0x00, 0x1f, 0x00, 0x78, 0x80, 0x0f, 0x00,
   0xf8, 0xc0, 0x07, 0x00, 0xf0, 0xe1, 0x03, 0x00, 0xe0, 0xf3, 0x01, 0x00,
   0xc0, 0xff, 0x00, 0x00, 0x80, 0x7f, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00,
   0x00, 0x1e, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#endif