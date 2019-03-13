#include "func1.h"
#include "func2.h"
#include <stdio.h>

void recurse(int x);
void revrecurse(int x);

int main(int argc, char **argv) {
	// Grundgeruest
  for(int i = 0;i<=20;i++){
    printf("%d\n", func1(i));
  }
	
	// 2. Aufaddieren
	{
		int sum = 0;
	  for(int i = 0;i<=20;i++) {
		  sum += func2(i);
	  }
	  printf("%d\n", sum);
  }
	// 3. for durch while ersetzen
	{
	  int sum = 0;
	  int i = 0;
	  while (i<=20) {
		  sum += func2(i++);
	  }
	  printf("%d\n", sum);
	}
  
	// 4. Nullstellen ermitteln
	{
	  for(int i = 0;i<=20;i++) {
		  if (func1(i) == 0){
				printf("Null at: %d\n", i);
			}
	  }
  }

	printf("\n\n\n\n");

	// 5. Recursive implementation
	recurse(20);
	
  // 6. Reverse recursive implementation
	revrecurse(20);
}

void recurse(int x) {
	printf("%d -> %d\n", x, func1(x));
	if (x > 0) {
		recurse(x-1);
	}
}

void revrecurse(int x) {
	if (x > 0) {
		revrecurse(x-1);
	}
	printf("%d -> %d\n", x, func1(x));
}

