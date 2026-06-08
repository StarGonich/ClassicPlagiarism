#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, s;
    cin >> n;
    s = (n / 60) * 20;
    for (int i = 1; i <= n % 60; i++){
        if (((i % 4 == 0) & (i % 6 != 0) & (i % 5 != 0)) or ((i % 4 != 0) & (i % 6 == 0) & (i % 5 != 0)) or ((i % 4 != 0) & (i % 6 != 0) & (i % 5 == 0)))
            s++;
    }
    cout << s;
}
