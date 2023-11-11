#include <iostream>
using namespace std;

void myFunc();

int main()
{
    myFunc();
    return 0;
}

void myFunc(){
    string myArray[] = {"ab","cd","asd"};
    int arraySize = sizeof(myArray);
    std::cout << arraySize/32;
    // for (size_t i = 0; i < count; i++)
    // {
    //     /* code */
    // }
    
}