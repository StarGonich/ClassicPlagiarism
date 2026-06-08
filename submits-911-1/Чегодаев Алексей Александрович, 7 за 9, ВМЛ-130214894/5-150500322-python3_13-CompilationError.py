#include <iostream>
using namespace std;

int main()
{
    long long k, n, m, s{0}, a;
    cin >> k >> n >> m;
    map <vector, vector> mp;
    for(long long i{0}; i < k; i++){
        for(long long j{1}; i < n * m; j ++){
            cin >> a;
            s += a;
        }
    if(s == 0)
        cout << 2 << ' ' << 1;
    else
        cout << 1 << '  << 2';
    }
}
