#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int k;
    int n, m;
    cin>>k;
    cin>>n>>m;
    map <vector<vector<int>>, int> mp_1;
    vector <vector<vector<int>>> per;
    for(int l=1; l<=k; l++){
        int ans=0;
        vector<vector<int>> cur(n+2, vector<int>(m+2, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin >>cur[i][j];
                ans+=cur[i][j];
            }
        }
        per.push_back(cur);
        mp_1[cur]=l;
    }
    vector<int> pos_1={-1, -1, -1,  0, 0,  1, 1, 1};
    vector<int> pos_2={-1,  0,  1, -1, 1, -1, 0, 1};
    for(auto st : per){
        vector<int> ans;
        map <vector<vector<int>>, int> mp = mp_1;
        ans.push_back(mp[st]);
        for(int o=1; o<k; o++){
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
            if(mp[nw]==0){
                break;
            }
            ans.push_back(mp[nw]);
            st = nw;
        }
        if(ans.size() == k){
            for(auto u: ans){
                cout << u << ' ';
            }
            return;
        }
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
