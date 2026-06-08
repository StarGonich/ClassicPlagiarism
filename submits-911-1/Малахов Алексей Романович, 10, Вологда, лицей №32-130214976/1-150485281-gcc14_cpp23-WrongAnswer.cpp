#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    int ans = 0;
    int i = h1;
    int j = m1;
    while(i != h2 || j != m2)
    {
        if(j == 60)
        {
            j = 0;
            i++;
        }
        if(i == 24)
        {
            i = 0;
        }
        if(i == j)
        {
            ans++;
        }
        else if(i / 10 == j % 10 && i % 10 == j / 10)
        {
            ans++;
        }
        else if(j % 10 == j / 10 + 1 && j / 10 == i % 10 +1 && i % 10 == i / 10 + 1)
        {
            ans++;
        }
        j++;
    }
    if(h1 == h2 && m1 == m2)
    {
        if(i == j)
        {
            ans++;
        }
        else if(i / 10 == j % 10 && i % 10 == j / 10)
        {
            ans++;
        }
        else if(j % 10 == j / 10 + 1 && j / 10 == i % 10 +1 && i % 10 == i / 10 + 1)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}