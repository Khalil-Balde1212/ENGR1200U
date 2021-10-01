#include <iostream>
#include <iomanip>
#include <fstream>

void weatherProgram();
std::string display(double*, int);
double sum(double*, int);
double average(double*, int);
double min(double*, int);
double max(double*, int);
void swap(double*, double*); //this is for bubble sort
void bsort(double*, int);
void reverse(double*, int);
int bsearch(double*, int, int, double);

void listProgram();
std::string display(int*, int);
void swap(int*, int*); //this is for bubble sort
void bsort(int*, int);
void clearArr(int*, int);
void extractOdd(int*, int*, int, int, int*);
void extractEven(int*, int*, int, int, int*);
void merge(int*, int*, int, int, int*);
void mergeSort(int*, int*, int, int, int*);


int main()
{
    weatherProgram();
    listProgram();
    return 0;
}

void weatherProgram()
{
    double temperatures[22];
    double x;
    std::string text;
    std::ifstream myfile("temprature.txt");

    for(int i = 0; getline(myfile, text); i++){
        temperatures[i] = atof(text.c_str());
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "This is the current array" << display(temperatures, 22)<< "\n\n";;
    std::cout << "Sum of temps: " << sum(temperatures, 22) << '\n';
    std::cout << "Average temp: " << average(temperatures, 22) << '\n';
    std::cout << "Min temp    : " << min(temperatures, 22) << '\n';
    std::cout << "Max temp    : " << max(temperatures, 22) << "\n\n";
    bsort(temperatures, 22);
    std::cout << "Here is the sorted array: " << display(temperatures, 22) << "\n\n";
    reverse(temperatures, 22);
    std::cout << "Here is the reverse array: " << display(temperatures, 22) << "\n\n";
    std::cout << "Please input a number from the list\n";
    std::cin >> x;
    if(bsearch(temperatures, 0, 22, x) == -1)
        std::cout << "That number isn't on the list \n";
    else
        std::cout << "That number has index of " << bsearch(temperatures, 0, 22, x);

}

std::string display(double* arr, int size)
{
    std::ostringstream streamobj;

    streamobj << '\n' << std::fixed << std::setprecision(1);
    for(int i = 0; i < size; i++)
        streamobj << arr[i] << ", ";

    return streamobj.str();
}

double sum(double* arr, int size)
{
    double output = 0;
    for(int i = 0; i < size; i++)
        output += arr[i];

    return output;
}

double average(double *arr, int size)
{
    return sum(arr, size)/size;
}

double min(double *arr, int size)
{
    if(size == 1)
        return arr[0];
    else
        return std::min(arr[0], min(arr + 1, size - 1));
}

double max(double *arr, int size)
{
    if(size == 1)
        return arr[0];
    else
        return std::max(arr[0], max(arr + 1, size - 1));
}

void swap(double *a, double *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bsort(double *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        for(int j = 0; j < size - i - 1; j++)
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j + 1]);
}

void reverse(double *arr, int size)
{
    if(size <= 1)
        return ;
    else{
        swap(&arr[0], &arr[size - 1]);
        reverse(&arr[1], size - 2);
    }
}

int bsearch(double *arr, int low, int high, double val)
{
    if(low > high) return -1;

    int mid = (low + high)/2;

    if(val == arr[mid]) 
        return mid;
    else if(val > arr[mid]) 
        return bsearch(arr, low, mid - 1, val);
    else 
        return bsearch(arr, mid + 1, high, val);
}






void listProgram()
{
    int sizea, sizeb;

    std::cout << "Please input the length of the first array\n";
    std::cin >> sizea;
    std::cout << "Please input the length of the second array\n";
    std::cin >> sizeb;

    int* list1 = new int[sizea];
    int* list2 = new int[sizeb];
    int* list3 = new int[sizea + sizeb];

    for(int i = 0; i < sizea; i++){
        list3[i] = -1;
        list1[i] = rand() % 100 + 1;
    }
    
    for(int j = 0; j < sizeb; j++){
        list3[sizea + j] = -1;
        list2[j] = rand() % 100 + 1;
    }

    std::cout << "List 1 consists of the following:" << display(list1, sizea) << "\n\n";
    std::cout << "List 2 consists of the following:" << display(list2, sizeb) << "\n\n";
    
    extractOdd(list1, list2, sizea, sizeb, list3);
    std::cout << "All the odd numbers are: " << display(list3, sizea+sizeb) << "\n\n";

    extractEven(list1, list2, sizea, sizeb, list3);
    std::cout << "All the even numbers are: " << display(list3, sizea+sizeb) << "\n\n";

    merge(list1, list2, sizea, sizeb, list3);
    std::cout << "Merged unsorted: " << display(list3, sizea+sizeb) << "\n\n";

    mergeSort(list1, list2, sizea, sizeb, list3);
    std::cout << "Merged sorted: " << display(list3, sizea+sizeb) << "\n\n";
}

std::string display(int* arr, int size)
{
    std::ostringstream streamobj;

    streamobj << '\n';
    for(int i = 0; i < size; i++)
        if(arr[i] == -1)
            break;
        else
            streamobj << arr[i] << ", ";

    return streamobj.str();
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bsort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        for(int j = 0; j < size - i - 1; j++)
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j + 1]);
}

void clearArr(int *arr, int size)
{
    for(int i = 0; i < size; i++)
        arr[i] = -1;
}

void extractOdd(int *arr1, int *arr2, int size1, int size2, int *arr3)
{
    int count = 0;
    clearArr(arr3, size1+size2);

    for(int i = 0; i < size1; i++)
        if(arr1[i] % 2 != 0){
            arr3[count] = arr1[i];
            count++;
        }

    for(int j = 0; j < size2; j++)
        if(arr2[j] % 2 != 0){
            arr3[count] = arr1[j];
            count++;
        } 
}

void extractEven(int *arr1, int *arr2, int size1, int size2, int *arr3)
{
    int count = 0;
    clearArr(arr3, size1 + size2);
    
    for(int i = 0; i < size1; i++)
        if(arr1[i] % 2 == 0){
            arr3[count] = arr1[i];
            count++;
        }

    for(int j = 0; j < size2; j++)
        if(arr2[j] % 2 == 0){
            arr3[count] = arr1[j];
            count++;
        } 
}

void merge(int *arr1, int *arr2, int size1, int size2, int *arr3)
{
    for(int i = 0; i < size1; i++)
        arr3[i] = arr1[i];

    for(int j = 0; j < size2; j++)
        arr3[size1 + j] = arr2[j];
}

void mergeSort(int *arr1, int *arr2, int size1, int size2, int *arr3)
{
    merge(arr1, arr2, size1, size2, arr3);
    bsort(arr3, size1+size2);
}