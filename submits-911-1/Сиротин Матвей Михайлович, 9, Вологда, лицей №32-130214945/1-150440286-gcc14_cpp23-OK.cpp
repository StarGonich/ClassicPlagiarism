#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int h1, m1, h2, m2, sum=0;
    cin>>h1>>m1>>h2>>m2;
    while(h1!=h2||m1!=m2){
		if(m1==60){
			m1=0;
			h1++;
		}
		if(h1==24){
			h1=0;
		}
		if(h1==m1){
			sum++;
		}
		else if(h1==((m1%10)*10+(m1/10))){
			sum++;
		}
		else if(h1==1&&m1==23||h1==12&&m1==34||h1==23&&m1==45){
			sum++;
		}
		m1++;
    }
	if(m1==60){
		m1=0;
		h1++;
	}
	if(h1==24){
		h1=0;
	}
	if(h1==m1){
		sum++;
	}
	else if(h1==((m1%10)*10+(m1/10))){
		sum++;
	}
	else if(h1==1&&m1==23||h1==12&&m1==34||h1==23&&m1==45){
		sum++;
	}
    cout<<sum;
    return 0;
}
