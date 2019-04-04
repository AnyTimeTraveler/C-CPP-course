// file: RationalNumber.hpp
#include <iostream>

struct RationalNumber{
	int zaehler;
	int nenner;
};

RationalNumber addRationalNumbers(RationalNumber left, RationalNumber right);
RationalNumber operator+ (RationalNumber left, RationalNumber right);
std::string as_string(RationalNumber);  // for println()
std::ostream& operator<< (std::ostream& os, RationalNumber &toBePrinted); // for cout
