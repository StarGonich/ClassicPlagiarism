#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long N, T;
    bool ok = true;
    int lmin;
    cin>>N;
    cin>>T;
    vector <long long> a(1e9, 0);
    for (long long i = 0; i<N; i++){
        long long t1, t2;
        cin>>t1>>t2;
        for (long long j = t1; j<t2; j++){
            a[j] = 1;
        }
    }
    long long l = 0;
    long long r = 3600;
    while (r<10e9){
        int k = 0;
        for (int i = l; i<r; i++){
            if(a[i]==1){
                k+=1;
            }
        }
        if (k > T){
            lmin = l;
            ok = false;
            break;
        }
        l+=1;
        r+=1;
    }
    if (ok){
        cout<<-1;
    }
    else cout<<lmin;
    return 0;

}