#include <iostream>

using namespace std;

int main()
{
    long long n, kol = 0;
    cin >> n;
    for (int i = 4; i <= n; i += 4){
        if ((i % 5 != 0) && (i % 6 != 0))
            kol += 1;
    }
    for (int i = 5; i <= n; i += 5){
        if ((i % 4 != 0) && (i % 6 != 0))
            kol += 1;
    }
    for (int i = 6; i <= n; i += 6){
        if ((i % 5 != 0) && (i % 4 != 0))
            kol += 1;
    }
    cout << kol;
}
