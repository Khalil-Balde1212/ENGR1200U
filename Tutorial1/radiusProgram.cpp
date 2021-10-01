#include <iostream>
#include <math.h>

#define PI 3.14159265358979

int main()
{
    double radius;
    //this is a comment
    std::cout << "Welcome to circle hero!\n A program designed to help you calculate the area of a circle if you know the radius. \n\nPlease type in the radius of your circle\n";
    std::cin >> radius;
    std::cout << "The area of your circle is: " << PI * pow(radius, 2);

    
    return 0;
}
