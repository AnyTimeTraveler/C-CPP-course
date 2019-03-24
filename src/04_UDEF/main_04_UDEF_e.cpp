// file main_04_UDEF_e.cpp
#include "../helpers/println.hpp"
#include <iostream>

const int bitsPerOctet=8;

struct BinaryOctet {
  bool evenParity;   // set to true if number of '1' in bitsAsDigits is even, false otherwise
  char bitsAsDigits[bitsPerOctet]; // bit values as chars
  BinaryOctet(int x=0);
  BinaryOctet(const BinaryOctet&) = default;
};

BinaryOctet::BinaryOctet(int x){
  // TODO: implement
}


BinaryOctet doCalculation(BinaryOctet a, BinaryOctet b){
  BinaryOctet result;
  
  for(; a != b; b--){
    a = a + 1;
    a = a / b;
  }
  result = a + b;
  
  return result;
}

// for println();
std::string as_string(BinaryOctet a){
  std::string result = "(";
  // TODO: implement
  result += ")";
  return result;
}

// for std::cout
/*std::ostream& operator<< (std::ostream& os, const BinaryOctet &toBePrinted){
	os << "(" << ")";
	return os;
}*/

int main(int argc, char **argv)
{
  BinaryOctet a = 0b00001111;
  BinaryOctet b = 0b00000110;
  println("result = ", doCalculation(a,b));
  //std::cout << "result = " << doCalculation(a,b) << std::endl;
  return 0;
}
