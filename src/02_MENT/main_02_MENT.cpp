// file: main_02_MENT.cpp
// THIS IS C++, use clang++

#include "../helpers/println.hpp"
#include <iostream>
//include <cstdint>
#include "pascal_string.cpp"

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
  for(int i=0; i<s.length(); i++){
    p.characters[i] = s[i];
  }
  return p;
}




int hexDigitToInt(char hexDigit){
	switch (hexDigit) {
		case '0':
			return 0;
	  case '1':
			return 1;
	  case '2':
			return 2;
	  case '3':
			return 3;
	  case '4':
			return 4;
	  case '5':
			return 5;
	  case '6':
			return 6;
	  case '7':
			return 7;
	  case '8':
			return 8;
	  case '9':
			return 9;
	  case 'a':
	  case 'A':
			return 10;
		case 'b':
	  case 'B':
			return 11;
	 	case 'c':
	  case 'C':
			return 12;
		case 'd':
	  case 'D':
			return 13;
		case 'e':
	  case 'E':
			return 14;
		case 'f':
	  case 'F':
			return 15;
		default:
			return -1;
	}
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

int main(int argc, char** argv, char** envp){
	PascalString s = {3, '1', '0', '0'};
	PascalString s2 = {4, 'f', 'f', 'f', 'f'};
  println(hexStringToInt(s));
  println(hexStringToInt(s2));
  println(fromString("Hello, World!"));
  	return 0;
}

