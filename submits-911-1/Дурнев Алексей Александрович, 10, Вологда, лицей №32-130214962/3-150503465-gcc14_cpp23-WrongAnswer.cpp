#include <iostream>
#include <numeric> gcd
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n, T, t1, t2, c, s;
    vector <int> a(10000000, 0);
    cin >> n >> T;
    for (int i=0; i<n; i++){
        cin >> t1 >> t2;
        if (i==0){
            c=t1;
        }
        for (int z=t1; z<t2; z++){
            a[z]=1;
        }
    }
    for (int i=c; i<t2-3600; i++){
        for (int z=i; z<i+3600; z++){
            s+=a[z];
        }
        if (s>T){
            cout << i;
            return 0;
        }
        else{
            s=0;
        }
    }
    cout << -1;
    return 0;
}
