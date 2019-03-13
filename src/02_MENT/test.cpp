#include "pascal_string.hpp"
#include "print_pascal_string.hpp"

int main() {
  PascalString ps ("test");
	ps.append('a');
	ps.append('b');
  printPascalString(ps.reverse());
  return 0;
}
