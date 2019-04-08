#include <stdio.h>  /* file main_mp2_FLOW_a.cpp */
#include "AnsiConsole.h"

AnsiConsole console;
int firstLine;
int currentTick;
Colors currentColor;
#define INITPRINT(label) {firstLine=__LINE__;console.printText(2*currentTick,0,label,Colors::BLACK);}
#define PRINT printLineNumber(__LINE__)

void printLineNumber(int lineNumber);

void sub(int); // forward declaration because of firstLine initialization

void start01() {
    INITPRINT("INITPRINT start02")
    for (int i = 1; i < 2; ++i) {
        PRINT;sub(5);PRINT;
        PRINT;sub(10);PRINT;
    }
}

void sub(int limit) {
    for (int i = 0; i < limit; PRINT) {
        if (limit == 5) { PRINT; }
        i++;
    }
}




int main(int argc, const char *argv[]) {
    console.clearScreen();
    currentColor = Colors::GREEN;
    start01();

    std::string s;
    std::cin >> s;

    return 0;
}

void printLineNumber(int lineNumber) {
    std::string line = std::to_string(lineNumber);
    currentTick++;
    console.printText(currentTick * 2 - 1, 1 + lineNumber - firstLine, line, currentColor);
}


/*void printLineNumber(int lineNumber){
  std::string line = std::to_string(lineNumber);
  console.printText(currentTick*2, 1+lineNumber-firstLine, line, currentColor);
  currentTick++;
}*/

