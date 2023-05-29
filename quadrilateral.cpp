#include "quadrilateral.h"

#include <sstream>

Quadrilateral::Quadrilateral(double a, double b, double c, double d)
    : sideA(a), sideB(b), sideC(c), sideD(d) {}

void Quadrilateral::setSides(double a, double b, double c, double d) {
    sideA = a;
    sideB = b;
    sideC = c;
    sideD = d;
}

double Quadrilateral::getSideA() const {
    return sideA;
}

double Quadrilateral::getSideB() const {
    return sideB;
}

double Quadrilateral::getSideC() const {
    return sideC;
}

double Quadrilateral::getSideD() const {
    return sideD;
}

std::ostream& operator<<(std::ostream& os, const Quadrilateral& quadrilateral) {
    os << quadrilateral.toString();
    return os;
}

Square::Square(double side) : Quadrilateral(side, side, side, side) {}

double Square::getArea() const {
    return sideA * sideA;
}

double Square::getPerimeter() const {
    return sideA * 4;
}

std::string Square::toString() const {
    std::stringstream ss;
    ss << "Square: sides = " << sideA;
    return ss.str();
}

Rectangle::Rectangle(double length, double width) : Quadrilateral(length, width, length, width) {}

double Rectangle::getArea() const {
    return sideA * sideB;
}

double Rectangle::getPerimeter() const {
    return 2 * (sideA + sideB);
}

std::string Rectangle::toString() const {
    std::stringstream ss;
    ss << "Rectangle: sides = " << sideA << ", " << sideB;
    return ss.str();
}

Rhombus::Rhombus(double side, double diagonal) : Quadrilateral(side, side, side, side) {
    sideC = diagonal;
    sideD = diagonal;
}

double Rhombus::getArea() const {
    return (sideA * sideC) / 2;
}

double Rhombus::getPerimeter() const {
    return sideA * 4;
}

std::string Rhombus::toString() const {
    std::stringstream ss;
    ss << "Rhombus: sides = " << sideA << ", diagonals = " << sideC;
    return ss.str();
}