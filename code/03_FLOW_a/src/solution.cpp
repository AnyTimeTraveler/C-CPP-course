#include <stdio.h>  /* file main_mp2_FLOW_a.cpp */
#include "../helpers/AnsiConsole.h"
#define INITPRINT(label) {firstLine=__LINE__;console.printText(2*currentTick,0,label,Colors::WHITE);}
#define PRINT printLineNumber(__LINE__)

AnsiConsole console;
int firstLine;
int currentTick;
Colors currentColor;

void printLineNumber(int lineNumber);

void recurse(int); // forward declaration because of firstLine initialization
void start_Recursion() {
    INITPRINT("Recursion");
    PRINT;
    recurse(10);
    PRINT;
}

void recurse(int turns) {
    PRINT;
    if (turns > 0) {
        PRINT;
        recurse(turns - 1);
    }
    PRINT;
}


void start_Sequence(void) {
    INITPRINT("Sequence");
    PRINT;
    PRINT;
    PRINT;
    PRINT;
    PRINT;
    PRINT;
    PRINT;
    PRINT;
    PRINT;
    PRINT;
}


void start_SeqSelection(void) {
    INITPRINT("Selection");
    PRINT;
    int b = 1;
    PRINT;
    if (b == 1) {
        PRINT;
        PRINT;
        PRINT;
        PRINT;
        PRINT;
    } else {
        PRINT;
        PRINT;
        PRINT;
        PRINT;
        PRINT;
    }
    PRINT;
    PRINT;
}


void start_Iteration(void) {
    INITPRINT("Iteration");
    PRINT;
    int i = 9;
    PRINT;
    while (i >= 0) {
        PRINT;
        i--;
    }
    PRINT;
    PRINT;
}


int func_1(int arg);

// Sequence, Selection, Iteration, Subroutine
void start_subroutine(void) {
    INITPRINT("Subroutine");
    PRINT;
    func_1(1);
    PRINT;
    func_1(1);
    PRINT;
}

int func_1(int arg) {
    PRINT;
    int local_1;
    PRINT;
    PRINT;
    PRINT;
    PRINT;
    return arg * local_1;
}


int main(int argc, const char *argv[]) {
    console.clearScreen();
    currentColor = Colors::CYAN;
    start_Recursion();


//    currentColor = Colors::BLUE;
//    start_Sequence();
//    currentColor = Colors::RED;
//    start_SeqSelection();
//    currentColor = Colors::YELLOW;
//    start_subroutine();
//    currentColor = Colors::GREEN;
//    start_Iteration();

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

