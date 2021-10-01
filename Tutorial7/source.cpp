#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//grade program
void generateRandomGrades(int);
void generateManualGrades();
void gradeProgram();

//prime number program
bool checkIfPrime(int);
void printPrimes();

void coinProgram();


int main()
{
    // generateRandomGrades(20);
    generateManualGrades();
    gradeProgram();
    printPrimes();
    coinProgram();
};



void generateRandomGrades(int num)
{
    std::fstream myFile("grades.txt");
    for(int i = 0; i < num; i++){
        myFile << std::rand() % 100 + 1 << '\n';
    }
    myFile << "-1";
    myFile.close();
}

void generateManualGrades()
{
    int input;
    std::fstream myFile("grades.txt");
    myFile.clear();

    std::cout << "Please input grades, when you are done, input -1!\n";
    while(1){
        std::cin >> input;

        if(input > 100 || input < 0){
            if(input == -1){
                myFile << "-1";
                break;
            } else {
                std::cout << input << " is not between 0 and 100\n";
            }
        } else {
            myFile << input << '\n';
        } //check if done
    }
    std::cout << "Calculating stuff!\n";
    myFile.close();
}



void gradeProgram()
{
    std::fstream myFile;
    std::string str;
    int lowest, highest, previous, current, sum, num;
    double average;

    myFile.open("grades.txt");
    myFile.seekg(0);

    std::getline(myFile, str);
    std::istringstream(str) >> current;
    highest = 1;
    lowest = 100;
    sum = 0;
    num = 0;

    while(current != -1){
        if(current >= highest){ highest = current;}
        if(current <= lowest){ lowest = current;}
        sum += current;
        num++;

        std::getline(myFile, str);
        std::istringstream(str) >> current;
    }

    average = sum/num;


    myFile.close();
    std::cout << "Lowest grade:  " << lowest << '\n';
    std::cout << "Highest grade: " << highest << '\n';
    std::cout << "Average grade: " << average << '\n';
};



void printPrimes()
{
    int number;
    std::cout << "Please enter a positive integer\n";
    std::cin >> number;
    while(number < 0){
        std::cout << "I said positive dummy head";
        std::cin >> number;
    }

    for(int i = 0; i < number; i++){
        if(checkIfPrime(i)){std::cout << i << '\n';}
    }
}

bool checkIfPrime(int num)
{
    bool isPrime = true;

    if(num == 0 || num == 1){
        return false;
    } else {
        for(int i = 2; i <= num/2; i++){
            if(num % i == 0){
                return false;
                break;
            }
        }
    }
    return true;
}



void coinProgram()
{
    int coins[5];
    int values[6] {200, 100, 25, 10, 5, 1};
    int num, val;
    double value;
    
    std::cout << "please input some amount of money\n";
    std::cin >> value;
    val = value*100;

    for(int i = 0; i <= 5; i++){
        num = val / values[i];
        coins[i] = num;
        std::cout << val << " num " << num << std::endl;
        val -= num*values[i];
    }

    std::cout << "Toonies : " << coins[0] << '\n';
    std::cout << "Loonies : " << coins[1] << '\n';
    std::cout << "Quarters: " << coins[2] << '\n';
    std::cout << "Dimes   : " << coins[3] << '\n';
    std::cout << "Nickels : " << coins[4] << '\n';
    std::cout << "Pennies : " << coins[5] << '\n';
}