#pragma once
#include <cstdint>
#include <iostream>

class PascalString {
  public:
  	uint8_t length;        // number of chars used as "unsigned integer type with width of exactly 8 bits"
	  char characters[256];  // chars of some character string
                           // 255 for Characters + 1 spare
    PascalString(char[]);
    PascalString() : length() {};
    PascalString reverse();
    void append(char);
    std::string toString();
};

