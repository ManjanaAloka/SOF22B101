#include <iostream>
using namespace std;

int main()
{
    int myArray[5] = {2, 1, 5, 4, 3};
    int arraySize = sizeof(myArray);

    int x = 0;

    int oththe_count = 0;
    while ( x < arraySize)
    {
        if ((myArray[x]%2)==1)
        {
           oththe_count++; 
        }

        x++;
    }

    cout << "count is :" << oththe_count;

    return 0;
}
