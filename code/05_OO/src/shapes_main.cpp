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
protected:
    Colors color;
    std::string symbol;
    Position position;
public:
    explicit Shape(Colors color = Colors::WHITE, Position position = Position(0, 0), std::string symbol = "#")
            : color(color), symbol(symbol), position(position) {}

    virtual void draw() {};

    virtual double area() = 0;

    virtual ~Shape() = default;
};


class Point : public Shape {
public:
    explicit Point(Colors color, int x = 0, int y = 0)
            : Shape(color, Position(x, y)) {}

    void draw() override {
        ansiConsole.printText(position.x, position.y, "*", color);
    }

    double area() override {
        return 0.0;
    }
};

class Circle : public Shape {
protected:
    int radius;
public:
    explicit Circle(Colors color, int x = 0, int y = 0, int radius = 0)
            : Shape(color, Position(x, y)), radius(radius) {}

    void draw() override {
        /* see https://de.wikibooks.org/wiki/Formelsammlung_Mathematik:_Geometrie
        * Höhensatz des Euklid
        * */
        int x_start = position.x - radius / 2;
        int x_stop = position.x + radius / 2;
        for (int i = x_start; i <= x_stop; i++) {
            double x_relative = double(i) - double(x_start);
            double h = sqrt(x_relative * (x_stop - x_start - x_relative));
            ansiConsole.printText(position.x + int(x_relative) - radius / 2,
                                  position.y + h, symbol,
                                  color);
            ansiConsole.printText(position.x + int(x_relative) - radius / 2,
                                  position.y - h, symbol,
                                  color);
        }
    }

    double area() override {
        return M_PI * M_PI * radius;
    }
};

class Rectangle : public Shape {
protected:
    int width;
    int height;
public:
    explicit Rectangle(Colors color, int x = 0, int y = 0, int width = 0, int height = 0)
            : Shape(color, Position(x, y)), width(width), height(height) {}

    void draw() override {
        int x_start = position.x;
        int x_stop = position.x + height;

        int y_start = position.y;
        int y_stop = position.y + width;

        // draw and bottom
        for (int i = x_start; i <= x_stop; i++) {
            ansiConsole.printText(i, y_start, symbol, color);
            ansiConsole.printText(i, y_stop, symbol, color);
        }

        // draw sides
        for (int i = y_start; i <= y_stop; i++) {
            ansiConsole.printText(x_start, i, symbol, color);
            ansiConsole.printText(x_stop, i, symbol, color);
        }
    }

    double area() override {
        return height * width;
    }
};

class Scene {
protected:
    std::vector<Shape *> shapes;
public:
    void add(Shape *shape) {
        shapes.push_back(shape);
    }

    void draw() {
        for (Shape *shape : shapes) {
            shape->draw();
        }
    }

    ~Scene() {
        for (Shape *shape : shapes) {
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
    schneeMann->add(new Rectangle(Colors::GREEN, 32, 23, 4, 4));
    schneeMann->add(new Point(Colors::GREEN, 10, 10));
    schneeMann->add(new Point(Colors::GREEN, 40, 10));

    schneeMann->draw();

    std::cin.ignore();

    delete schneeMann;
    return 0;
}
