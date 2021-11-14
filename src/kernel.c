#include "../include/hexcodes.h"
#include "../include/keyboard.h"
#include "../include/screen.h"
#include "../include/string.h"
#include "../include/pios.h"

void kmain() {

	clear_screen();
	set_default_color(COLOR_BLACK_LIGHT_GREEN);
	set_default_selection_color(COLOR_LIGHT_GREEN_BLACK);

	menu_management();

}