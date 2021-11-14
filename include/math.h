#ifndef MATH_H
#define MATH_H

#include "types.h"
#include "screen.h"
#include "string.h"

int32 string_to_int32(string);

uint32 string_to_uint32(string);

int64 string_to_int64(string);

uint64 string_to_uint64(string);

string int64_to_string(int64);

string uint64_to_string(uint64);

void calculate_pi_gl(uint8);

void calculate_pi_n(uint8);

#endif