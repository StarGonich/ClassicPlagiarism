#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    long long n, k, sum=1, ms=999999, p, moc;
    cin>>n>>k;
    long long u=n;
    vector<long long> a(1000000);
    for(long long i=2; i<=n; i++){
		if(n%i==0){
			while(n%i==0){
				a[i]++;
				n=n/i;
			}
		}
    }
    for(int y=u+1; y<=u+k; y++){
		sum=1;
		long long h=y;
		vector<long long> t(1000000);
		for(long long i=2; i<=y; i++){
			if(h%i==0){
				while(h%i==0){
					t[i]++;
					h=h/i;
				}
			}
		}
		for(long long i=1; i<=1000000; i++){
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
    cout<<moc+4;
    return 0;
}

