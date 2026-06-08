#include <iostream>
#include <vector>


using namespace std;

int main() {
    long long n,t,l,r,l1;
    int fl;
    cin>>n>>t;
    vector <int> b(150000,0);
    vector <int> a(150000,0);
    fl=0;
    l1=3600;
    for (int i=0;i<n;i++){
        if (fl==0){
            cin>>l>>r;
            l=l+3600;
            r=r+3600;
            for (long long j=l1;j<l+1;j++){
                a[j]=a[j-1]-b[j-3600];
            }
            l1=r+1;
            for (long long j=l+1;j<r+1;j++){
                b[j]=1;
                a[j]=a[j-1]-b[j-3600]+b[j];
                if (a[j]>t){
                    fl=1;
                    cout<<j-7200;
                    break;
                }
            }
        }
    }
    if (fl==0){
        cout<<-1;
    }



    return 0;


}
