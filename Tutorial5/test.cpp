#include <iostream>
#include <math.h>

int main()
{
    float s, i, d, c, h, b;
    std::cout << "This program calculates the maximum load on a symetrical wooden beam\n";

    //ask stuff for stress
    std::cout << "please input the stress on the beam (ilbs/in^2)\n";
    while(1){
        if(std::cin >> s){
            break;
        } else {
            std::cout << "Please put a valid input\n";
            std::cin.clear();
            while(std::cin.get() != '\n');
        }
    }

    //thingy thing for distance
    std::cout << "Please input distance that the load is placed on from the fixed end of the beam (inches)\n";
    while(1){
        if(std::cin >> d){
            break;
        } else {
            std::cout << "Please put a valid input\n";
            std::cin.clear();
            while(std::cin.get() != '\n');
        }
    }

    //questions about the cross section
    std::cout << "Please input the height of the beam (inches)\n";
    while(1){
        if(std::cin >> h){
            break;
        } else {
            std::cout << "Please put a valid input\n";
            std::cin.clear();
            while(std::cin.get() != '\n');
        }
    }

    std::cout << "please input the length of the base of the beam (inches)\n";
    while(1){
        if(std::cin >> b){
            break;
        } else {
            std::cout << "Please put a valid input\n";
            std::cin.clear();
            while(std::cin.get() != '\n');
        }
    }

    //calculate inertia
    i = b * pow(h, 3) / 12;

    //calculate c
    c = h/2;


    std::cout << "The maximum load on a " << d << " x " << h << " x " << b << " piece of wood is: " << (s*i)/(d*c);
    return 0;
}