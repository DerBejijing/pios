#include "../include/screen.h"

int cursor_x = 0;
int cursor_y = 0;

char default_color = COLOR_BLACK_WHITE;
char default_selection_color = COLOR_WHITE_BLACK;

const uint8 screen_width = 80;														// screen-width 80  : 80 cells width (columns)
const uint8 screen_height = 25;														// screen-height 25 : 25 cells high  (rows)
const uint8 screen_depth = 2;														// screen-depth 2   : two bytes per cell in vga color mode


void clear_lines(uint8 from, uint8 to) {

	uint16 i = screen_width * from * screen_depth;
	string video_memory = (string) 0xb8000;
	for (i; i < (screen_width * (to + 1) * screen_depth); ++i) {
		video_memory[i] = 0x0;
	}

}


void update_cursor() {

	unsigned tmp = cursor_y * screen_width + cursor_x-1;

	outportb(0x3d4, 14);
	outportb(0x3d5, tmp >> 8);
	outportb(0x3d4, 15);
	outportb(0x3d5, tmp);

}


void clear_screen() {

	clear_lines(0, screen_height-1);
	cursor_x = 0;
	cursor_y = 0;
	update_cursor();

}


void scroll_up(uint8 lines) {

	string video_memory = (string) 0xb8000;
	uint16 i = 0;

	clear_lines(0, lines-1);
	for(i; i < screen_width * (screen_height-1) * screen_depth; ++i) {				// copy line towards the top of the screen
		video_memory[i] = video_memory[i + screen_width * screen_depth * lines];
	}

	clear_lines(screen_height-1-lines, screen_height - 1);							// clear old lines


	if((cursor_y - lines) < 0) {													// adjust cursor position
		cursor_x = 0;
		cursor_y = 0;
	} else {
		cursor_y -= lines;
	}

	update_cursor();

}


void newline_check() {
	if(cursor_y >= screen_height) scroll_up(1);
}


char get_default_color() {
	return default_color;
}


void set_default_color(char color) {
	default_color = color;
}


char get_default_selection_color() {
	return default_selection_color;
}


void set_default_selection_color(char color) {
	default_selection_color = color;
}


void print_char_color(char c, char color) {

	string video_memory = (string) 0xb8000;

	switch(c) {

		case (0x08):
			if(cursor_x > 0) {
				--cursor_x;
				video_memory[(cursor_y * screen_width +cursor_x) * screen_depth] = 0x0;
			}
			break;
		case ('\r'):
			cursor_x = 0;
			break;
		case ('\n'):
			cursor_x = 0;
			++cursor_y;
			break;
		default:
			video_memory[((cursor_y * screen_width + cursor_x)) * screen_depth] = c;
			video_memory[((cursor_y * screen_width + cursor_x)) * screen_depth + 1] = color;
			++cursor_x;
	}

	if(cursor_x >= screen_width) {
		cursor_x = 0;
		++cursor_y;
	}

	update_cursor();
	newline_check();

}


void print_char(char c) {
	print_char_color(c, default_color);
}


void print_color(string text, char col) {

	uint16 string_len = str_len(text);
	uint16 i = 0;
	for(i; i < string_len; ++i) {
		print_char_color(text[i], col);
	}

}


void print(string text) {

	print_color(text, default_color);

}


void print_bar_color(char color) {
	for(int x = 0; x < screen_width; ++x) print_char_color('-', color);
}


void print_bar() {
	print_bar_color(default_color);
}