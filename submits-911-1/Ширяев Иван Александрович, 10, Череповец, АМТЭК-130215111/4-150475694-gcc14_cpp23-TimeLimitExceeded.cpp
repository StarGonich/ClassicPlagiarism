#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k, i, a, b, c, o, r, m;
    cin >> n >> k;
    m = (n + k) * (n + k);
    r = 0;
    if (n == k) cout << n * 2;
    else{
        for (i = n + 1; i < n + k + 1; i++){
            a = i;
            b = n;
            while (a % b != 0){
                c = b;
                b = a % c;
                a = c;
            }
            o = i * n / b;
            if (o < m){
                r = i;
                m = o;
            }
        }
        cout << r;
    }

    return 0;
}

