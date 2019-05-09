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
//    void (*drawPtr)();
    int64_t drawPtr;

    int getX() {
        return position.x;
    }

    int getY() {
        return position.y;
    }

    std::string *getSymbol() {
        return &symbol;
    }

    virtual void print(int x, int y) {
        ansiConsole.printText(position.x + x, position.y + y, symbol, Colors::WHITE);
    }

    virtual void print(int x, int y, std::string text) {
        ansiConsole.printText(position.x + x, position.y + y, text, Colors::WHITE);
    }

public:
    explicit Shape(Position position, std::string symbol) : position(position), symbol(symbol) {

    }

    void draw(){
        drawPtr();
    }

    virtual double area() = 0;

    void nonVirtual() {
        std::cout << "Shape::nonVirtual()" << std::endl;
    }

    double nonVirtualArea() {
        return area();
    }

    virtual ~Shape() = default;
};

class ColoredShape : public Shape {
private:
    Colors color;
protected:
    void print(int x, int y) override {
        ansiConsole.printText(getX() + x, getY() + y, *getSymbol(), color);
    }

    virtual void print(int x, int y, std::string text) {
        ansiConsole.printText(getX() + x, getY() + y, text, Colors::WHITE);
    }

public:
    explicit ColoredShape(Colors color = Colors::WHITE, Position position = Position(0, 0), std::string symbol = "#")
            : Shape(position, symbol), color(color) {}

    void draw(){
        Shape::draw();
    }

    virtual double area() = 0;

    virtual ~ColoredShape() = default;
};


class Point : public ColoredShape {
private:

public:
    void draw() {
        print(0, 0, "*");
    }
    explicit Point(Colors color, int x = 0, int y = 0)
            : ColoredShape(color, Position(x, y), "*") {
        drawPtr = (*void)draw;
    }


    double area() override {
        return 0.0;
    }
};

class Circle : public ColoredShape {
private:
    void _draw() {
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
protected:
    int radius;
public:
    explicit Circle(Colors color, int x = 0, int y = 0, int radius = 0)
            : ColoredShape(color, Position(x, y)), radius(radius) {
        void (Circle::*pFunction)() = &Circle::_draw;
        uintptr_t pointer = reinterpret_cast<uintptr_t>(pFunction);

        drawPtr = pFunction;
    }



    double area() override {
        return M_PI * radius * radius;
    }


    void nonVirtual() {
        std::cout << "Circle::nonVirtual()" << std::endl;
    }
};

class Rectangle : public ColoredShape {
protected:
    int height;
    int width;
public:
    explicit Rectangle(Colors color, int x = 0, int y = 0, int height = 0, int width = 0)
            : ColoredShape(color, Position(x, y)), height(height), width(width) {}

    void draw() {

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


    void nonVirtual() {
        std::cout << "Rectangle::nonVirtual()" << std::endl;
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

        print(4, height / 2, text);
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

void invokeVirtually(Shape *theShape) {
//    if (typeid(*theShape) == typeid(Circle)) {
//        static_cast<Circle *>(theShape)->nonVirtual();
//    } else if (typeid(*theShape) == typeid(Rectangle)) {
//        static_cast<Rectangle *>(theShape)->nonVirtual();
//    }

    Rectangle* rect = dynamic_cast<Rectangle *>(theShape);
    if (rect != nullptr) {
        rect->nonVirtual();
        return;
    }
    Circle* circle = dynamic_cast<Circle *>(theShape);
    if (circle != nullptr) {
        circle->nonVirtual();
    }
}

int main(int argc, char **argv) {
    Shape *shape = new Sign(Colors::WHITE, "Text", 0, 0, 2, 2);

    // 1
    invokeVirtually(shape);

    // 2
    std::cout << shape->nonVirtualArea() << std::endl;

    // 3


    //4


    delete shape;
//    ansiConsole.clearScreen();
//
//    Scene *schneeMann = new Scene();
//
//    schneeMann->add(new Circle(Colors::GREEN, 20, 22, 10));
//    schneeMann->add(new Circle(Colors::GREEN, 20, 15, 6));
//    schneeMann->add(new Circle(Colors::GREEN, 20, 10, 4));
//    schneeMann->add(new Sign(Colors::GREEN, "Test", 32, 23, 4, 12));
//    schneeMann->add(new Point(Colors::GREEN, 10, 10));
//    schneeMann->add(new Point(Colors::GREEN, 40, 10));
//
//    schneeMann->draw();
//
//    std::cin.ignore();
//
//    delete schneeMann;
    return 0;
}
