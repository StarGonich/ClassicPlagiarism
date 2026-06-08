
#include <vector>
#include <string>
#include <iostream>


using namespace std;


int main()
{
    int n, count = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if ((i % 4 == 0) && (i % 5 != 0) && (i % 6 != 0)) { count++; }
        if ((i % 4 != 0) && (i % 5 == 0) && (i % 6 != 0)) { count++; }
        if ((i % 4 != 0) && (i % 5 != 0) && (i % 6 == 0)) { count++; }
    }

    cout << count;


    return 0;
}


