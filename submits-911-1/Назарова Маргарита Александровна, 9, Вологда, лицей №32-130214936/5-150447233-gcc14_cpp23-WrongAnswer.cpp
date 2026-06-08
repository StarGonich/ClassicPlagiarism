#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
using ll =long long;



ll gcd(ll a, ll b){
    if(a>b){
        swap(a, b);
    }
    while(b>1){
        a%=b;
        swap(a, b);
    }
    if(b==1){
        return b;
    }
    return a;
}

ll nok(ll a, ll b){
    return (a*b)/gcd(a, b);
}

int main()
{
    int k, n, m;
    cin >> k >> n >> m;
    int d = 0;
    vector <vector<vector <int>>> a(k, vector<vector<int>>(n, vector <int> (m)));
    for(int l = 0; l < k; l++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[l][i][j];
                if(a[l][i][j]==1){
                    d = l+1;
                }
            }
        }
    }
    if(d==2){
        cout << 1 << " " << 2;
    }
    else{
        cout << 2 << " " << 1;
    }
    return 0;
}
