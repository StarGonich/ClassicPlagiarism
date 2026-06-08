#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
using ll =long long;




int main()
{
    int k, n, m;
    cin >> k >> n >> m;
    int d = 0;
    vector <pair <ll, ll>> cnt(k, {0, 0});
    vector <vector<vector <int>>> a(k, vector<vector<int>>(n, vector <int> (m)));
    for(int l = 0; l < k; l++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[l][i][j];
                if(d==0 && a[l][i][j]==1){
                    d = l+1;
                }
                cnt[l].first+= a[l][i][j];
                cnt[l].second = l+1;
            }
        }
    }
    if(k==2){
        if(d==2){
            cout << 2 << " " << 1;
        }
        else{
            cout << 1 << " " << 2;
        }
    }
    else{
        sort(cnt.rbegin(), cnt.rend());
        for(auto c:cnt){
            cout << c.second << " ";
        }
    }
    return 0;
}
