#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

void caseProgram();
void moneyProgram();
std::string numsToString(int, int, int);

int main(){
    caseProgram();
    moneyProgram();
}

void caseProgram(){
    std::string message;
    std::cout << "enter a message to be converted into all lower case\n";
    std::getline(std::cin, message);

    for(char &c: message){
        if(c >= 'A' && c <= 'Z'){
            c += 32; 
        }
    }

    std::cout << message;
}

void moneyProgram()
{
    double money;
    int values[8];// {hundred thousand, ten thousand, thousand, hundreds, tens, ones, tenths, hundreths}
    
    std::cout << "How much is the money?\n";
    std::cin >> money;

    while (money < 0 || money >= 1000000){
        std::cout << "It's impossible that you have that much money, please put a number between 0.00 and 999999.99";
        std::cin >> money;
    }

    std::cout << std::setprecision(2) << std::fixed;

    money *= 100;
    //parse digit at decimal places
    for(int i = 0; i <= 7; i++){
        values[i] = (int)money / (int)pow(10, 7 - i);
        // std::cout << money << " ";
        // std::cout <<  " " << i << values[i] << '\n';
        money -= values[i]*pow(10, 7 - i);
    }

    if((values[0] != 0) || (values[1] != 0) || (values[2] != 0))
        std::cout << numsToString(values[0], values[1], values[2]) << "thousand "; //thousands

    if((values[3] != 0) || (values[4] != 0) || (values[5] != 0))
        std::cout << numsToString(values[3], values[4], values[5]);//dollars

    std::cout << "dollars ";
    if((values[6] != 0) || (values[7] != 0))
        std::cout << "and " << numsToString(0, values[6], values[7]) << "cents"; //cents
}

std::string numsToString(int hundred, int ten, int one){
    std::string ones[] {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::string tens[] {"Easter Egg", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    std::string special[] {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    std::string output {""};
    
    //check if hundreds exist
    if(hundred != 0){
        output += ones[hundred] + " hundred ";
    }

    if(ten != 0){
        if(ten == 1){
            output += special[one] + ' ';
        } else {
            output += tens[ten - 1] + ' ';
        }
    }

    if(one != 0 && ten != 1){
        output += ones[one] + ' ';
    }

    return output;
}