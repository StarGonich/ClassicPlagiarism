#include <iostream>

int main()
{
    int counter = 0;
    int n;
    std::cin >> n;
    int i = 4;
    int j = 5;
    int z = 6;
    while (i <= n)
    {
        if ((i % 20 != 0) && (i % 12 != 0))
        {
            counter++;
        }
        if ((j <= n) && (j % 20 != 0) && (j % 30 != 0))
        {
            counter++;
        }
        if ((z <= n) && (z % 12 != 0) && (z % 30 != 0))
        {
            counter++;
        }
        i+=4; 
        j+=5; 
        z+=6;

    }
   
    std::cout << counter;
}
