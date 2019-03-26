#include "functions.hpp"

char cStringArea[1024];

int to_cstring(PascalString a) {
  int found = -1;
  for (int i = 0; i < 1024; ++i) {
    if (cStringArea[i] == '\0') {
      found = i;
      break;
    }
  }

  if (found != -1) {
    for (int i = 0; i < a.length; ++i) {
      cStringArea[found + i] = a.characters[i];
    }
    cStringArea[found + a.length] = '\0';
  }
  return found;
}

int main() {
	PascalString a ("aaa");
	PascalString b ("bbb");
	PascalString c ("ccc");
	int apos = to_cstring(a);
  int cpos = to_cstring(c);
  int bpos = to_cstring(b);

  for (int i = 0; i < 1024; ++i) {
    std::cout << cStringArea[i];
  }
  std::cout << std::endl;
	return 0;
}
