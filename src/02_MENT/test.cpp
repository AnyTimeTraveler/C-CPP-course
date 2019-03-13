#include "pascal_string.hpp"
#include "print_pascal_string.hpp"

int main() {
  PascalString ps ("test");
  printPascalString(ps.reverse());
  return 0;
}
