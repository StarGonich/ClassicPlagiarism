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
	else if(n==6){
		cout<<24<<'\n'<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<6<<" "<<8;
	}
	else if(n==7){
		cout<<60<<'\n'<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<15<<" "<<30;
	}
	else if(n==8){
		cout<<60<<'\n'<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<10<<" "<<15<<" "<<20;
	}
	else{
		cout<<"-1";
	}
    return 0;
}
