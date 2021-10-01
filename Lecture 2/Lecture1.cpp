#include <iostream>
#include <math.h>

int main()
{
    double x1{ 5 }, y1{ 20 }, x2{ 10 }, y2{ 30 };
    double side1, side2, distance;
    side1 = x2 - x1;
    side2 = y2 - y1;

    distance = sqrt(side1*side1 + side2*side2);

    std::cout << "Your distance is: " << distance << std::endl;
    return 0;
}