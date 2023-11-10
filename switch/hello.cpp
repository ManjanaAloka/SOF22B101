#include <iostream>
using namespace std;
main()
{
    char gender;
    cin >> gender;
    switch(gender)
    {
case 'F':
    cout<<" F is female";
    break;
case 'M':
    cout<<"M is male";
    break;
default:
    cout<<"Invalid sintax";
    }
}
