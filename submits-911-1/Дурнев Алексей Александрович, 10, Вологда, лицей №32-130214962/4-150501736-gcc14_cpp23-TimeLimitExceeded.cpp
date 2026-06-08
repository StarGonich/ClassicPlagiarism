#include <iostream>
#include <numeric> gcd
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    long long n, k, p, mi;
    mi=99999999999;
    cin >> n >> k;
    for (int i=n+1; i<n+k; i++){
        if (abs(n*i)/gcd(n, i)<mi){
            mi=abs(n*i)/gcd(n, i);
            p=i;
        }
    }
    cout << p;
    return 0;
}
