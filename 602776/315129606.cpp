#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    map<int,int> mp;
    int tek=-1;
    if (v[0]!=1){
        tek=1;
        mp[tek]=1;
    }
    for (int i=0;i<n;i++){
        if (tek!=-1){
            if (v[i]==v[i-1]+1){
                mp[tek]++;
            }
            else{
                tek=-1;
                if (v[i]==i+1){
                    1;
                }
                else{
                    tek=i+1;
                    mp[tek]=1;
                }
            }
        }
        else{
            if (v[i]==i+1){
                1;
            }
            else{
                tek=i+1;
                mp[tek]=1;
            }
        }
    }
    if (mp.size()!=2){
        cout<<-1<<endl;
        return 0;
    }
    for(auto [x,y]:mp){
        cout<<x<<" "<<y<<endl;
    }

    return 0;
}
