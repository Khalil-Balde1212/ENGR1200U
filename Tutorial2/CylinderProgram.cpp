#include <iostream>
#include <math.h>

const double PI { 3.141592 };

int main()
{
    double height, radius, surface;

    std::cout << "Cylinder Height Hero" << std::endl << "--------------------------------------------------------" << std::endl;
    std::cout << "This program will calculate the height of a cylinder based on the surface area, and the radius" << std::endl;
    std::cout << "What is the surface area of the cylinder?" << std::endl;
    std::cin >> surface;
    if (surface < 0)
    {
        std::cout << "This needs to be a positive number! please restart the program";
        return 0;
    }
    
    std::cout << "Whe is the radius of the cylinder? " << std::endl;
    std::cin >> radius;
    if (radius < 0)
    {
        std::cout << "This needs to be a positive number! please restart the program";
        return 0;
    }

    if((surface - (2 * PI * radius * radius)) / (2 * PI * radius) < 0)
    {
        std::cout << "That is actually impossible. The height becomes negative what the heck\n";
        return 0;
    }

    std::cout << "Height of the cylinder: " << (surface - (2 * PI * radius * radius)) / (2 * PI * radius) << std::endl << std::endl;
    
    return 0;
};