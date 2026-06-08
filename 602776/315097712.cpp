#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    cout << n / 4 + n / 5 + n / 6 - (n / 20)*2 - (n / 12)*2 - (n / 30)*2 + (n / 60)*3;
    return 0;
}
