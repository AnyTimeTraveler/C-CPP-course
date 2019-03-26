// file: main_02_MENT.cpp
// THIS IS C++, use clang++

#include "../helpers/println.hpp"
#include <iostream>
#include <cstring>
//include <cstdint>
#include "functions.hpp"
#include "pascal_string.hpp"

// helper function for print() and println()
// no need to understand it right now
std::string as_string(PascalString p){
  p.characters[p.length]=0;
  std::string s(p.characters);
  return s;
}

// convenience function for creation
PascalString fromString(std::string s){
  PascalString p;
  p.length = s.length();
  for(int i = 0; i < p.length; i++){
    p.characters[i] = s[i];
  }
  return p;
}

int hexDigitToInt(char hexDigit){
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

int hexStringToInt(PascalString binaryDigits){
	int returnValue = hexDigitToInt(binaryDigits.characters[binaryDigits.length - 1]);
	int base = 16;
	for (int i = binaryDigits.length - 2; i >= 0; i--) {
		returnValue += base * hexDigitToInt(binaryDigits.characters[i]);
		base *= 16;
	}
	return returnValue;
}

int main(){
	for (int i = 0; i < 16; i ++) {
		std::stringstream stream;
		stream << std::hex << i;
		std::string result (stream.str());
		char cstr[result.size()];
		strcpy(cstr, result.c_str());
		PascalString ps (cstr);
		println(hexStringToInt(ps));
	}
	println("\n");
	
	PascalString s ("100");
	PascalString s2 ("ffff");
	println(hexStringToInt(s));
  println(hexStringToInt(s2));
  println(fromString("Hello, World!"));
  return 0;
}

