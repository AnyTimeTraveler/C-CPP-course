#include <math.h>
#include <utility>
#include <iostream>
#include <cmath>
#include <vector>
#include "AnsiConsole.h"

struct Position {
  int x;
  int y;

  explicit Position(int x = 0, int y = 0) : x(x), y(y) {}
};

class Shape {
private:
  Position position;
  std::string symbol;
protected:
  int getX() {
    return position.x;
  }
  int getY() {
    return position.y;
  }
  std::string* getSymbol(){
    return &symbol;
  }

  virtual void print(int x, int y){
    ansiConsole.printText(position.x + x, position.y + y, symbol, Colors::WHITE);
  }

  virtual void print(int x, int y, std::string text){
    ansiConsole.printText(position.x + x, position.y + y, text, Colors::WHITE);
  }
public:
  explicit Shape(Position position, std::string symbol) : position(position), symbol(symbol) {

  }

  virtual void draw() = 0;

  virtual double area() = 0;

  virtual ~Shape() = default;
};

class ColoredShape : public Shape {
private:
  Colors color;
protected:
  void print(int x, int y) override {
    ansiConsole.printText(getX() + x, getY() + y, *getSymbol(), color);
  }
  virtual void print(int x, int y, std::string text){
    ansiConsole.printText(getX() + x, getY() + y, text, Colors::WHITE);
  }

public:
  explicit ColoredShape(Colors color = Colors::WHITE, Position position = Position(0, 0), std::string symbol = "#")
    : Shape(position, symbol), color(color) {}

  virtual void draw() = 0;

  virtual double area() = 0;

  virtual ~ColoredShape() = default;
};


class Point : public ColoredShape {
public:
  explicit Point(Colors color, int x = 0, int y = 0)
    : ColoredShape(color, Position(x, y), "*") {}

  void draw() override {
    print(0, 0, "*");
  }

  double area() override {
    return 0.0;
  }
};

class Circle : public ColoredShape {
protected:
  int radius;
public:
  explicit Circle(Colors color, int x = 0, int y = 0, int radius = 0)
    : ColoredShape(color, Position(x, y)), radius(radius) {}

  void draw() override {
    /* see https://de.wikibooks.org/wiki/Formelsammlung_Mathematik:_Geometrie
    * Höhensatz des Euklid
    * */
    int x_start = getX() - radius / 2;
    int x_stop = getX() + radius / 2;
    for (int i = x_start; i <= x_stop; i++) {
      double x_relative = double(i) - double(x_start);
      double h = sqrt(x_relative * (x_stop - x_start - x_relative));
      print(int(x_relative) - radius / 2, h);
      print(int(x_relative) - radius / 2, h);
    }
  }

  double area() override {
    return M_PI * radius * radius;
  }
};

class Rectangle : public ColoredShape {
protected:
  int height;
  int width;
public:
  explicit Rectangle(Colors color, int x = 0, int y = 0, int height = 0, int width = 0)
    : ColoredShape(color, Position(x, y)), height(height), width(width) {}

  void draw() override {

    // draw and bottom
    for (int i = 0; i <= width; i++) {
      print(i, 0);
      print(i, height);
    }

    // draw sides
    for (int i = 0; i <= height; i++) {
      print(0, i);
      print(width, i);
    }
  }

  double area() override {
    return width * height;
  }
};


class Sign : public Rectangle {
protected:
  std::string text;
public:
  explicit Sign(Colors color, std::string text, int x, int y, int height, int width)
    : Rectangle(color, x, y, height, width), text(text) {}

  void draw() override {
    Rectangle::draw();

    print(4, height/2, text);
  }
};

class Scene {
protected:
  std::vector<ColoredShape *> shapes;
public:
  void add(ColoredShape *shape) {
    shapes.push_back(shape);
  }

  void draw() {
    for (ColoredShape *shape : shapes) {
      shape->draw();
    }
  }

  ~Scene() {
    for (ColoredShape *shape : shapes) {
      delete shape;
    }
  }
};

int main(int argc, char **argv) {
  ansiConsole.clearScreen();

  Scene *schneeMann = new Scene();

  schneeMann->add(new Circle(Colors::GREEN, 20, 22, 10));
  schneeMann->add(new Circle(Colors::GREEN, 20, 15, 6));
  schneeMann->add(new Circle(Colors::GREEN, 20, 10, 4));
  schneeMann->add(new Sign(Colors::GREEN, "Test", 32, 23, 4, 12));
  schneeMann->add(new Point(Colors::GREEN, 10, 10));
  schneeMann->add(new Point(Colors::GREEN, 40, 10));

  schneeMann->draw();

  std::cin.ignore();

  delete schneeMann;
  return 0;
}
