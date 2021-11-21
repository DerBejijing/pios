#include "../include/keyboard.h"

// if one of the important keys was pressed, return that key
// keys are ARROW_UP, ARROW_DOWN, ARROW_LEFT, ARROW_RIGHT, ENTER
char get_keystroke() {

	uint8 reading = 1;
	
	// keep reading until an inportant key is pressed
	while(reading) {

		// check if a key is pressed
		if(inportb(0x64) & 0x1) {

			// store hex-value of the key
			char input = inportb(0x60);

			// compare hex-value and return if it matches any of the important keys:
			// ARROW_UP, ARROW_DOWN, ARROW_LEFT, ARROW_RIGHT, ENTER
			if(input == 0x48 || input == 0x4b || input == 0x4d || input == 0x50 || input == 0x1c) return input;

		}

	}

	// useless, but I keep it in case I want to add a way to cancel the input
	return 0x0;
}


// writes a char into a buffer
// previously used when prompting the user to enter a mutli-character-string
// string *buffer: pointer to the buffer
// char c: character to append
// uint8 *index: pointer to the index variable that will be incremented
void write_char(string *buffer_str, char c, uint8 *index) {
	print_char(c);
	*buffer_str[*index] = c;
	++*index;
}


// deletes the last char in the buffer
// previously used when prompting the user to enter a multi-character-string
// string *buffer: pointer to the buffer that is to be edited
// uint *index: pointer to the index variable that will be decremented
void delete_char(string *buffer_str, uint8 *index) {
	// sets the curser back by one character
	print_char('\b');
	--*index;
	if(*index < 0) *index = 0;
	
	// delete the character and the char that indicated the color
	*buffer_str[*index + 1] = 0;
	*buffer_str[*index] = 0;
}
