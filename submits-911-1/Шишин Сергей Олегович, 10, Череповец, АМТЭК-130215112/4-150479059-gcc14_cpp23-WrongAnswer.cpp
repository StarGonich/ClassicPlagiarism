#include <iostream>
#include <vector>


using namespace std;

int main() {
    long long n,k,nok,p,a1,b1,e,z;
    nok=99999999999;
    p=0;
    cin>>n>>k;
    if (k>=n){cout<<2*n;}
    else {
        for (long long i=n+1;i<n+k+1;i++){
            a1=n;
            b1=i;
            while (b1>0){
                e=a1%b1;
                a1=b1;
                b1=e;
            }
            z=n*i/a1;
            cout<<z<<endl;
            if (z<nok){
                nok=z;
                p=i;
            }

        }
        cout<<p;
    }


    return 0;

}
