#include <iostream>
#include <math.h>

int main()
{
    int counter = 0;
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if ((i % 4 == 0) xor (i % 5 == 0) xor (i % 6 == 0))
        {
            counter++;
        }
    }
    std::cout << counter;
}
