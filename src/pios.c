#include "../include/pios.h"

// stores a value between 0 and 3 (inclusive) to store a number representing
//  every available algorithm to calculate e or pi
// 0: pi using the Gregory-Leibniz series
// 1: pi using the Nilakantha series
// 2: e using ???
// 3: e using ???
uint8 goal = 0;

// either 0 or 1, used to decide whether a visual output will be displayed
uint8 output_representation = 0;

// to not recreate the greeting-screen every time, this stores whether or not it has already been created
uint8 generated_greeting = 0;

// first digits of pi and a pattern
// all "a"s will be replaced with digits of pi
const string first_pi_digits = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989380952572010654858632788659361533818279682303019520353018529689957736225994138912497217752834791315155748572424541506959508295331168617278558890750983817546374649393192550604009277016711390098488240128583616035637076601047101819429555961989467678374494482553797747268471040475346462080466842590694912933136770289891521047521620569660240580381501935112533824300355876402474964732639141992726042699227967823547816360093417216412199245863150302861829745557067498385054945885869269956909272107975093029553211653449872027559602364806654991198818347977535663698074265425278625518184175746728909777727938000816470600161452491921732172147723501414419735685481613611573525521334757418494684385233239073941433345477624168625189835694855620992192221842725502542568876717904946016534668049886272327917860857843838279679766814541009538837863609506800642251252051173929848960841284886269456042419652850222106611863067442786220391949450471237137869609563643719172874677646575739624138908658326459958133904780275900";
const string greeting_pattern = "\
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
aaaaaaQQQQQQQQQQQQaaaaaaQQQaaaaaaaaaQQQQQQQQQaaaaaaaaaQQQQQQQQQaaaaaaaaaaaaaaaaa\
aaaaaaQQQQQQQQQQQQaaaaaaQQQaaaaaaaaaQQQQQQQQQaaaaaaaaaQQQQQQQQQaaaaaaaaaaaaaaaaa\
aaaaaaQQQaaaaaaaaaQQQaaaaaaaaaaaaQQQaaaaaaaaaQQQaaaQQQaaaaaaaaaQQQaaaaaaaaaaaaaa\
aaaaaaQQQaaaaaaaaaQQQaaaQQQaaaaaaQQQaaaaaaaaaQQQaaaQQQaaaaaaaaaQQQaaaaaaaaaaaaaa\
aaaaaaQQQQQQQQQQQQaaaaaaQQQaaaaaaQQQaaaaaaaaaQQQaaaQQQaaaaaaaaaaaaaaaaaaaaaaaaaa\
aaaaaaQQQQQQQQQQQQaaaaaaQQQaaaaaaQQQaaaaaaaaaQQQaaaaaaQQQQQQQQQaaaaaaaaaaaaaaaaa\
aaaaaaQQQaaaaaaaaaaaaaaaQQQaaaaaaQQQaaaaaaaaaQQQaaaaaaQQQQQQQQQaaaaaaaaaaaaaaaaa\
aaaaaaQQQaaaaaaaaaaaaaaaQQQaaaaaaQQQaaaaaaaaaQQQaaaaaaaaaaaaaaaQQQaaaaaaaaaaaaaa\
aaaaaaQQQaaaaaaaaaaaaaaaQQQaaaaaaQQQaaaaaaaaaQQQaaaQQQaaaaaaaaaQQQaaaaaaaaaaaaaa\
aaaaaaQQQaaaaaaaaaaaaaaaQQQaaaaaaQQQaaaaaaaaaQQQaaaQQQaaaaaaaaaQQQaaaaaaaaaaaaaa\
aaaaaaQQQaaaaaaaaaaaaaaaQQQaaaaaaaaaQQQQQQQQQaaaaaaaaaQQQQQQQQQaaaaaaaaaaaaaaaaa\
aaaaaaQQQaaaaaaaaaaaaaaaQQQaaaaaaaaaQQQQQQQQQaaaaaaaaaQQQQQQQQQaaaaaaaaaaaaaaaaa\
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

string greeting = greeting_pattern;


// generates a very fancy banner containing the first digits of pi
void generate_greeting() {

	uint16 pattern_length = str_len(greeting_pattern);
	uint16 index = 0;

	for(; index < pattern_length; ++index) {
		if(greeting_pattern[index] == 'a') greeting[index] = first_pi_digits[index];
		else greeting_pattern[index] = ' ';
	}

}


// displays the greeting-banner and some text
void print_greeting() {

	if(!generated_greeting) {
		generate_greeting();
		generated_greeting = 1;
	}

	print(greeting);
	print_bar();
	print("                                Welcome to PI-OS\n");
	print_bar();
	print_char('\n');

}


// manages the active menu and what to execute afterwards
void menu_management() {

	output_representation = get_output_representation();

	uint8 active = 1;
	uint8 active_menu = 1;
	uint8 tmp = 1;


	while(active) {
		switch(active_menu) {
			case 0:
				// add an array to keep track of previous menus
				// to add a "back" functionality
				break;
			case 1:
				tmp = get_select_goal();
				if(tmp == 0) active_menu = 2;
				else active_menu = 3;
				break;
			case 2:
				goal = get_select_algorithm_pi();
				active = 0;
				break;
			case 3:
				goal = get_select_algorithm_e() + 2;
				active = 0;
				break;
			case 4:
				break;
		}
	}


	clear_screen();
	print_greeting();

	print("\nPress enter to start computing target:\n");
	switch(goal) {
		case 0:
			print("  Calculate pi using Gregory-Leibniz series\n");
			break;
		case 1:
			print("  Calculate pi using Nilakantha series\n");
			break;
		case 2:
			print("  Calculate Euler's number using ???\n");
			break;
		case 3:
			print("  Calculate Euler's number using ???\n");
			break;
	}

	uint8 checking = 1;
	while(checking) {
		char c = get_keystroke();
		if(c == 0x1c) checking = 0;
	}

	switch(goal) {
		case 0:
			calculate_pi_gl(output_representation);
			break;
		case 1:
			calculate_pi_n(output_representation);
			break;
	}	

}
