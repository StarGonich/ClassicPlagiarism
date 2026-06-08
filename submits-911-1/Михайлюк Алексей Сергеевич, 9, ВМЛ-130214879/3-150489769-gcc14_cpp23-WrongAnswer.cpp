#include <iostream>
using namespace std;

int main(){
    int n, t;
    cin >> n;
    cin >> t;
    int m[n * 2];
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        m[i] = a;
        m[i + 1] = b;
    }
    int q = m[n * 2 - 1];
    int v[q + 1];
    int j = 0;
    for(int i = 0; i < q; i++){
        if (i > m[j + 1]){
            j++;
        }
        if (m[j] <= i < m[j + 1]){
            v[i + 1] = v[i] + 1;
        } else{
            v[i + 1] = v[i];
        }

    }
    int mi = 9999;
    int c = -1;
    for(int i = 0; i < q - 3600; i++){
        if(mi == t + 1){
            
            break;
        }
        int z = v[i + 3600] - v[i];
        if (t < z < mi){
            mi = z;
            c = i;
        }
    }
    cout << c;
}
