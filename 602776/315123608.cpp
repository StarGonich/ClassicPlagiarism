#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tek=1;
    int sum=210;
    while(1){
        if (tek==1){
            cout<<8<<" "<<"R"<<endl;
            int ans;
            cin>>ans;
            if (ans==1){
                tek=1;
                sum+=8;
            }
            else{
                tek++;
                sum-=8;
            }
        }
        if (tek==2){
            cout<<24<<" "<<"R"<<endl;
            int ans;
            cin>>ans;
            if (ans==1){
                tek=1;
                sum+=24;
            }
            else{
                tek++;
                sum-=24;
            }
        }
        if (tek==3){
            cout<<56<<" "<<"R"<<endl;
            int ans;
            cin>>ans;
            if (ans==1){
                tek=1;
                sum+=56;
            }
            else{
                tek++;
                sum-=56;
            }
        }
        if (tek==4){
            cout<<sum<<" "<<"R"<<endl;
            int ans;
            cin>>ans;
            if (ans==1){
                tek=1;
                sum+=56;
            }
            else{
                tek++;
                sum-=56;
            }
        }
        if (sum>=1000){
            break;
        }
    }
}
