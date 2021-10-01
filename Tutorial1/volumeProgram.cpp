#include <iostream>
#include <math.h>

#define PI 3.14159265358979

int main()
{
    double radius;
    //this is a comment
    std::cout << "Welcome to sphere hero!\n A program designed to help you calculate the area of a sphere if you know the radius.\n\n Please enter the radius of the sphere\n";
    std::cin >> radius;
    std::cout << "\nThe volume of the sphere is: " << 4 * PI * pow(radius, 3.0) / 3;
    return 0;
}
