#include "func1.h"
#include <stdio.h>

int recurse(int);

int main() {
  int sum = 0;
  for (int i = 0; i<= 25; i++) {
    sum += func3(i);
  }
  printf("Summe: %d \n", sum);
  printf("Summe: %d \n", recurse(25));
}

int recurse(int x){
  if(x < 0){
    return 0;
  }

  return func3(x) + recurse(x-1);
}

