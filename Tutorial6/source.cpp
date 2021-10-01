#include <iostream>
#include <math.h>

void coffeeQuestion();
void stepQuestion();

int main()
{
    double x;
    std::cout << "Do the thing \n";
    std::cin >> x;

    if(x <= 0){
        std::cout << pow(2, -3*x);
    } else {
        std::cout << log(x) + 10;
    }


}

void coffeeQuestion(){
    std::string input;
    double price;

    std::cout << "Please enter size of coffee that you want to purchase\n";
    std::cin >> input;
    while(input != "Small" && input != "Medium" && input != "Large")
    {
        std::cout << "Please enter a valid size. We offer Small, Medium and Large\n";
        std::cin >> input;
    }

    if(input == "Small"){
       price = 3.99;
    } else if(input == "Medium") {
        price = 4.99;
    } else if(input == "Large"){
        price = 5.99;
    }

    std::cout << "The cost of your drink is: " << price << '\n';

}