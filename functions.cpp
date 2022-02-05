#include "functions.h"

bool is_valid_range(int a, int b) {
    if (a > b || b > 10000 || a <= 0) {
		return false;
	} else {
		return true;
	}
}

int count_digit_occurrences(int number, int digit) {
	int counter = 0;
	
	if (number < 0) {
		number *= -1;
	}
	
	while (number >= 10) {
		if (number % 10 == digit) {
			++counter;
		}
		number /= 10;
	}
	if (number == digit) {
		++counter;
	}
	return counter;
}

bool has_repeated_digits(int number) {
    for (int i = 0; i < 10; ++i) {
		if (count_digit_occurrences(number, i) > 1) {
			return true;
		}
	}
    return false;
}

int count_valid_numbers(int a, int b) {
	int valid_count = 0;
    for (int i = a; i <= b; ++i) {
		if (has_repeated_digits(i)) {
			++valid_count;
		}
	}
    return valid_count;
}
