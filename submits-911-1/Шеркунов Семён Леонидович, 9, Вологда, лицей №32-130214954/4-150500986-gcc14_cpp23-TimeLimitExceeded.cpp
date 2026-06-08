#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    long long NOK = 1000000000000000000;
    for (int p = n+1;p<= n+k;p++){
        for(int f =1;f<=n;f++){
            if(p*f %n == 0){
                if(NOK>p*f){
                    NOK = p*f;
                }
            }
        }
        if(NOK > p*n){
            NOK = p*n;
        }
    }
    int p = n+1;
    int minp = n+k;
    while(p <= n+k){
        if(NOK%p==0){
            if(p<minp){
                minp =p;
            }
        }
        p++;
    }
    cout << minp;
    return 0;
}