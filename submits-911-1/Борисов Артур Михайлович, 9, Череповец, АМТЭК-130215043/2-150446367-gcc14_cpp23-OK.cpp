#include <iostream>
#include <vector>
using namespace std;
vector <int> func(int n){
    if (n == 3) {
        vector <int> v(3, 0);
        v[0] = 1;
        v[1] = 2;
        v[2] = 3;
        return v;
    }
    else {
        vector <int> v1;
        v1 = func(n - 1);
        int a = 0;
        for (int c : v1) {
            a += c;
        }
        v1.push_back(a);
        return v1;
    }
}
int main()
{
    int n, ans = 0;
    cin >> n;
    vector <int> v(n, 0);
    if (n == 1) {
        v[0] = 1;
    }
    else if (n != 2){
        v = func(n);
    }
    for (int c : v) {
        ans += c;
    }
    if (n == 2) {
        ans = 2000000000;
    }
    if (ans > 1000000000) {
        cout << -1;
    }
    else {
        cout << ans << '\n';
        for (int c : v) {
            cout << c << " ";
        }
    }
}
