#include <iostream>
#include <string>
using namespace std;
int main()
{
    string mas[14]{ "1","1 2", "1 2 3", "1 2 3 4", "1 2 3 4 5", "1 2 3 4 5 6", "1 2 3 4 5 6 7"
        , "1 2 3 4 5 6 7 8", "1 2 3 4 5 6 7 8 9", "1 2 3 4 5 6 7 8 9 10", "1 2 3 4 5 6 7 8 9 10 11",
        "1 2 3 4 5 6 7 8 9 10 11 12", "1 2 3 4 5 6 7 8 9 10 11 12 13", "1 2 3 4 5 6 7 8 9 10 11 12 13 14",};
    int input;
    cin >> input;
    if (14 < input) {
        cout << -1;
    }
    else {
        int out = 1;
        for (int i = 2; i <= input; i++) {
            out *= i;
        }
        cout << out << "\n" << mas[input-1];
    }

}