#include <iostream>
using namespace std;
int nok(int a, int b)
{
    int a1, b1;
    a1 = a;
    b1 = b;
    while((a1 != b1) and (a1 != 0) and (b1 != 0))
    {
        if (a1 > b1)
        {
            if (a1 / b1 > 1)
            {
                if (a1 - b1 * (a1 / b1) == 0)
                {
                    a1 = b1;
                    break;
                }
            a1 -= b1 * (a1 / b1);
            }
            else{
                a1 -= b1;
            }
        }
        else
        {
            if (b1 / a1 > 1)
            {
                if (b1 - a1 * (b1 / a1) == 0)
                {
                   b1 = a1;
                   break;
                }
            b1 -= a1 * (b1 / a1);
            }
            else{
                b1 -= a1;
            }
        }
    }
    if ((a1 == 0) or (b1 == 0))
    {
        a1 = 1;
        b1 = 1;
    }
    int nok = a * b / a1;
    return nok;
}
int main()
{
    int n, k, mini, minii;
    cin >> n >> k;
    mini = 9999999;
    for (int i = n + 1; i <= n + k; i++)
    {
        if (nok(i, n) < mini)
        {
            mini = nok(i, n);
            minii = i;
        }
    }
    cout << minii;
}
