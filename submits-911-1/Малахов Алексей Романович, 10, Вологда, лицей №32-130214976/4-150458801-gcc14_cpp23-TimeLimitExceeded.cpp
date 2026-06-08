#include <iostream>
#include <vector>

using namespace std;

int nod(int a, int b)
{
    while(b != 0)
    {
        swap(a, b);
        b = b % a;
    }
    return b;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int l = 2;
    int r = 10;
    int lnok = n * l / nod(n, l);
    while(l + 1 != r)
    {
        int m = (l + r) / 2;
        int nok = n * m / nod(n, m);
        if(lnok > nok)
        {
            l = m;
        }
        else if (lnok < nok)
        {
            r = m;
        }
        lnok = nok;
    }
    cout << l;
    return 0;
}
