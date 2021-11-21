#include "../include/hexcodes.h"
#include "../include/keyboard.h"
#include "../include/screen.h"
#include "../include/string.h"
#include "../include/pios.h"

// kernel entrypoint
void kmain() {
	
	// clears the screen
	clear_screen();
	
	// sets the default colors for printing text
	set_default_color(COLOR_BLACK_LIGHT_GREEN);
	set_default_selection_color(COLOR_LIGHT_GREEN_BLACK);

	// renders the menues
	menu_management();

}
