#include "pascal_string.hpp"
#include "print_pascal_string.hpp"

PascalString intToHex(int number) {
	PascalString ps;
	for (int i = (sizeof(number) * 8) - 4; i >= 0; i -= 4) {
		int x = (number >> i) & 0b1111;
		char out;
		if(x < 10){
			out = x + 48;
		} else {
			out = x + 87;
		}
		ps.append(out);
	}
	return ps;
}

