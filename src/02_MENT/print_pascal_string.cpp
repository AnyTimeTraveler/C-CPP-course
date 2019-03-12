#include "pascal_string.hpp"
#include <iostream>

void printPascalString(PascalString ps) {
	for (int i = 0; i < ps.length; i++) {
		std::cout << ps.characters[i];
	}
	std::cout << '\n';
}

