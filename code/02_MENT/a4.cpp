
#include "functions.hpp"

int main() {
	PascalString a ("011010");
	PascalString b ("000110");
  
  printPascalString(bitwiseDualAnd(a, b));
	return 0;
}
