#include <stdio.h>  /* file main_mp2_FLOW_a.cpp */
#include "../helpers/AnsiConsole.h"
#define INITPRINT(label) {firstLine=__LINE__;console.printText(2*currentTick,0,label,Colors::WHITE);}
#define PRINT printLineNumber(__LINE__)

AnsiConsole console;int firstLine;int currentTick;Colors currentColor;
void printLineNumber(int lineNumber);
void recurse(int); // forward declaration because of firstLine initialization

void mod1() {
  INITPRINT("Modifikation 1");
  PRINT;
  recurse(6);PRINT;
}
void recurse(int turns) {
  PRINT; if (turns > 0) {
    recurse(turns - 1);
    PRINT;
  }
}

void mod2() {
  INITPRINT("Modifikation 2");
  for (int i = 0; i < 2; i++) {PRINT;
    PRINT; for (int j = 0; j < 4; j++) {
      PRINT;
    }
  }
}

int main(int argc, const char *argv[]) {
  console.clearScreen();

  currentColor = Colors::RED;
  mod1();

  currentColor = Colors::YELLOW;
  mod2();

  std::string s;
  std::cin >> s;
  return 0;
}

void printLineNumber(int lineNumber) {
  std::string line = std::to_string(lineNumber);
  currentTick++;
  console.printText(currentTick * 2 - 1, 1 + lineNumber - firstLine, line, currentColor);
}
