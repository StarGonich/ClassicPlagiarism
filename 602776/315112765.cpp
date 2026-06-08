#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0;i<n;i++){
        cin>>v[i];
    }
    int l1=-1,r1=-1,l2=-1,r2=n;
    int fl=0;
    for (int i=0;i<n;i++){
        if (fl==1){
            if (v[i]==i+1 || v[i]!=v[i-1]+1){
                r1=i;
                fl=2;
            }
        }
        if (fl==2){
            if (v[i]!=i+1){
                l2=i+1;
                fl=3;
                continue;
            }
        }
        if (fl==3){
            if (v[i]==i+1 || v[i]!=v[i-1]+1){
                    //cout<<v[i]<<endl;
                r2=i;
                break;
            }
        }
        if (fl==0){
            if (v[i]!=i+1){
                l1=i+1;
                fl=1;
            }
        }
    }
    if (l1==-1 || r1==-1 || l2==-1){
        cout<<-1<<endl;
        return 0;
    }
    vector<int> ans;
    vector<int> met(n,1);
    for (int i=0;i<n;i++){
        if (((l1-1)<=i && (r1-1)>=i)){
            met[i]=0;
        }
        if(((l2-1)<=i && (r2-1)>=i)){
            met[i]=-1;
        }
    }
    fl=0;
    for (int i=0;i<n;i++){
        if (met[i]==1){
            ans.push_back(v[i]);
        }
        if (i==l1-1){
            for (int j=l2-1;j<r2;j++){
                ans.push_back(v[j]);
            }
            fl=1;
            continue;
        }
        if (i==l2-1){
            for (int j=l1-1;j<r1;j++){
                ans.push_back(v[j]);
            }
        }
    }
    fl=0;
    for (int i=1;i<n;i++){
        if (ans[i]-ans[i-1]!=1){
            fl=1;
            break;
        }
    }
    if (fl){
        cout<<-1<<endl;
    }
    else{
        cout<<l1<<" "<<r1-l1+1<<endl;
        cout<<l2<<" "<<r2-l2+1<<endl;
    }
}
