#include <iostream>
using namespace std;
main()
{
    double arrayD[4][4] = {
        {1.1, 2.1, 3.1, 4.1},
        {1.2, 2.2, 3.2, 4.2},
        {1.3, 2.3, 3.3, 4.3},
        {1.4, 2.4, 3.4, 4.4}};
        std::cout<< sizeof(arrayD[1])<<"\n";
    for (int row = 0; row < 4; row++)

    {

        for (int col = 0; col < 4; col++)
        {

            cout << arrayD[row][col] << " ";
        }

        cout << endl;
    }
}
