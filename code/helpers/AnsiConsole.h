
#include <iostream>

enum class Colors {
  BLACK   = 30,
  RED     = 31,
  GREEN   = 32,
  YELLOW  = 33,
  BLUE    = 34,
  MAGENTA = 35,
  CYAN    = 36, 
  WHITE   = 37
};

class AnsiConsole {
  // protected:
  // can only be used by members of AnsiConsole and its 
  // derived classes
protected:            
  void hideCursor();
  void showCursor();
  void pushCursorPos();
  void popCursorPos();
  
public:
  AnsiConsole();
  ~AnsiConsole();
  void clearScreen();
  void printText(int x, int y, std::string text, Colors color=Colors::BLUE);
};

extern AnsiConsole ansiConsole;


