#include "../include/menu.h"

// display a menu with two options and a question
// string question: text to be displayed
// string opt0: option 1 text
// string opt1: option 2 text
// returns 0 or 1
uint8 display_menu(string question, string opt0, string opt1) {

	// store the current default color
	char color_restore = get_default_color();

	uint8 active = 1;
	
	// keep track of the current choice
	int8 choice = 0;
	
	// number of choices
	uint8 choices = 1;

	// keep running until a choice is selected
	while(active) {

		// clear screen and print text
		clear_screen();
		print_greeting();

		// print the supplied question-string
		print(question);

		// iterate through choices and display the text
		// active choice gets colored differently
		for(uint8 i = 0; i <= choices; ++i) {
			
			// if the currently to be rendered-choice is selected, it gets colored differently
			// done by swapping fore- and background-colors
			if(i == choice) set_default_color(get_default_selection_color());

			switch(i) {
				case 0:
					print(opt0);
					break;
				case 1:
					print(opt1);
					break;
			}
			
			// restore the background color
			set_default_color(color_restore);
		}
		
		// wait for the user to press wither UP, DOWN or ENTER
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

	// return user's choice
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
