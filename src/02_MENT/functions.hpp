#pragma once
#include "pascal_string.hpp"

PascalString intToDual(int);

PascalString intToHex(int);

void printPascalString(PascalString ps);

PascalString bitwiseDualAnd(PascalString a, PascalString b);

PascalString bitwiseHexAnd(PascalString a, PascalString b);

