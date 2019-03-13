#include "pascal_string.hpp"
#include "print_pascal_string.hpp"

PascalString intToDual(int number) {
	PascalString ps;
	for (; number > 0; number /=2) {
		if (number % 2 == 1) {
      //printf("1");
			ps.append('1');
		} else {
			//printf("0");
      ps.append('0');
		}
	}
	return ps.reverse();
}

