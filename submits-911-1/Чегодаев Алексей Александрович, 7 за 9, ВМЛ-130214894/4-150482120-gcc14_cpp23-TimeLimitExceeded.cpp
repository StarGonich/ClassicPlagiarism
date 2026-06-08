#include <iostream>

using namespace std;

int main()
{
    long long n, k, m{10000000000000}, p{0}, p2, n2, nok;
    cin >> n >> k;
    for(long long i{n + 1}; i < n + k + 1; i++){
        p2 = i;
        n2 = n;
        while(p2 > 0 && n2 > 0){
            if(p2 > n2)
                p2 -= p2 / n2 * n2;
            else
                n2 -= n2 / p2 * p2;
        }
        p2 = max(p2, n2);
        nok = i * n / p2;
        if(nok < m){
            p = i;
            m = nok;
        }
    }
    cout << p ;
}