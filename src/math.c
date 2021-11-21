#include "../include/math.h"

// parse a string to a 32bit signed integer
// accepts a leading dash to indicate negative numbers
int32 string_to_int32(string str) {

	// when iterating backwards through the string, multiplier gets multiplied by ten
	//  on every iteration
	// this is how our decimal-system works
	int32 multiplier = 1;
	
	// stores the resulting integer
	int32 result = 0;
	
	// when iterating, this stores the value of the current character
	int16 add = 0;

	// iterate backwards
	for(int16 pos = str_len(str)-1; pos >= 0; --pos) {
		
		// check if the resulting number will be positive
		if(str[pos] != '-') {
			
			// convert character to an int and subtract 48
			// that way the ascii-value 48 refers to 0, 49 to 1 and so on
			add = str[pos] - 48;
			
			// append the value to the result and multiply with the multiplier to simulate a shift
			result += add * multiplier;
			multiplier *= 10;
		} else {
			
			// multiply result with -1
			return result * -1;
		}
	}

	return result;

}


uint32 string_to_uint32(string str) {
	return 0;
}


int64 string_to_int64(string str) {
	return 0;
}


uint64 string_to_uint64(string str) {
	return 0;
}


string int64_to_string(int64 num) {
	return 0;
}


string uint64_to_string(uint64 num) {
	return 0;
}


// this is where pi will be calculated using the Gregory-Leibniz series
void calculate_pi_gl(uint8 visualOutput) {

	print("\nStill to be developed (README.md) :(\n");

}


// this is where pi will be calculated using Nilakantha series
void calculate_pi_n(uint8 visualOutput) {

	print("\nStill to be developed (README.md) :(\n");

}
