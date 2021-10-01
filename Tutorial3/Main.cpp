#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

//prices for each thingy


int main()
{
    int n_coffee, n_pastry;
    double subtotal, hst;
    //price stuff
    const double P_COFFEE   = 4.99;
    const double P_PASTRY   = 1.99;
    const double HST        = 0.13;
    //label widths
    const auto LABEL_WIDTH  = 12;
    const auto QUANT_WIDTH  = 5;
    const auto DOLLAR_WIDTH = 4;
    const auto CENTS_WIDTH  = 2;

    std::cout << "Welcome to Jim Hortons! Where we only seem to serve Coffee and Dougnuts\nHow much Coffee would you like to purchase from us today?\n";
    std::cin >> n_coffee; //I would add error checking here but I am too lazy to, as well as probably out of the scope of this tutorial

    std::cout << "How many dougnuts would you like to purchase from us today?\n";
    std::cin >> n_pastry;

    //print receipt
    std::cout << "\n\nJim Hortons\nCustomer Receipt\n-------------------------\n"; //fancy first part
    //print quantity + price for items
    std::cout << std::setw(LABEL_WIDTH) << std::setfill(' ') << std::left << "Coffee"
        << std::setw(QUANT_WIDTH)  << std::left << 'x' + std::to_string(n_coffee)
        << std::setw(DOLLAR_WIDTH) << std::right << (int)(n_coffee * P_COFFEE) << '.' //this thing prints the dollars
        << std::setw(CENTS_WIDTH)  << std::left << std::setfill('0') << (int)(((n_coffee * P_COFFEE) - std::floor(n_coffee * P_COFFEE)) * 100)//this prints the cents
        << std::endl;

    //the rest are basically a copy-paste of the above section
    std::cout << std::setw(LABEL_WIDTH) << std::setfill(' ') << std::left << "Doughnuts"
        << std::setw(QUANT_WIDTH) << std::left << 'x' + std::to_string(n_pastry)
        << std::setw(DOLLAR_WIDTH) << std::right << (int)(n_pastry * P_PASTRY) << '.'
        << std::setw(CENTS_WIDTH) << std::left << std::setfill('0') << (int)(((n_pastry * P_PASTRY) - std::floor(n_pastry * P_PASTRY)) * 100)
        << std::endl << std::endl;
    
    subtotal = n_pastry*P_PASTRY + n_coffee*P_COFFEE;
    //print taxes
    std::cout << std::setw(LABEL_WIDTH) << std::setfill(' ') << std::left << "Subtotal"
        << std::setw(QUANT_WIDTH) << std::left << ""
        << std::setw(DOLLAR_WIDTH) << std::right << (int)subtotal << '.'
        << std::setw(CENTS_WIDTH) << std::left << std::setfill('0') << (int) ((subtotal - std::floor(subtotal))*100)
        << std::endl;

    hst = subtotal*HST;
    //calculate HST
    std::cout << std::setw(LABEL_WIDTH) << std::setfill(' ') << std::left << "HST"
        << std::setw(QUANT_WIDTH) << std::left << "%13"
        << std::setw(DOLLAR_WIDTH) << std::right << (int)hst << '.'
        << std::setw(CENTS_WIDTH) << std::left << std::setfill('0') << (int) ((hst - std::floor(hst))*100)
        << std::endl << std::endl;

    //total it up
    std::cout << std::setw(LABEL_WIDTH) << std::setfill(' ') << std::left << "Total"
        << std::setw(QUANT_WIDTH) << std::left << ""
        << std::setw(DOLLAR_WIDTH) << std::right << (int)(subtotal + hst) << '.'
        << std::setw(CENTS_WIDTH) << std::left << std::setfill('0') << (int) ((subtotal + hst - std::floor(subtotal + hst))*100)
        << std::endl << std::endl;

    return 0;
}