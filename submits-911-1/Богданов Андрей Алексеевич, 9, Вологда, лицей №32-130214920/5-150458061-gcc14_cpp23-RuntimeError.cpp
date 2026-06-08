#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int k;
    int n, m;
    cin>>k;
    cin>>n>>m;
    map <vector<vector<int>>, vector<int>> mp;
    vector <vector<int>> st;
    int total=0;
    for(int l=1; l<=k; l++){
        int ans=0;
        vector<vector<int>> cur(n+2, vector<int>(m+2, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin >>cur[i][j];
                ans+=cur[i][j];
            }
        }
        if(ans>total){
            st=cur;
            total = ans;
        }
        mp[cur].push_back(l);
    }
    vector<int> ans;
    ans.push_back(mp[st].back());
    mp[st].pop_back();
    k--;
    vector<int> pos_1={-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> pos_2={-1, 0, 1, -1, 1, -1, 0, 1};
    while(k--){
        vector<vector<int>> nw;
        nw=st;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int s=0;
                for(int l=0; l<8; l++){
                    s+=st[i+pos_1[l]][j+pos_2[l]];
                }
                if(s==3){
                    nw[i][j]=1;
                }
                else if(s<2){
                    nw[i][j]=0;
                }
                else if (s>3){
                    nw[i][j]=0;
                }
            }
        }
        ans.push_back(mp[nw].back());
        mp[nw].pop_back();
        st = nw;
    }
    for(auto u: ans){
        cout << u << ' ';
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    //cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
