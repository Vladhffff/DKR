#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <iostream>
#include <vector>
#include <algorithm>

class Quadrilateral {
protected:
    double sideA;
    double sideB;
    double sideC;
    double sideD;

public:
    Quadrilateral(double a, double b, double c, double d);
    void setSides(double a, double b, double c, double d);
    double getSideA() const;
    double getSideB() const;
    double getSideC() const;
    double getSideD() const;
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual std::string toString() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Quadrilateral& quadrilateral);
};

class Square : public Quadrilateral {
public:
    Square(double side);
    double getArea() const override;
    double getPerimeter() const override;
    std::string toString() const override;
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(double length, double width);
    double getArea() const override;
    double getPerimeter() const override;
    std::string toString() const override;
};

class Rhombus : public Quadrilateral {
public:
    Rhombus(double side, double diagonal);
    double getArea() const override;
    double getPerimeter() const override;
    std::string toString() const override;
};

#endif  // QUADRILATERAL_H