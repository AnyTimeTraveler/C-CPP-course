#include <math.h>
#include <utility>
#include <iostream>
#include <cmath>
#include <vector>
#include "AnsiConsole.h"

struct Position {
    int x;
    int y;

    explicit Position(int x_ = 0, int y_ = 0) {
        x = x_;
        y = y_;
    }
};

class Shape {
protected:
    Colors _color;
    std::string _symbol;
    Position _position;
public:
    explicit Shape(Colors color = Colors::WHITE, Position position = Position(0, 0), std::string symbol = "#") {
        _color = color;
        _symbol = std::move(symbol);
        _position = position;
    }

    virtual void draw() {};

    virtual double area() = 0;

    virtual ~Shape() = default;
};


class Point : public Shape {
public:
    explicit Point(Colors color, int x = 0, int y = 0) : Shape(color, Position(x, y)) {}

    void draw() override {
        ansiConsole.printText(_position.x, _position.y, "*", _color);
    }

    double area() override {
        return 0.0;
    }
};

class Circle : public Shape {
protected:
    int _radius;
public:
    explicit Circle(Colors color, int x = 0, int y = 0, int radius = 0) : Shape(color, Position(x, y)) {
        _radius = radius;
    }

    void draw() override {
        /* see https://de.wikibooks.org/wiki/Formelsammlung_Mathematik:_Geometrie
        * Höhensatz des Euklid
        * */
        int x_start = _position.x - _radius / 2;
        int x_stop = _position.x + _radius / 2;
        for (int i = x_start; i <= x_stop; i++) {
            double x_relative = double(i) - double(x_start);
            double h = sqrt(x_relative * (x_stop - x_start - x_relative));
            ansiConsole.printText(_position.x + int(x_relative) - _radius / 2,
                                  _position.y + h, _symbol,
                                  _color);
            ansiConsole.printText(_position.x + int(x_relative) - _radius / 2,
                                  _position.y - h, _symbol,
                                  _color);
        }
    }

    double area() override {
        return M_PI * M_PI * _radius;
    }
};

class Rectangle : public Shape {
protected:
    int _width;
    int _height;
public:
    explicit Rectangle(Colors color, int x = 0, int y = 0, int width = 0, int height = 0) : Shape(color,
                                                                                                  Position(x, y)) {
        _width = width;
        _height = height;
    }

    void draw() override {
        int x_start = _position.x;
        int x_stop = _position.x + _height;

        int y_start = _position.y;
        int y_stop = _position.y + _width;

        // draw and bottom
        for (int i = x_start; i <= x_stop; i++) {
            ansiConsole.printText(i, y_start, _symbol, _color);
            ansiConsole.printText(i, y_stop, _symbol, _color);
        }

        // draw sides
        for (int i = y_start; i <= y_stop; i++) {
            ansiConsole.printText(x_start, i, _symbol, _color);
            ansiConsole.printText(x_stop, i, _symbol, _color);
        }
    }

    double area() override {
        return _height * _width;
    }
};

class Scene {
protected:
    std::vector<Shape *> _shapes;
public:
    void add(Shape *shape) {
        _shapes.push_back(shape);
    }

    void draw() {
        for (Shape *shape : _shapes) {
            shape->draw();
        }
    }

    ~Scene() {
        for (Shape *shape : _shapes) {
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
