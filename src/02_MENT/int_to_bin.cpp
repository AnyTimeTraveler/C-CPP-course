#include "print_pascal_string.hpp"

PascalString intToDual(int number) {
	PascalString ps = {0};
	for (; number > 0; number /=2) {
		if (number%2 == 1) {
      ps.append('1');
		} else {
      ps.append('0');
		}
	}
	return ps.reverse();
}

