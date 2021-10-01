#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

int* parseGrades(std::string);
int checkPassing(int*);

/***File format must be as follows***
1,2,3,4,5,
6,7,8,9,10
11,12,13,14,15
16,17,18,19,20
*/
//Each row represents 1 reviewer and the column represents the respective criteria score (1,2,3,4,5)
//All values must be followed by a comma for the program to function correctly
//must have 5 values per row, and 4 rows total
//The file must be called scores.txt and in the same folder as the compiled code

int main()
{
    int passed = 0; //-1 failed, 0 borderline, 1 passed;
    int* scoreMatrix;
    scoreMatrix = parseGrades("scores.txt");

    //display score matrix
    std::cout << "The scoring matrix:";
    for(int i = 0; i < 4; i++){
        std::cout << '\n';
        for(int j = 0; j <= 4; j++)
            std::cout << std::left << std::setw(3) << scoreMatrix[i*5 + j] << " ";
    }
    
    std::cout << "\n\n";
    passed = checkPassing(scoreMatrix);

    switch(passed)
    {
        case -1:
            std::cout << "Rejected";
            break;
        case 0:
            std::cout << "Borderline";
            break;
        case 1:
            std::cout << "Accepted";
            break;
        
        default:
            std::cout << "Easter Egg!";
    }
    return 0;
}


int* parseGrades(std::string address)
{
    std::ifstream file;
    std::string entries, substr;
    int *output = new int(20);
    int count;

    file.open(address);

    if(!file)
    {
        std::cout << "Please create a file named scores.txt, and populate it by seperating all values by commas\n\nFor example:\n"
        << "3,5,1,9,7,\n5,7,5,1,6,\n2,9,7,6,4,\n8,7,9,10,10,\n";
        exit(0);
    }

    for(int i = 0; i < 4; i++) //This be for 1 review
    {
        std::getline(file, entries);
        count = 0;
        substr = "";
        for(auto j : entries)
        {
            if(j == ','){
                output[i*5 + count] = std::stoi(substr);
                count++;
                substr = "";
            }
            else
            {
                substr += j;
            }
        }
    }
    file.close();
    return output;
}

int checkPassing(int* scoreMatrix)
{
    double totalAverage = 0;
    //criteria 1. Fail if ANY overall scores< 5
    for(int i = 0; i < 4; i++)
    {
        double sum = 0; 
        for(int j = 0; j < 5; j++)
            sum += scoreMatrix[i*4 + j];

        totalAverage += sum;

        sum /= 5; //get average
        // std::cout << sum << '\n';
        if(sum < 5)
            return -1;
    }

    //criteria 2. That the overall average is >= 7, pass
    totalAverage /= 20;
    if(totalAverage >= 7)
        return 1;


    //second pass
    if(totalAverage < 7 && totalAverage >= 6)
        return 0;

    return -1;//in the case that the overal average is >5 but it meets no other criteria
}