#include <iostream>
using namespace std;
int nok(int a, int b)
{
    int a1, b1;
    a1 = a;
    b1 = b;
    while(a1 != b1)
    {
        if (a1 > b1)
        {
            a1 -= b1;
        }
        else
        {
            b1 -= a1;
        }
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