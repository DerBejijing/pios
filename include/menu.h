#ifndef MENU_H
#define MENU_H

#include "keyboard.h"
#include "math.h"
#include "pios.h"
#include "screen.h"
#include "types.h"
#include "hexcodes.h"

uint8 display_menu(string, string, string);

uint8 get_output_representation();

uint8 get_select_goal();

uint8 get_select_algorithm_pi();

uint8 get_select_algorithm_e();

#endif