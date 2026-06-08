#include <iostream>

using namespace std;

int main()
{
    long long n, kol = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        if (((i % 4 == 0) && (i % 5 != 0) && (i % 6 != 0)) || ((i % 4 != 0) && (i % 5 == 0) && (i % 6 != 0)) || ((i % 4 != 0) && (i % 5 != 0) && (i % 6 == 0)))
            kol += 1;
    }
    cout << kol;
}
