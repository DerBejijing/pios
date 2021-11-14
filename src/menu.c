#include "../include/menu.h"

uint8 display_menu(string question, string opt0, string opt1) {

	char color_restore = get_default_color();

	uint8 active = 1;
	int8 choice = 0;
	uint8 choices = 1;


	while(active) {

		clear_screen();
		print_greeting();

		print(question);

		for(uint8 i = 0; i <= choices; ++i) {
			if(i == choice) set_default_color(get_default_selection_color());

			switch(i) {
				case 0:
					print(opt0);
					break;
				case 1:
					print(opt1);
					break;
			}
			set_default_color(color_restore);
		}

		char key = get_keystroke();
		switch(key) {
			case KEY_UP:
				--choice;
				if(choice < 0) choice = choices;
				break;
			case KEY_DOWN:
				++choice;
				if(choice > choices) choice = 0;
				break;
			case KEY_ENTER:
				active = 0;
		}

	}

	return choice;

}


uint8 get_output_representation() {

	return display_menu("\nChoose an option:\n", "  Only computing\n", "  Compute + visual output (slow)\n");

}


uint8 get_select_goal() {

	return display_menu("\nChoose a goal to compute:\n", "  pi\n", "  e\n");

}


uint8 get_select_algorithm_pi() {

	return display_menu("\nChoose an algorithm to approximate pi:\n", "  Gregory-Leibniz series\n", "  Nilakantha series\n");

}


uint8 get_select_algorithm_e() {

	return display_menu("\nChoose an algorithm to approximate e:\n", "  unset\n", "  unset\n");
	
}