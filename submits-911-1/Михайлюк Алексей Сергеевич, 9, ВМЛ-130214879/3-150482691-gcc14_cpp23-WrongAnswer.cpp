#include <iostream>
using namespace std;

int main(){
    long long n, t;
    cin >> n;
    cin >> t;
    long long m[n][2];
    for(long long i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        m[i][0] = a;
        m[i][1] = b;
    }
    long long q = m[-1][1];
    long long v[q + 1];
    long long j = 0;
    for(long long i = 0; i < q; i++){
        if (i > m[j][1]){
            j++;
        }
        if (m[j][0] <= i < m[j][1]){
            v[i + 1] = v[i] + 1;
        } else{
            v[i + 1] = v[i];
        }

    }
    long long mi = 9999;
    long long c = -1;
    for(long long i = 0; i < q - 3600; i++){
        if(mi == t + 1){
            break;
        }
        long long z = v[i + 3600] - v[i];
        if (t < z < mi){
            mi = z;
            c = i;
        }

    }
    cout << c << endl;
}
