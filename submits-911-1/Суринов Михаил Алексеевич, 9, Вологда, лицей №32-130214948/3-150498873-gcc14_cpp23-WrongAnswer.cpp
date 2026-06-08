#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int t;
    cin >> t;
    vector <int> a(1000000);
    int s = 0;
    for (int i = 0; i < n; i++){
        int d, b;
        cin >> d >> b;
        for (int j = d; j <= b; j++){
            a[j] = 1;
        }
    }
    for (int i = 0; i < 1000000; i++){
        for (int j = i; j < i + 3600; j++){
            s += a[j];
        }
        if (s > t){
            cout << i + 1;
            return 0;
        }
        s = 0;
    }
    cout << -1;
    return 0;
}

