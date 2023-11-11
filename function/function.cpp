#include <iostream>
using namespace std;

void myFunc();

int main()
{
    myFunc();
    return 0;
}

void myFunc()
{

    std::cout << "Enter Your Array Lenth : ";
    int len;
    string bd[len] = {"2002/07/05","2002/09/06"};
    cin >> len;
    string myArray[len] = {};
    int i = 1;
    string val;
    while (i <= len)
    {
        string val;
        std::cout << "Value " << i << " : ";
        cin >> val;
        myArray[i] = {val};
        i++;
    }

    std::cout <<"Array size is :"<< len << "\n";
    for (int i = 0; i < len; i++)
    {
        std::cout << myArray[i] <<" Your Birth Day is - "<<bd[i]<< "\n";
    }
}