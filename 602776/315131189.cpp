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
    if (((a==0) && (c==0))){
        if (b/d!=p/q){
            cout<<"Contradiction"<<endl;
        }
        else{
            cout<<"Ambiguity"<<endl;
        }
        return 0;
    }
    if(((b==0)&& d==0)){
        if (a/c!=p/q){
            cout<<"Contradiction"<<endl;
        }
        else{
            cout<<"Ambiguity"<<endl;
        }
        return 0;
    }
    if (a==0 && d==0){
        cout<<"Success"<<endl;
        cout<<100*q/c<<" "<<100*p/b<<endl;
        return 0;
    }
    if (b==0 && c==0){
        cout<<"Success"<<endl;
        cout<<100*p/a<<" "<<100*q/d<<endl;
        return 0;
    }
    if (a==0 || b==0 || c==0 || d==0){
        double ans1,ans2;
        if (a==0){
            ans2 = 100*p/b;
            ans1 = 100*(q-(p*d/b))/c;
        }
        if (b==0){
            ans1 = 100*p/a;
            ans2 = 100*(q-(p*c/a))/d;
        }
        if (c==0){
            ans2 = 100*q/d;
            ans1 = 100*(p-b*q/d)/a;
        }
        if (d==0){
            ans1 = 100*q/c;
            ans2 = 100*(p-a*q/c)/b;
        }
        if (ans2<0 || ans1<0){
            cout<<"Not positive"<<endl;
        }
        else{
            cout<<"Success"<<endl;
            cout<<ans1<<" "<<ans2<<endl;
        }
        return 0;
    }
    if (a/c==b/d){
        if ((a/c==p/q)){
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
    double ans1=100*x/a,ans2=100*y/b,ans3=100*z/c,ans4=100*w/d;
    //cout<<ans4<<" "<<ans3<<endl;
    else if (ans1<0 || ans2<0){
        cout<<"Not positive"<<endl;
    }
    else{
        cout<<"Success"<<endl;
        cout<<ans1<<" "<<ans2<<endl;
    }
}
