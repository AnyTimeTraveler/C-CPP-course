#include "pascal_string.hpp"
#include "print_pascal_string.hpp"

PascalString intToDual(int number) {
	PascalString ps;
	for (int i = sizeof(number) * 8; i > 0; i--) {
		if (number >> i & 1) {
			ps.append('1');
		} else {
      ps.append('0');
		}
	}
	return ps;
}

