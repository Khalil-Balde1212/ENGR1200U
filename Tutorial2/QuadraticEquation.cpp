#include <iostream>
#include <math.h>

int main()
{
    double a, b, c;
    std::cout << "Quadratic equation root wizard" << std::endl << "--------------------------------------------------------" << std::endl;
    std::cout << "This program will assume quadratic equations in standard form (Ax^2 + Bx + C)" << std::endl;
    std::cout << "What is the value of A?" << std::endl;
    std::cin >> a;
    std::cout << "What is the value of B?" << std::endl;
    std::cin >> b;
    std::cout << "What is the value of C?" << std::endl;
    std::cin >> c;
    std::cout << std::endl << std::endl;

    std::cout << "1st root: " << (-b + sqrt(b*b - 4 * a * c))/ (2 * a) << std::endl;
    std::cout << "2nd root: " << (-b - sqrt(b*b - 4 * a * c))/ (2 * a) << std::endl;

    return 0;
};