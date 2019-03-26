// file: main_02_MENT.cpp
// THIS IS C++, use clang++

#include "../helpers/println.hpp"
#include <iostream>
#include <cstring>
//include <cstdint>
#include "print_pascal_string.hpp"
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
  for(int i = 0; i < s.length(); i++){
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






int hexalDigitToInt(char hexDigit){
	// digits
	if (hexDigit >= '0' && hexDigit <= '6') {
		return (int) (hexDigit - '0');
	}
	
	// out of range
	return -1;
}

int hexalStringToInt(PascalString binaryDigits){
	int returnValue = hexalDigitToInt(binaryDigits.characters[binaryDigits.length - 1]);
	int base = 6;
	for (int i = binaryDigits.length - 2; i >= 0; i--) {
		returnValue += base * hexalDigitToInt(binaryDigits.characters[i]);
		base *= 6;
	}
	return returnValue;
}

char intDigitToHexal(int hexDigit){
	// digits
	if (hexDigit >= 0 && hexDigit <= 6) {
		return (char) hexDigit + '0';
	}
	
	// out of range
	return -1;
}

PascalString intToHexalString(int number){
  PascalString ps;
  for (;number>0;number /=6) {
    char out = number % 6 + '0';
    ps.append(out);
  }
  return ps.reverse();
}

int main(){
	PascalString s ("100");
	PascalString s2 ("123456");

  int si = hexalStringToInt(s);
  int s2i = hexalStringToInt(s2);

  printPascalString(s);
	println(si);
  println(intToHexalString(si));

  printPascalString(s2);
	println(s2i);
  println(intToHexalString(s2i));

  return 0;
}

