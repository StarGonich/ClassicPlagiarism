#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >>n;
    int t;
    cin >>t;
    int maxr=0;
    vector <bool> a(1e9+1);
    for(int i=0; i<n; i++){
        int l, r;
        cin >>l>>r;
        for(int j=l; j<r; j++){
            a[j]=1;
        }
        maxr=r;
    }
    int  pre=0;
    for(int i=0; i<3600; i++){
        if(a[i]){
            pre+=1;
        }
    }
    if(pre>t){
        cout <<"0";
        return 0;
    }
    for(int i=3600; i<=maxr; i++){
        if(a[i]){
            pre+=1;
        }
        if(a[i-3600]){
            pre-=1;
        }
        if(pre>t){
            cout <<i-3600+1;
            return 0;
        }
    }
    cout <<"-1";
}
