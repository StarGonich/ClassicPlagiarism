#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int k, n, m;
    cin >>k>>n>>m;
    bool flag=0;
    for(int i=0; i<k; i++){
        flag=0;
        for(int j=0; j<n; j++){
            for(int d=0; d<m; d++){
                int bit;
                cin >>bit;
                if(bit==1){
                    flag=1;
                }
            }
        }
    }
    if(flag){
        for(int i=k; i>0; i--){
            cout <<i<<" ";
        }
    }
    else{
        for(int i=1; i<=k; i++){
            cout <<i<<" ";
        }
    }
}
