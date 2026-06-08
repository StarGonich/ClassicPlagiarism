#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int cnt = n/4 + n/5 + n/6;
    int cnt1 = 2*(n/(4*5));
    int cnt2 = 2*(n/(5*6));
    int cnt3 = 2*(n/(12));
    int cnt4 = 2*(n/(2*5*6));
    //cout<<cnt<<endl;
    cout<<cnt-cnt1-cnt2-cnt3+cnt4<<endl;
}
