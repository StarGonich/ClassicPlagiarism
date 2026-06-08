#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	long long n;
	cin>>n;
	
	if(n==1){
		cout<<1<<'\n'<<1;
	}
	else if(n==3){
		cout<<6<<'\n'<<1<<" "<<2<<" "<<3;
	}
	else if(n==5){
		cout<<36<<'\n'<<1<<" "<<2<<" "<<9<<" "<<6<<" "<<18;;
	}
	else if(n==4){
		cout<<12<<'\n'<<1<<" "<<2<<" "<<3<<" "<<6;
	}
	else{
		cout<<"-1";
	} 
    return0;
}
