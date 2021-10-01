#include <iostream>
#include <iomanip>
#include <sstream>

std::string displayMagicSquare(int[4][4]);
bool isValidSquare(int[4][4]);
int countInstances(int*, int, int);
bool isMagical(int[4][4]);
void flipArray(int[4][4]);
void swap(int&, int&);


int main()
{
    int arr[4][4];
    int input;

    std::cout << "Welcome to magic square program thing\n\n" 
    << "Please input the numbers one at at a time (press enter after each number) in order of top leftt of the square to the bottom right of the square\n";

    //get user input
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) {
            std::cin >> input;
            while(input < 1 || input > 16){
                std::cout << "\nPlease put a number from 1 and 16\n";
                std::cin >> input;
            }
            arr[i][j] = input;
        }
    }

    //show the magic square
    std::cout << "Your square looks like this:\n" << displayMagicSquare(arr) << '\n';
    
    //check for dupes/missing values
    if(!isValidSquare(arr)){
        std::cout << "The square is not valid because there are either duplicate or missing values";
        return 0;
    }

    //part a
    if(isMagical(arr))
        std::cout << "It is magical!\n";
    else
        std::cout << "Your square is not eligible for hogwarts :(\n";


    //part b
    flipArray(arr);
    std::cout << "We flipped your square so now it's like this:\n" << displayMagicSquare(arr);

    return 0;
}


std::string displayMagicSquare(int arr[4][4])
{
    std::stringstream streamobj;
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            streamobj << std::setw(6) << std::left;
            streamobj << std::to_string(arr[i][j]);
        }
        streamobj << "\n";
    }

    return streamobj.str();
}


bool isValidSquare(int arr[4][4])
{
    int a[16];
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            a[i*4 + j] = arr[i][j];

    
    for(int k = 1; k <= 16; k++){
        if(countInstances(a, 16, k) != 1)
            return false;
    }

    return true;
}

int countInstances(int *arr, int size, int val)
{
    if(size)
        return (arr[0] == val) + countInstances(arr+1, size - 1, val);
    else
        return 0;
}

bool isMagical(int arr[4][4])
{
    int sum1 = 0, sum2 = 0;
    int target = arr[0][0] + arr[0][1] + arr[0][2] + arr[0][3];

    for(int i = 0; i < 4; i++){
        //check cols
        if( (arr[i][0] + arr[i][1] + arr[i][2] + arr[i][3]) != target)
            return false;

        // check rows
        if( (arr[0][i] + arr[1][i] + arr[2][i] +  arr[3][i]) != target)
            return false;

        //sum the diagonals
        sum1 += arr[i][i];
        sum2 += arr[3-i][3-i];
    }

    if(sum1 != target)
        return false;

    if(sum2 != target)
        return false;

    return true;
}


void flipArray(int arr[4][4])
{
    for(int i = 0; i < 4; i++)
        for(int j = i; j < 4; j++)
            swap(arr[j][i], arr[i][j]);
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}