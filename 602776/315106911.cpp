#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double a,b,p;
    cin>>a>>b>>p;
    double c,d,q;
    double e=0.0001;
    cin>>c>>d>>q;
    if (abs(a/c - b/d)<e){

        if (abs(a/c-p/q)<e){
            cout<<"Ambiguity"<<endl;
        }
        else{
            cout<<"Contradiction"<<endl;
        }
        return 0;
    }
    double y = (q-c*p/a)/(d/b-c/a);
    double w = y*d/b;
    double x = p-y;
    double z = (c*(p-y))/a;
    double ans1=100*x/a,ans2=100*y/b;
    if (ans1<0 || ans2<0){
        cout<<"Not positive"<<endl;
    }
    else{
        cout<<"Success"<<endl;
        cout<<ans1<<" "<<ans2<<endl;
    }

}
