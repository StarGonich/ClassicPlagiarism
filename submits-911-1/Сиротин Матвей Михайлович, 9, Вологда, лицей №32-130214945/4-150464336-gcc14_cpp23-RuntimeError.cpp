#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    long long n, k, sum=0, ms=9999999999999, p, moc;
    cin>>n>>k;
    vector<long long> a(1000000000000);
    for(int i=1; i<=n/2; i++){
		if(n%i==0){
			while(n%i==0){
				a[i]++;
				n/=i;
			}
		}
    }
    for(int y=n+1; y<=n+k; y++){
		vector<long long> t(1000000000000);
		for(int i=1; i<=y/2; i++){
			if(y%i==0){
				while(y%i==0){
					a[i]++;
					y/=i;
				}
			}
		}
		for(int i=1; i<=1000000000000; i++){
			p=max(a[i], t[i]);
			if(p==0){
				continue;
			}
			else{
				sum*=p*i;
			}
		}
		if(sum<ms){
			moc=y;
		}
		ms=min(ms, sum);
    }
    cout<<moc;
    return 0;
}
