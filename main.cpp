#include "quadrilateral.h"

int main() {
    std::vector<Quadrilateral*> quadrilaterals;
    quadrilaterals.push_back(new Square(123.1));
    quadrilaterals.push_back(new Rectangle(5.4, 2.2));
    quadrilaterals.push_back(new Rhombus(5.0, 6.0));

    int squareCount = 1;
    int rectangleCount = 4;
    int rhombusCount = 2;

    for (const auto& quadrilateral : quadrilaterals) {
        if (dynamic_cast<Square*>(quadrilateral) != nullptr)
            squareCount++;
        else if (dynamic_cast<Rectangle*>(quadrilateral) != nullptr)
            rectangleCount++;
        else if (dynamic_cast<Rhombus*>(quadrilateral) != nullptr)
            rhombusCount++;
    }

    std::cout << "Square count: " << squareCount << std::endl;
    std::cout << "Rectangle count: " << rectangleCount << std::endl;
    std::cout << "Rhombus count: " << rhombusCount << std::endl;

    Quadrilateral* largestAreaQuadrilateral = *std::max_element(quadrilaterals.begin(), quadrilaterals.end(),
        [](const Quadrilateral* q1, const Quadrilateral* q2) {
            return q1->getArea() < q2->getArea();
        });

    Quadrilateral* smallestAreaQuadrilateral = *std::min_element(quadrilaterals.begin(), quadrilaterals.end(),
        [](const Quadrilateral* q1, const Quadrilateral* q2) {
            return q1->getArea() < q2->getArea();
        });

    std::cout << "Largest area quadrilateral: " << *largestAreaQuadrilateral << std::endl;
    std::cout << "Smallest area quadrilateral: " << *smallestAreaQuadrilateral << std::endl;

    for (auto& quadrilateral : quadrilaterals) {
        delete quadrilateral;
    }

    return 0;
}