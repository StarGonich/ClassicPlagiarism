#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n, k, s,ans;
    s = 0;
    k = 0;
    ans = -1;
    cin >> n;
    vector <int> p(n);
    vector <int> h(n);
    for (int i = 1; i < 1000; i++)
    {
        for (int j = 1; j < sqrt(i) + 1; j++)
        {
            if (i % j == 0)
            {
                p[k] = j;
                k++;
            }
        }
        for (int j = n + 1; j < n; j++)
        {
            s += p[j];
        }
    }
    if (s == 0)
    {
        cout << ans;
    }
}