#ifndef SCREEN_H
#define SCREEN_H

#include "string.h"
#include "system.h"
#include "types.h"
#include "hexcodes.h"

int cursor_x;
int cursor_y;

char default_color;
char default_selection_color;

const uint8 screen_width;
const uint8 screen_height;
const uint8 screen_depth;

void clear_lines(uint8, uint8);

void update_cursor();

void clear_screen();

void scroll_up(uint8);

void newline_check();

char get_default_color();

void set_default_color(char);

char get_default_selection_color();

void set_default_selection_color(char);

void print_char_color(char, char);

void print_char(char);

void print_color(string, char);

void print(string);

void print_bar_color(char);

void print_bar();

#endif