#ifndef PIOS_H
#define PIOS_H

#include "menu.h"
#include "keyboard.h"
#include "screen.h"
#include "string.h"
#include "types.h"

uint8 goal;
uint8 output_representation;
uint8 generated_greeting;

const string first_pi_digits;
const string greeting_pattern;
string greeting;

void generate_greeting();

void print_greeting();

void menu_management();

#endif