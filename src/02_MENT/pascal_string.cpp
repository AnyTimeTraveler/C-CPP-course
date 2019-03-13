#include <cstdint>
#include <iostream>
#include <string.h>
#include "pascal_string.hpp"

PascalString::PascalString(char initial[]) {
  strcpy(characters, initial);
  length = strlen(initial);
}

PascalString PascalString::reverse() {
	PascalString output;
  output.length = length;
	for(int i = 0; i < length; i++) {
		output.characters[i] = characters[length - 1 - i];
	}
	return output;
}

void PascalString::append(char x) {
  characters[length] = x;
	length++;
}

std::string PascalString::toString() {
  characters[length] = 0;
  std::string output (characters);
  return output;
}
