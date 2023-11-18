#include <iostream>
using namespace std;

// x = අඩාරක
//  y = ලම්බ උස
int x;
int y;
void abc();
int main()
{
    cout << "adaraka padaya : ";
    cin >> x;

    cout << "lamba usa : ";
    cin >> y;
    abc();
    return 0;
}



void abc()
{
    float area = 0.5 * x * y;
    cout << "Triangale Area is : " << area;
}