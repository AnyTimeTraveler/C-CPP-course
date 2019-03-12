// file: main_02_MENT.cpp
// THIS IS C++, use clang++

#include "../helpers/println.hpp"
#include <iostream>
#include <cstdint>

struct PascalString{
	uint8_t length;        // number of chars used as "unsigned integer type with width of exactly 8 bits"
	char characters[256];  // chars of some character string
                         // 255 for Characters + 1 spare
};

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
int value = -1;
// TBD
return value;
}

int hexStringToInt(PascalString binaryDigits){
int returnValue = -1;

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

