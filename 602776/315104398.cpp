#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> x(n),d(n);
    for (int i=0;i<n;i++){
        cin>>x[i];
    }
    for (int i=0;i<n;i++){
        cin>>d[i];
    }
    int k;
    cin>>k;
    int uk1=k-2,uk2=k;
    int mn= x[k-1]-d[k-1];
    int mx=x[k-1]+d[k-1];
    int ans=1;
    while (1){
        int fl=0;
        if (uk1>-1){
            if (mn<=x[uk1]){
                fl=1;
                ans++;
                mx=max(mx,x[uk1]+d[uk1]);
                mn=min(mn,x[uk1]-d[uk1]);
                uk1--;
            }
        }
        if (uk2<n){
            if (mx>=x[uk2]){
                fl=1;
                ans++;
                mx=max(mx,x[uk2]+d[uk2]);
                mn=min(mn,x[uk2]-d[uk2]);
                uk2++;
            }
        }
        if (fl==0){
            break;
        }
    }
    cout<<ans<<endl;
}
