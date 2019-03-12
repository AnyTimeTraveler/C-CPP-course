#include "pascal_string.hpp"
#include "print_pascal_string.hpp"

PascalString intToDual(int number) {
	PascalString ps = {0};
	for (; number > 0; number /=2) {
		if (number%2 == 1) {
		 	append(ps, '1');
		} else {
			append(ps, '0');
		}
	}
	return reverse(ps);
}

int main() {
	int a = 5;
	printPascalString(intToDual(a));
	return 0;
}
