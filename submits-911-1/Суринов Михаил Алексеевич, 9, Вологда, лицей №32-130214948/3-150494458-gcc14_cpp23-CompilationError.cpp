#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long t;
    cin >> t;
    vector <long long> a(1000000000);
    long long s = 0;
    for (long long i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        for (long long j = a; j <= b; j++){
            a[j] = 1;
        }
    }
    for (long long i = 0; i < 1000000000; i++){
        for (long long j = i; j < i + 3600; j++){
            s += a[j];
        }
        if (s > t){
            cout << i;
            return 0;
        }
        s = 0;
    }
    cout << -1;
    return 0;
}
