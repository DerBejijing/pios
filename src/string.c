#include "../include/string.h"

uint16 str_len(string str) {

	uint16 counter = 0;
	while (str[counter] != 0x0) {
		++counter;
	}
	return counter;

}


uint8 str_equals(string str1, string str2) {
	
	uint16 str1_len = str_len(str1);
	uint16 str2_len = str_len(str2);

	if(str1_len != str2_len) return 0;
	else {
		uint16 i = 0;
		for(; i <= str1_len; ++i) {
			if(str1[i] != str2[i]) {
				return 0;
			}
		}
	}
	return 1;

}


string center_string(string str, uint16 size) {
	return "";
}