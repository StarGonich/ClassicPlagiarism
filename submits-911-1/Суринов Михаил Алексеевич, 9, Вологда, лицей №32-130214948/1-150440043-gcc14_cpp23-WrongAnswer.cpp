#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long x = x1, y = y1;
    long long s = 0;
    if (x == x2 && y == y2){
        if (x == y){
            s++;
        }
        else if (x / 10 == y % 10 && x %10 == y /10){
            s++;
        }
        else if (x / 10 == (x % 10 - 1) && x % 10 == (y / 10 - 1) && y / 10 == (y % 10 - 1)){
            s ++;
        }
    }
    while (x != x2 || y != y2){
        if (x == y){
            s++;
        }
        else if (x / 10 == y % 10 && x %10 == y /10){
            s++;
        }
        else if (x / 10 == (x % 10 - 1) && x % 10 == (y / 10 - 1) && y / 10 == (y % 10 - 1)){
            s ++;
        }
        if (x == 23 && y == 59){
            x = 0;
            y = 0;
        }
        else if (y == 59){
            x ++;
            y = 0;
        }
        else {
            y++;
        }
    }
    cout << s;
    return 0;
}
