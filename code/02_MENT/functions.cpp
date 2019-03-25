#include "pascal_string.hpp"
#include <iostream>

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

void printPascalString(PascalString ps) {
	for (int i = 0; i < ps.length; i++) {
		std::cout << ps.characters[i];
	}
	std::cout << '\n';
}

PascalString bitwiseDualAnd(PascalString a, PascalString b) {
  PascalString r;
  for (int i = 0; i < a.length; ++i) {
    r.characters[i] = a.characters[i] == '1' && b.characters[i] == '1' ? '1' : '0';
  }
  r.length = a.length;
  return r;
}

uint8_t hexCharToByte(char hexDigit){
	// digits
	if (hexDigit >= 48 && hexDigit <= 57) {
		return hexDigit - 48;
	}
	// lowercase chars
	if (hexDigit >= 65 && hexDigit <= 69) {
		return hexDigit - 55;
	}
	// upper case chars
	if (hexDigit >= 97 && hexDigit <= 102) {
		return hexDigit - 87;
	}

	// out of range
	return -1;
}

char byteToHexChar(uint8_t byte){
	// digits
  if (byte < 10) {
		return byte + 48;
	}
	// lowercase chars
	if (byte > 9) {
		return byte + 55;
	}
	// out of range
	return -1;
}

PascalString bitwiseHexAnd(PascalString a, PascalString b) {
  PascalString r;

  for (int i = 0; i < a.length; ++i) {
    r.characters[i] = byteToHexChar(hexCharToByte(a.characters[i]) & hexCharToByte(b.characters[i]));
  }
  r.length = a.length;
  return r;
}

