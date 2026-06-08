
#include <vector>
#include <string>
#include <iostream>


using namespace std;


int main()
{
    vector<int> array;
    int n, count = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        array.push_back(0);
    }
    for (int i = 1; i <= n; i++) {
        if (i % 4 == 0) { array[i-1] = array[i-1] + 1; }
        if (i % 5 == 0) { array[i-1] = array[i-1] + 1; }
        if (i % 6 == 0) { array[i-1] = array[i-1] + 1; }
    }
    for (int i = 1; i <= n; i++) {
        if (array[i-1] == 1) { count++; }
    }

    cout << count;


    return 0;
}


