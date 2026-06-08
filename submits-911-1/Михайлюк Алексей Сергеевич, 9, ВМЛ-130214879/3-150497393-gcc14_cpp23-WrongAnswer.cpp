#include <iostream>
using namespace std;

int main(){
    int n, t;
    cin >> n;
    cin >> t;
    int m[n * 2][2];
    for(int i = 0; i < n; i++){
        cin >> m[i][0] >> m[i][1];
    }
    int q = m[n - 1][1];
    int v[q + 1];
    v[0] = 0;
    int j = 0;
    for(int i = 0; i < q; i++){
        if (i > m[j][1]){
            j++;
        }
        if (m[j][0] <= i < m[j][1]){
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
