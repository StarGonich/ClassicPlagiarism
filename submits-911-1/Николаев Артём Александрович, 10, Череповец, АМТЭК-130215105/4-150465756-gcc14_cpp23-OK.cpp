#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, k, var;
    cin >> n >> k;
    if(k >= n){
        cout << (n << 1);
        return 0;
    }
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            var = (n / i) * (i + 1);
            if(var <= n + k){
                cout << var;
                return 0;
            }
        }
    }
    cout << n + 1;
    return 0;
}
