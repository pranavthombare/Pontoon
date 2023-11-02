#include<vector>
#include<random>

#include "gnuplot-iostream.h"

using namespace std;

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int randum_nomber()
{
    int randomNumber = rand() % 100 + 1;
    return randomNumber;
}

int main()
{
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random number between 1 and 100

    // Plot the random number
    Gnuplot gp;
    gp << "plot '-' with lines title 'Random Number'\n";
    for (int i = 0; i < 1000; i++)
    {
        cout << "The random number is: " << randum_nomber() << endl;
        gp << randum_nomber() << endl;
    }
    gp << "e\n";
    return 0;
}