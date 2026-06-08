#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    --n;
    cout << n / 4 + n / 5 + n / 6 - n / 20 - n / 12 - n / 30 + n / 60;
    return 0;
}
