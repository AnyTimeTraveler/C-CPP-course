#include <iostream>
#include <cmath>
#include "AnsiConsole.h"

struct Position{
  int x;
  int y;
  Position(int x_=0, int y_=0){ x=x_;y=y_;}
};

class Point{
protected:
  Position _position;
public:
  Point(int x=0, int y=0);
  void draw();
};

Point::Point(int x, int y){
  _position = Position(x,y);
}

void Point::draw(){
  ansiConsole.printText(_position.x,_position.y,"*", Colors::RED);
}

class Circle{
protected:
  Position  _position;
  int       _radius;
public:
  Circle(int x=0, int y=0, int radius=0);
  void draw();
};

Circle::Circle(int x, int y, int radius){
  _position = Position(x,y);
  _radius=radius;
}

void Circle::draw(){
  /* see https://de.wikibooks.org/wiki/Formelsammlung_Mathematik:_Geometrie
   * Höhensatz des Euklid
   * */
  int x_start = _position.x - _radius/2;
  int x_stop  = _position.x + _radius/2;

  for(int i=x_start; i<=x_stop; i++){
    double x_relative = double(i) - double(x_start);
    double h = sqrt(x_relative*(x_stop-x_start-x_relative));
    ansiConsole.printText(_position.x + int(x_relative)- _radius/2,
                          _position.y +h,"#",
                          Colors::GREEN);
    ansiConsole.printText(_position.x + int(x_relative)- _radius/2,
                          _position.y -h,"#",
                          Colors::GREEN);

  }
}

int main(int argc, char **argv)
{
  // x=1 and y=1 is the upper left corner
  // x and y are more like column and row
  ansiConsole.printText(5,5,"Hello, World!");

  Point* p = new Point(10,10);
  p->draw();

  Point* p2 = new Point(2,10);
  p2->draw();


  Circle* c = new Circle(30, 15, 10);
  c->draw();

  Point* p3= new Point(30,15);
  p3->draw();


  delete p;
  delete p2;
  delete p3;
  delete c;

  return 0;
}
