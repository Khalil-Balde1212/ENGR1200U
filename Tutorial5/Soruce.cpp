#include <iostream>

void triangleProgram();
void sumProgram();
void loadProgram();

int main()
{
    triangleProgram();
    sumProgram();
    loadProgram();

    return 0;
}


void triangleProgram()
{
    double base, height;
    std::cout << "Flameo hotman welcome to triangle hero!\n This program is designed to help you calculate the area of a triangle given that you know the base and height of it\n\n";
    
    //check for the base
    std::cout << "Please enter the length of the base of the triangle:\n";
    //type checking I guess
    while(1){
        if(std::cin >> base){
            break;
        } else {
            std::cout << "Please put a valid input\n";
            std::cin.clear();
            while(std::cin.get() != '\n');
        }
    }

    //check for height
    std::cout << "Please enter the height of the triangle:\n";
    //type checking I guess
    while(1){
        if(std::cin >> height){
            break;
        } else {
            std::cout << "Please put a valid input\n";
            std::cin.clear();
            while(std::cin.get() != '\n');
        }
    }

    std::cout << "The area of your triangle is: " << std::scientific << base * height * 0.5;
}

void sumProgram()
{
    int a, difference, numInt;
    std::cout << "This is the thing that will sum up the numbers between 2 integers\n";
    
    //Input the first number
    std::cout << "Please input your first number\n";
    while(1){
        if(std::cin >> a){
            break;
        } else {
            std::cout << "Please put a valid input\n";
            std::cin.clear();
            while(std::cin.get() != '\n');
        }
    }

    //Input the second number
    std::cout << "Please input the number of integers you want to add\n";
    while(1){
        if(std::cin >> numInt){
            break;
        } else {
            std::cout << "Please put a valid input\n";
            std::cin.clear();
            while(std::cin.get() != '\n');
        }
    }

    //calculate the difference
    difference = 1; //xd


    std::cout << "I hate my life and the question makes no sense. So I have the equation version and a for loop version. I trust the for loop better\n";
    std::cout << "The sum of the numbers between " << a << " and " << a + numInt - 1 << " is:\n" << std::scientific << (int)((double)((numInt/2)*(2*a + (numInt - 1) * difference)));


    int test = 0;
    for (int i = a; i < a + numInt; i++){
        test += i;
    }

    std::cout << "\n\nFor loop:\n"<< test;
}

void loadProgram()
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
}