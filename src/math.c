#include "../include/math.h"

int32 string_to_int32(string str) {

	int32 multiplier = 1;
	int32 result = 0;
	int16 add = 0;

	for(int16 pos = str_len(str)-1; pos >= 0; --pos) {
		if(str[pos] != '-') {
			add = str[pos] - 48;
			result += add * multiplier;
			multiplier *= 10;
		} else {
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


void calculate_pi_gl(uint8 visualOutput) {

	print("\nStill to be developed (README.md) :(\n");

}

void calculate_pi_n(uint8 visualOutput) {

	print("\nStill to be developed (README.md) :(\n");

}
