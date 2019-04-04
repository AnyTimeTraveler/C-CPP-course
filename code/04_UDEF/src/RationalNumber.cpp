// file: RationalNumber.cpp
#include "RationalNumber.hpp"

RationalNumber addRationalNumbers(RationalNumber left, RationalNumber right){
	RationalNumber result;
	// add left and right
    result.nenner = left.nenner * right.nenner;
    result.zaehler = left.zaehler * right.zaehler + right.zaehler * left.nenner;
	return result;
}

RationalNumber operator+ (RationalNumber left, RationalNumber right){
	return addRationalNumbers(left, right);
}

// for println()
std::string as_string(RationalNumber r){
  std::string result = "(";
  result += std::to_string(r.zaehler);
  result += "/";
  result += std::to_string(r.nenner);
  result += ")";
  return result;
}

std::ostream& operator<< (std::ostream& os, RationalNumber &toBePrinted){
	os << "(" << toBePrinted.zaehler << "/"
	<< toBePrinted.nenner << ")";
	return os;
}
