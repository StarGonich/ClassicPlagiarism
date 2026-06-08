#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> v(n),v1,v2,v3,v4,v5;
    for (int i=0;i<n;i++){
        cin>>v[i];
    }
    int fl=1;
    int l1,r1,l2,r2=n-1;
    for (int i=0;i<n;i++){
        if (fl==1 && v[i]==i+1){
            v1.push_back(v[i]);
        }
        else if (fl==1 && v[i]!=i+1){
            l1=i;
            v2.push_back(v[i]);
            fl=2;
        }
        else if (fl==2 && v[i]==v[i-1]+1){
            v2.push_back(v[i]);
        }
        else if (fl==2 && v[i]!=v[i-1]+1){
            r1=i-1;
            fl=3;
            if (v[i]==i+1){
                v3.push_back(v[i]);
            }
            else{
                l2=i;
                v4.push_back(v[i]);
                fl=4;
            }
        }
        else if (fl==3 && v[i]==i+1){
            v3.push_back(v[i]);
        }
        else if (fl==3 && v[i]!=i+1){
            fl=4;
            l2=i;
            v4.push_back(v[i]);
        }
        else if (fl==4 &&v[i]==v[i-1]+1){
            v4.push_back(v[i]);
        }
        else if (fl==4 &&v[i]!=v[i-1]+1){
            r2=i-1;
            fl=5;
            v5.push_back(v[i]);
        }
        else {
            v5.push_back(v[i]);
        }
    }
    vector<int> ans;
    for (int i:v1)ans.push_back(i);
    for (int i:v4)ans.push_back(i);
    for (int i:v3)ans.push_back(i);
    for (int i:v2)ans.push_back(i);
    for (int i:v5)ans.push_back(i);
    if (fl==1){
        cout<<-1<<endl;
    }
    else{
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
            cout<<l1+1<<" "<<r1-l1+1<<endl;
            cout<<l2+1<<" "<<r2-l2+1<<endl;
        }
    }
}
