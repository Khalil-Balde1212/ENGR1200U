#include <iostream>

int main()
{
    int m1 = 100, m2 = 50;
    double g = 9.81;
    //this is a comment
    std::cout << "Given that we know that mass 1 = 100, mass 2 = 50, and acceleration due to gravity is = 9.8m/s we know that:\n the tension in the rope is: ";
    std::cout << (2 * m1 * m2)/(m1 + m2) * g;
    return 0;
}
