#include <iostream>

using namespace std;
bool fun(int i, int j)
{
    if(i == 1 && j ==23)
    {
        return 1;
    }
    else if(i == 12 && j == 34)
    {
        return 1;
    }
    else if(i == 23 && j == 45)
    {
        return 1;
    }
    else if(i == j)
    {
        return 1;
    }
    else
    {
        int a2 = i%10;
        int a1 = i/10;
        int b2 = j%10;
        int b1 = j/10;
        if(a2 == b1 && a1 == b2)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int h1, h2, m1, m2;
    cin>> h1>>m1>>h2>>m2;
    int s = 0;
    int r = 0;
    if(h2 < h1 || m1> m2)
    {
        swap(h1, h2);
        swap(m1, m2);
        r++;
    }
    if(h2> h1)
    {
        for(int i = h1; i< h2; i++)
        {
            for(int j = m1; j<=59; j++)
            {
                if(fun(i, j))
                {
                    s++;
                }
            }
        }
        int i = h2;
        for(int j = 0; j<=m2; j++)
        {
            if(fun(i, j))
            {
                s++;
            }
        }

    }
    else if( h2 >= h1 && m2>= m1)
    {

        for(int i = h1; i<= h2; i++)
        {
            for(int j = m1; j<=m2; j++)
            {
                if(fun(i, j))
                {
                    s++;

                }
            }
        }

    }
    if( r > 0)
    {
        s = 40 - s;
        if(fun(h1, m1)){
            s++;
        }
        if(fun(h2, m2)){
            s++;
        }
    }
    cout<<s;
    return 0;
}
