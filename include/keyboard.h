#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "system.h"
#include "screen.h"
#include "types.h"

string str_read();

char get_keystroke();

void write_char(string*, char, uint8*);

void delete_char(string*, uint8*);

#endif