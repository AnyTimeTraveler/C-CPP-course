#include <cstdint>

struct PascalString{
	uint8_t length;        // number of chars used as "unsigned integer type with width of exactly 8 bits"
	char characters[256];  // chars of some character string
                         // 255 for Characters + 1 spare
};

PascalString reverse(PascalString input) {
	PascalString output = {input.length};
	for(int i = 0; i < input.length; i++) {
		output.characters[i] = input.characters[input.length - i];
	}
	return output;
}

void append(PascalString ps, char x) {
	ps.characters[ps.length] = x;
	ps.length += 1;
}
