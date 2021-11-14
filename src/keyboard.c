#include "../include/keyboard.h"

/*
string str_read() {

	//char buffer;
	string buffer_str;
	uint8 i = 0;
	uint8 reading = 1;

	// 0x64: key pressed?
	// 0x60: key


	while(reading) {

		if(inportb(0x64) & 0x1) {

			// TODO: add length check to avoid buf overflow
			switch(inportb(0x60)) {

				case 2:
					write_char(&buffer_str, '1', &i);
					break;
				case 3:
					write_char(&buffer_str, '2', &i);
					break;
				case 4:
					write_char(&buffer_str, '3', &i);
					break;
				case 5:
					write_char(&buffer_str, '4', &i);
					break;
				case 6:
					write_char(&buffer_str, '5', &i);
					break;
				case 7:
					write_char(&buffer_str, '6', &i);
					break;
				case 8:
					write_char(&buffer_str, '7', &i);
					break;
				case 9:
					write_char(&buffer_str, '8', &i);
					break;
				case 10:
					write_char(&buffer_str, '9', &i);
					break;
				case 11:
					write_char(&buffer_str, '0', &i);
					break;
				case 12:
					write_char(&buffer_str, '-', &i);
					break;
				case 13:
					write_char(&buffer_str, '=', &i);
					break;
				case 14:
					delete_char(&buffer_str, &i);
					break;
				case 15:
					write_char(&buffer_str, ' ', &i);
					break;
				case 16:
					write_char(&buffer_str, 'q', &i);
					break;
				case 17:
					write_char(&buffer_str, 'w', &i);
					break;
				case 18:
					write_char(&buffer_str, 'e', &i);
					break;
				case 19:
					write_char(&buffer_str, 'r', &i);
					break;
				case 20:
					write_char(&buffer_str, 't', &i);
					break;
				case 21:
					write_char(&buffer_str, 'y', &i);
					break;
				case 22:
					write_char(&buffer_str, 'u', &i);
					break;
				case 23:
					write_char(&buffer_str, 'i', &i);
					break;
				case 24:
					write_char(&buffer_str, 'o', &i);
					break;
				case 25:
					write_char(&buffer_str, 'p', &i);
					break;
				case 26:
					write_char(&buffer_str, '[', &i);
					break;
				case 27:
					write_char(&buffer_str, ']', &i);
					break;
				case 28:
					//write_char(&buffer_str, '\n', &i);
					++i;

					reading = 0;
					break;
				case 29:
					// left ctrl
					break;
				case 30:
					write_char(&buffer_str, 'a', &i);
					break;
				case 31:
					write_char(&buffer_str, 's', &i);
					break;
				case 32:
					write_char(&buffer_str, 'd', &i);
					break;
				case 33:
					write_char(&buffer_str, 'f', &i);
					break;
				case 34:
					write_char(&buffer_str, 'g', &i);
					break;
				case 35:
					write_char(&buffer_str, 'h', &i);
					break;
				case 36:
					write_char(&buffer_str, 'j', &i);
					break;
				case 37:
					write_char(&buffer_str, 'k', &i);
					break;
				case 38:
					write_char(&buffer_str, 'l', &i);
					break;
				case 39:
					write_char(&buffer_str, ';', &i);
					break;
				case 40:
					// (')
					break;
				case 41:
					// (`)
					break;
				case 42:
					// lshift
					break;
				case 43:
					// some
				case 44:
					write_char(&buffer_str, 'z', &i);
					break;
				case 45:
					write_char(&buffer_str, 'x', &i);
					break;
				case 46:
					write_char(&buffer_str, 'c', &i);
					break;
				case 47:
					write_char(&buffer_str, 'v', &i);
					break;
				case 48:
					write_char(&buffer_str, 'b', &i);
					break;
				case 49:
					write_char(&buffer_str, 'n', &i);
					break;
				case 50:
					write_char(&buffer_str, 'm', &i);
					break;
				case 51:
					write_char(&buffer_str, ',', &i);
					break;
				case 52:
					write_char(&buffer_str, '.', &i);
					break;
				case 53:
					write_char(&buffer_str, '/', &i);
					break;
				case 54:
					write_char(&buffer_str, '.', &i);
					break;
				case 55:
					write_char(&buffer_str, '/', &i);
					break;
				case 56:
					// right shift
					break;
				case 57:
					write_char(&buffer_str, ' ', &i);
					break;
			}
		}
	}

	buffer_str[i-1] = 0;
	return buffer_str;

}
*/


char get_keystroke() {

	uint8 reading = 1;

	while(reading) {

		if(inportb(0x64) & 0x1) {

			char input = inportb(0x60);

			if(input == 0x48 || input == 0x4b || input == 0x4d || input == 0x50 || input == 0x1c) return input;

		}

	}

	return 0x0;
}


void write_char(string *buffer_str, char c, uint8 *index) {
	print_char(c);
	*buffer_str[*index] = c;
	++*index;
}


void delete_char(string *buffer_str, uint8 *index) {
	print_char('\b');
	--*index;
	if(*index < 0) *index = 0;
	*buffer_str[*index + 1] = 0;
	*buffer_str[*index] = 0;
}